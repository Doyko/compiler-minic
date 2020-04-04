#include "arbre.h"
#include "utils/mips_inst.h"

static int main_is_declared = 0;
static scope* stack = NULL;
static list_node* list_global_decl;
static int stack_offset = 0;
static int data_offset = 0;
static int nb_reg_max = 0;
static int no_reg = 8;

void analyse_tree(node_t n)
{
    if(sflag)
    {
        free_tree(n);
        return;
    }

    creat_scope(stack);
    //print_tree(n);
    analyse_tree_rec(n);

    if(main_is_declared == 0)
    {
        fprintf(stderr, "Error : Missing main function\n");
        exit(1);
    }

    if(vflag)
    {
        free_tree(n);
        delete_scope(stack);
        delete_list_node(list_global_decl);
        return;
    }

    //creation du program assembleur
    create_program();

    second_pass(n);

    create_addiu_inst(29,29, stack_offset);
    create_addiu_inst(2,0,10);
    create_syscall_inst();


    if(ovalue != NULL)
    {
        //printf("ovalue = %s\n", ovalue);
        dump_mips_program(ovalue);
    }
    else
    {
        //printf("ovalue = NULL\n");
        dump_mips_program("out.s");
    }

    free_program();
    free_tree(n);
    delete_scope(stack);
    delete_list_node(list_global_decl);
}

void analyse_tree_rec(node_t n)
{
    if(n == NULL)
        return;

    switch(n->nature)
    {
        case NODE_FUNC:
            if(is_declared(n->opr[1]->ident, stack))
            {
                fprintf(stderr, "Error line %d: Fonction %s is already declared\n", n->lineno, n->opr[1]->ident);
                exit(1);
            }

            if(strcmp(n->opr[1]->ident,"main") == 0)
            {
                main_is_declared = 1;
                if(n->opr[0]->type != TYPE_VOID)
                {
                    fprintf(stderr, "Error line %d: Return value of function main is not void\n", n->lineno);
                    exit(1);
                }
            }
            return analyse_tree_rec(n->opr[2]);

        case NODE_BLOCK:
            //printf(">>>\n");
            creat_scope(stack);
            break;
        case NODE_DECLS:
            analyse_decls(n);
            break;
        case NODE_IDENT:
            {
                node_t res = is_declared(n->ident, stack);
                if(res == NULL)
                {
                    fprintf(stderr, "Error line %d: Variable %s is not declared\n", n->lineno, n->ident);
                    exit(1);
                }

                n->global_decl = res->global_decl;
                n->decl_node = res;
                n->type = res->type;
                n->offset = res->offset;
                break;
            }
        case NODE_STRINGVAL:
            n->offset = data_offset;
            data_offset += str_size(n->str);
            //printf("%s : %d\n", n->str, str_size(n->str));
            list_global_decl = add_node_to_end_list(n, list_global_decl);
            break;
        default:
            break;
    }

    for(int i = 0; i < n->nops; i++)
    {
        analyse_tree_rec(n->opr[i]);
    }

    switch(n->nature)
    {
        case NODE_BLOCK:
            //printf("<<<\n");
            delete_scope(stack);
            break;

        case NODE_AFFECT:
            if(n->opr[0] == NULL || n->opr[1] == NULL)
                break;
            if(n->opr[0]->type == n->opr[1]->type)
                n->type = n->opr[0]->type;
            else
            {
                printf("Error line %d: Affectation of variable '%s' of wrong type\n", n->lineno, n->opr[0]->ident);
                exit(1);
            }
            break;

        case NODE_DECL:
            if(n->opr[0] == NULL || n->opr[1] == NULL)
                break;
            if(n->opr[0]->type == n->opr[1]->type)
                n->type = n->opr[0]->type;
            else
            {
                printf("Error line %d: Initialization of variable '%s' of wrong type\n", n->lineno, n->opr[0]->ident);
                exit(1);
            }

            if(n->opr[0]->global_decl)
            {
                if(n->opr[1]->nature != NODE_INTVAL && n->opr[1]->nature != NODE_BOOLVAL)
                {
                    printf("Error line %d: Initializer is not constant\n", n->lineno);
                    exit(1);
                }
            }

            break;

        case NODE_MUL:
        case NODE_DIV:
        case NODE_PLUS:
        case NODE_MINUS:
        case NODE_MOD:
        case NODE_SRL:
        case NODE_SRA:
        case NODE_SLL:
        case NODE_BAND:
        case NODE_BOR:
        case NODE_BXOR:
            if(n->opr[0]->type == TYPE_INT && n->opr[1]->type == TYPE_INT)
                n->type = TYPE_INT;
            else
            {
                printf("Error line %d: Operands cannot be of TYPE_BOOL\n", n->lineno);
                exit(1);
            }
            break;

        case NODE_LT:
        case NODE_GT:
        case NODE_GE:
        case NODE_LE:
            if(n->opr[0]->type == TYPE_INT && n->opr[1]->type == TYPE_INT)
                n->type = TYPE_BOOL;
            else
            {
                printf("Error line %d: Operands cannot be of TYPE_BOOL\n", n->lineno);
                exit(1);
            }
            break;

        case NODE_AND:
        case NODE_OR:
            if(n->opr[0]->type == TYPE_BOOL && n->opr[1]->type == TYPE_BOOL)
               n->type = TYPE_BOOL;
            else
            {
                printf("Error %d: Operands cannot be of TYPE_INT\n", n->lineno);
                exit(1);
            }
            break;

        case NODE_EQ:
        case NODE_NE:
        if(n->opr[0]->type == n->opr[1]->type)
           n->type = TYPE_BOOL;
        else
        {
            printf("Error %d: Operand have different types\n", n->lineno);
            exit(1);
        }
        break;

        case NODE_UMINUS:
        case NODE_BNOT:
            if(n->opr[0]->type == TYPE_INT)
                n->type = TYPE_INT;
            else
            {
                printf("Error line %d: Operand cannot be of TYPE_BOOL\n", n->lineno);
                exit(1);
            }

            break;

        case NODE_NOT:
            if(n->opr[0]->type == TYPE_BOOL)
                n->type = TYPE_BOOL;
            else
            {
               printf("Error %d: Operand cannot be of TYPE_INT\n", n->lineno);
               exit(1);
            }

            break;

        case NODE_IF:
        case NODE_WHILE:
            if(n->opr[0]->type != TYPE_BOOL)
            {
                printf("Error line %d: Condition is not of TYPE_BOOL\n", n->lineno);
                exit(1);
            }
            break;

        case NODE_DOWHILE:
        case NODE_FOR:
            if(n->opr[1]->type != TYPE_BOOL)
            {
                printf("Error line %d: Condition is not type of TYPE_BOOL\n", n->lineno);
                exit(1);
            }
        break;

        default:
            break;
    }
}

void free_tree(node_t n)
{
    int i;

    for(i = 0; i < n->nops; i++)
    {
        if(n->opr[i] != NULL)
            free_tree(n->opr[i]);
    }
    free(n->opr);

    if(n->nature == NODE_IDENT)
        free(n->ident);
    else if(n->nature == NODE_STRINGVAL)
        free(n->str);

    free(n);
}

void analyse_decls(node_t n)
{
    if(n->opr[0]->type == TYPE_VOID)
    {
        fprintf(stderr, "Error line %d: Variable cannot be TYPE_VOID\n", n->lineno);
        exit(1);
    }

    n->type = n->opr[0]->type;
    analyse_decls_rec(n->opr[1], n->type);
}

void analyse_decls_rec(node_t n, node_type type)
{
    if(n->nature == NODE_DECL)
    {
        node_t n_ident = n->opr[0];
        if(is_declared_in_scope(n_ident->ident, stack) != NULL)
        {
            fprintf(stderr, "Error line %d: Variable %s is already declared\n", n->lineno, n_ident->ident);
            exit(1);
        }
        //printf("add_node_to_list : %s\n", n_ident->ident);
        stack->nodes = add_node_to_list(n_ident, stack->nodes);

        if(stack->prec == NULL)
        {
            n_ident->global_decl = true;
            n_ident->offset = data_offset;
            data_offset += 4;
        }
        else
        {
            n_ident->global_decl = false;
            n_ident->offset = stack_offset;
            stack_offset += 4;
        }
        //printf("offset = %d\n", n_ident->offset);

        n_ident->decl_node = n;
        n_ident->type = type;
    }

    for(int i = 0; i < n->nops; i++)
    {
        if(n->opr[i] != NULL)
            analyse_decls_rec(n->opr[i], type);
    }
}

node_t is_declared(char* ident, scope* s)
{
    node_t res = is_declared_in_scope(ident, s);
    if(res == NULL)
    {
        if(s->prec != NULL)
            return is_declared(ident, s->prec);
        else
            return NULL;
    }
    return res;
}

node_t is_declared_in_scope(char* ident, scope* s)
{
    list_node* ln = s->nodes;
    while(ln != NULL)
    {
        if(ident == NULL)
            printf("null !\n");
        //printf("is_declared : %s\n", ln->node->ident);
        if(strcmp(ln->node->ident, ident) == 0)
            return ln->node;
        ln = ln->next;
    }

    return NULL;
}

int str_size(char* s)
{
    int i = 0, cmpt = 0;
    char c = s[i];

    while(c != 0)
    {
        if(!(c == 34 || c == 92))
        {
            cmpt++;
        }
        i++;
        c = s[i];
    }
    return cmpt+1;
}

list_node* add_node_to_list(node_t n, list_node* ln)
{
    list_node* new = (list_node*)malloc(sizeof(list_node));
    new->node = n;
    new->next = ln;
    return new;
}

list_node* add_node_to_end_list(node_t n, list_node* ln)
{
    list_node* tmp = ln;
    list_node* new = (list_node*)malloc(sizeof(list_node));

    new->node = n;
    new->next = NULL;

    if(tmp == NULL)
        return new;

    while(tmp->next != NULL)
        tmp = tmp->next;

    tmp->next = new;
    return ln;
}

scope* creat_scope(scope* prec)
{
    scope* ns = (scope*)malloc(sizeof(scope));
    ns->prec = prec;
    ns->nodes = NULL;
    stack = ns;
    return ns;
}

void delete_list_node(list_node* ln)
{
    if(ln != NULL && ln->next != NULL)
        delete_list_node(ln->next);
    free(ln);
    return;
}

void delete_scope(scope* s)
{
    stack = s->prec;
    if(s->nodes != NULL)
        delete_list_node(s->nodes);
    free(s);
}

void second_pass(node_t n)
{
    static int nb_label = 1;

    switch(n->nature)
    {
        case NODE_PROGRAM:
            create_data_sec_inst();
            if(n->opr[0] != NULL)
                second_pass(n->opr[0]);

            list_node* global_str = list_global_decl;
            while (global_str != NULL)
            {
                create_asciiz_inst(NULL, global_str->node->str);
                global_str = global_str->next;
            }

            create_text_sec_inst();
            second_pass(n->opr[1]);

            break;

        case NODE_FUNC:
        {
            create_label_str_inst(n->opr[1]->ident);
            create_addiu_inst(29,29, -stack_offset);
            second_pass(n->opr[2]);

            break;
        }
        // case NODE_BLOCK:
        //     break;
        // case NODE_LIST:
        //     break;
        // case NODE_DECLS:
        //     break;

        case NODE_DECL:
            if(n->opr[0]->global_decl)
            {
                if(n->opr[1] != NULL)
                    create_word_inst(n->opr[0]->ident, n->opr[1]->value);
                else
                    create_word_inst(n->opr[0]->ident, 0);

                break;
            }

            if(n->opr[1] == NULL)
                break;

            if(n->opr[1]->nature == NODE_IDENT)
            {
                int a = load_register(n->opr[1]);
                no_reg -= 1;
                create_sw_inst(a, n->opr[0]->offset, 29);
            }
            else if(n->opr[1]->nature == NODE_INTVAL)
            {
                int a = load_register(n->opr[1]);
                no_reg -= 1;
                create_sw_inst(a, n->opr[0]->offset, 29);
            }
            else
            {
                int a = load_register(n->opr[1]);
                no_reg -= 1;
                create_sw_inst(a, n->opr[0]->offset, 29);
            }
            break;

        // case NODE_IDENT:
        //     break;
        //
        // case NODE_TYPE:
        //     break;
        //
        // case NODE_INTVAL:
        //     break;
        //
        // case NODE_BOOLVAL:
        //     break;

        case NODE_IF:
        {
            int else_label = nb_label;
            nb_label += 1;
            int a = load_register(n->opr[0]);
            no_reg -= 1;
            create_beq_inst(a,0,else_label);
            second_pass(n->opr[1]);

            if(n->nops == 3)
            {
                int end_label = nb_label;
                nb_label += 1;
                create_j_inst(end_label);
                create_label_inst(else_label);
                second_pass(n->opr[2]);
                create_label_inst(end_label);
            }
            else
                create_label_inst(else_label);


            break;
        }

        case NODE_WHILE:
        {
            int start_label = nb_label, end_label = nb_label + 1;
            nb_label += 2;
            create_label_inst(start_label);
            int a = load_register(n->opr[0]);
            no_reg -= 1;
            create_beq_inst(a, 0, end_label);
            second_pass(n->opr[1]);
            create_j_inst(start_label);
            create_label_inst(end_label);

            break;
        }

        case NODE_FOR:
        {
            int start_label = nb_label, end_label = nb_label + 1;
            nb_label += 2;
            second_pass(n->opr[0]);
            create_label_inst(start_label);

            int a = load_register(n->opr[1]);
            no_reg -= 1;
            create_beq_inst(a, 0, end_label);
            second_pass(n->opr[3]);
            second_pass(n->opr[2]);
            create_j_inst(start_label);
            create_label_inst(end_label);

            break;
        }

        case NODE_DOWHILE:
        {
            int start_label = nb_label, end_label = nb_label + 1;
            nb_label += 2;
            create_label_inst(start_label);
            second_pass(n->opr[0]);
            int a = load_register(n->opr[1]);
            no_reg -= 1;
            create_xori_inst(a,a,1);
            create_beq_inst(a, 0, start_label);
            create_label_inst(end_label);

            break;
        }

        case NODE_PLUS:
        {
            int a = load_register(n->opr[0]);
            int b = load_register(n->opr[1]);
            no_reg -= 2;
            create_addu_inst(no_reg, a, b);

            break;
        }

        case NODE_MINUS:
        {
            int a = load_register(n->opr[0]);
            int b = load_register(n->opr[1]);
            no_reg -= 2;
            create_subu_inst(no_reg, a, b);

            break;
        }

        case NODE_MUL:
        {
            int a = load_register(n->opr[0]);
            int b = load_register(n->opr[1]);
            create_mult_inst(a, b);
            no_reg -= 2;
            create_mflo_inst(no_reg);

            break;
        }

        case NODE_DIV:
        {
            int a = load_register(n->opr[0]);
            int b = load_register(n->opr[1]);
            create_div_inst(a, b);
            no_reg -= 2;
            create_mflo_inst(no_reg);

            break;
        }

        case NODE_MOD:
        {
            int a = load_register(n->opr[0]);
            int b = load_register(n->opr[1]);
            create_div_inst(a, b);
            no_reg -= 2;
            create_mfhi_inst(no_reg);

            break;
        }

        case NODE_LT:
        {
            int a = load_register(n->opr[0]);
            int b = load_register(n->opr[1]);
            no_reg -= 2;
            create_slt_inst(no_reg, a, b);

            break;
        }

        case NODE_GT:
        {
            int a = load_register(n->opr[0]);
            int b = load_register(n->opr[1]);
            no_reg -= 2;
            create_slt_inst(no_reg, b, a);

            break;
        }

        case NODE_LE:
        {
            int a = load_register(n->opr[0]);
            int b = load_register(n->opr[1]);
            create_slt_inst(a,b,a);
            no_reg -= 2;
            create_xori_inst(no_reg,a,1);

            break;
        }

        case NODE_GE:
        {
            int a = load_register(n->opr[0]);
            int b = load_register(n->opr[1]);
            create_slt_inst(a,a,b);
            no_reg -= 2;
            create_xori_inst(no_reg,a,1);

            break;
        }

        case NODE_EQ:
        {
            int a = load_register(n->opr[0]);
            int b = load_register(n->opr[1]);
            int c = load_register(NULL);
            create_slt_inst(c,a,b);
            create_slt_inst(a,b,a);
            create_or_inst(a,c,a);
            no_reg -= 3;
            create_xori_inst(no_reg,a,1);

            break;
        }

        case NODE_NE:
        {
            int a = load_register(n->opr[0]);
            int b = load_register(n->opr[1]);
            int c = load_register(NULL);
            create_slt_inst(c,a,b);
            create_slt_inst(a,b,a);
            no_reg -= 3;
            create_or_inst(no_reg,c,a);

            break;
        }

        case NODE_AND:
        {
            int a = load_register(n->opr[0]);
            int b = load_register(n->opr[1]);
            no_reg -= 2;
            create_and_inst(no_reg,a,b);

            break;
        }

        case NODE_OR:
        {
            int a = load_register(n->opr[0]);
            int b = load_register(n->opr[1]);
            no_reg -= 2;
            create_or_inst(no_reg,a,b);

            break;
        }

        case NODE_BAND:
        {
            int a = load_register(n->opr[0]);
            int b = load_register(n->opr[1]);
            no_reg -= 2;
            create_and_inst(no_reg,a,b);

            break;
        }

        case NODE_BOR:
        {
            int a = load_register(n->opr[0]);
            int b = load_register(n->opr[1]);
            no_reg -= 2;
            create_or_inst(no_reg,a,b);

            break;
        }

        case NODE_BXOR:
        {
            int a = load_register(n->opr[0]);
            int b = load_register(n->opr[1]);
            no_reg -= 2;
            create_xor_inst(no_reg,a,b);

            break;
        }

        case NODE_NOT:
        {
            int a = load_register(n->opr[0]);
            no_reg -= 1;
            create_xori_inst(no_reg,a,1);

            break;
        }

        case NODE_BNOT:
        {
            int a = load_register(n->opr[0]);
            no_reg -= 1;
            create_nor_inst(no_reg,a,0);

            break;
        }

        case NODE_SLL:
        {
            int a = load_register(n->opr[0]);
            int b = load_register(n->opr[1]);
            no_reg -= 2;
            create_sllv_inst(no_reg,a,b);

            break;
        }

        case NODE_SRA:
        {
            int a = load_register(n->opr[0]);
            int b = load_register(n->opr[1]);
            no_reg -= 2;
            create_srav_inst(no_reg,a,b);

            break;
        }

        case NODE_SRL:
        {
            int a = load_register(n->opr[0]);
            int b = load_register(n->opr[1]);
            no_reg -= 2;
            create_srlv_inst(no_reg,a,b);


            break;
        }

        case NODE_UMINUS:
        {
            int a = load_register(n->opr[0]);
            no_reg -= 1;
            create_subu_inst(no_reg,0,a);

            break;
        }

        case NODE_AFFECT:
        {
            int a = load_register(n->opr[1]);
            no_reg -= 1;
            create_sw_inst(a, n->opr[0]->offset, 29);
            break;
        }

        case NODE_PRINT:
            create_print_inst(n);
            break;

        default:
            for(int i = 0; i < n->nops; i++)
                if(n->opr[i] != NULL)
                    second_pass(n->opr[i]);
            break;
    }
}

int load_register(node_t n)
{
    if(n == NULL)
    {
        no_reg++;
        return no_reg-1;
    }

    if(n->nature == NODE_IDENT)
    {
        if(n->global_decl)
        {
            create_lui_inst(no_reg,0x1001);
            create_lw_inst(no_reg, n->offset, no_reg);
        }
        else
            create_lw_inst(no_reg, n->offset, 29);
    }
    else if(n->nature == NODE_INTVAL)
    {
        create_ori_inst(no_reg, 0, n->value);
    }
    else
    {
        second_pass(n);
        //if(r_dest != no_reg)
          //create_or_inst(r_dest, no_reg, 0);
    }

    no_reg++;
    return no_reg-1;
}

void create_print_inst(node_t n)
{
    if(n->nature == NODE_IDENT)
    {
        if(n->global_decl)
        {
            create_lui_inst(4,0x1001);
            create_lw_inst(4, n->offset, 4);
        }
        else
            create_lw_inst(4, n->offset, 29);

        create_addiu_inst(2,0,1);
        create_syscall_inst();
    }
    else if(n->nature == NODE_STRINGVAL)
    {
        create_lui_inst(4, 0x1001);
        create_addiu_inst(4,4,n->offset);
        create_ori_inst(2,0,4);
        create_syscall_inst();
    }
    else
    {
        for(int i = 0; i < n->nops; i++)
        {
          create_print_inst(n->opr[i]);
        }
    }
}


//############################ Affichage #################################

void print_tree(node_t n)
{
    int32_t deeth = get_max_deeth(n, 1);
    int32_t nbLines = get_nb_lines(n);

    int** tab = (int**)malloc(nbLines * sizeof(int*));
    if(tab == NULL)
    {
        printf("Erreur d'allocation !\n");
        exit(1);
    }

    for(int i = 0; i < nbLines; i++)
    {
        tab[i] = (int*)malloc(deeth * sizeof(int));
        if(tab[i] == NULL)
        {
            printf("Erreur d'allocation !\n");
            exit(1);
        }

        for(int j = 0; j < deeth; j++)
        {
            tab[i][j] = -3;
        }
    }

    int lign = 0;
    build_tab(tab, n, 0, &lign);

    for(int i = 0; i < nbLines; i++)
    {
        for(int j = 0; j < deeth; j++)
        {
            if(tab[i][j] >= 0)
            {
                if(j + 1 == deeth)
                    continue;

                for(int k = i + 1; k < nbLines; k++)
                {
                    if(tab[k][j] >= 0)
                        break;

                    if(tab[k][j + 1] >= 0)
                    {
                        tab[k][j] = -2;
                        for(int l = k - 1; l > i; l--)
                        {
                            if(tab[l][j] != -2)
                                tab[l][j] = -1;
                        }
                    }
                }
            }
        }
    }

    for(int i = 0; i < nbLines; i++)
    {
        for(int j = 0; j < deeth; j++)
        {
            switch(tab[i][j])
            {
                case -3:
                    printf("\x1b[36m                \x1b[0m");
                    break;
                case -2:
                    printf("\x1b[36m    +-------->  \x1b[0m");
                    break;
                case -1:
                    printf("\x1b[36m    |           \x1b[0m");
                    break;
                default:
                    printf("\x1b[33m%s\t\x1b[0m", node_to_str(tab[i][j]));
                    break;
            }
        }
        printf("\n");
    }
}

int32_t get_max_deeth(node_t n, int32_t deep)
{
    if(n == NULL)
        return 0;

    if(n->nops == 0)
        return deep;

    int32_t max = deep;
    int32_t tmp;
    for(int i = 0; i < n->nops; i++)
    {
        tmp = get_max_deeth(n->opr[i], deep + 1);
        if(tmp > max)
            max = tmp;
    }

    return max;
}

int32_t get_nb_lines(node_t n)
{
    if(n == NULL || n->nops == 0)
        return 1;

    int32_t nb = 0;
    for(int i = 0; i < n->nops; i++)
    {
        nb += get_nb_lines(n->opr[i]);
    }

    return nb;
}

void build_tab(int** tab, node_t n, int deep, int* lign)
{
    if(n == NULL)
    {
        *lign += 1;
        return;
    }

    tab[*lign][deep] = n->nature;

    for(int i = 0; i < n->nops; i++)
    {
        build_tab(tab, n->opr[i], deep + 1, lign);
    }
    if(n->nops == 0)
        *lign += 1;
}

char* node_to_str(node_nature n)
{
    switch(n)
    {
        case NODE_PROGRAM:
            return("NODE_PROGRAM");
            break;
        case NODE_BLOCK:
            return("NODE_BLOCK");
            break;
        case NODE_LIST:
            return("NODE_LIST");
            break;
        case NODE_DECLS:
            return("NODE_DECLS");
            break;
        case NODE_DECL:
            return("NODE_DECL");
            break;
        case NODE_IDENT:
            return("NODE_IDENT");
            break;
        case NODE_TYPE:
            return("NODE_TYPE");
            break;
        case NODE_INTVAL:
            return("NODE_INTVAL");
            break;
        case NODE_BOOLVAL:
            return("NODE_BOOLVAL");
            break;
        case NODE_STRINGVAL:
            return("NODE_STRINGVAL");
            break;
        case NODE_FUNC:
            return("NODE_FUNC");
            break;
        case NODE_IF:
            return("NODE_IF\t");
            break;
        case NODE_WHILE:
            return("NODE_WHILE");
            break;
        case NODE_FOR:
            return("NODE_FOR");
            break;
        case NODE_DOWHILE:
            return("NODE_DOWHILE");
            break;
        case NODE_PLUS:
            return("NODE_PLUS");
            break;
        case NODE_MINUS:
            return("NODE_MINUS");
            break;
        case NODE_MUL:
            return("NODE_MUL");
            break;
        case NODE_DIV:
            return("NODE_DIV");
            break;
        case NODE_MOD:
            return("NODE_MOD");
            break;
        case NODE_LT:
            return("NODE_LT\t");
            break;
        case NODE_GT:
            return("NODE_GT\t");
            break;
        case NODE_LE:
            return("NODE_LE\t");
            break;
        case NODE_GE:
            return("NODE_GE\t");
            break;
        case NODE_EQ:
            return("NODE_EQ\t");
            break;
        case NODE_NE:
            return("NODE_NE\t");
            break;
        case NODE_AND:
            return("NODE_AND");
            break;
        case NODE_OR:
            return("NODE_OR\t");
            break;
        case NODE_BAND:
            return("NODE_BAND");
            break;
        case NODE_BOR:
            return("NODE_BOR");
            break;
        case NODE_BXOR:
            return("NODE_BXOR");
            break;
        case NODE_NOT:
            return("NODE_NOT");
            break;
        case NODE_BNOT:
            return("NODE_BNOT");
            break;
        case NODE_SLL:
            return("NODE_SLL");
            break;
        case NODE_SRA:
            return("NODE_SRA");
            break;
        case NODE_SRL:
            return("NODE_SRL");
            break;
        case NODE_UMINUS:
            return("NODE_UMINUS");
            break;
        case NODE_AFFECT:
            return("NODE_AFFECT");
            break;
        case NODE_PRINT:
            return("NODE_PRINT");
            break;
    }
}
