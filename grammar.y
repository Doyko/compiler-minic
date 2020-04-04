%{
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <stdbool.h>
#include <stdarg.h>
#include <string.h>
#include <assert.h>

#include "defs.h"
#include "common.h"
#include "arbre.h"

/* Global variables */
static int nb_node = 0;
// à compléter

/* prototypes */
node_t make_node(node_nature nature, int nb_arg, ...);
node_t make_final_node(node_nature nature, int nb_arg, ...);
int yylex(void);
extern int yylineno;

void yyerror(char *s);

// à compléter

%}

%union {
    int32_t intval;
    char* strval;
    node_t ptr;
};

/* à compléter : définition des tokens et de leur associativité */
%token TOK_VOID
%token TOK_INT
%token TOK_INTVAL
%token TOK_BOOL
%token TOK_TRUE
%token TOK_FALSE
%token TOK_IDENT
%token TOK_IF
%token TOK_ELSE
%token TOK_WHILE
%token TOK_FOR
%token TOK_PRINT
%token TOK_AFFECT
%token TOK_GE
%token TOK_LE
%token TOK_GT
%token TOK_LT
%token TOK_EQ
%token TOK_NE
%token TOK_PLUS
%token TOK_MINUS
%token TOK_MUL
%token TOK_DIV
%token TOK_MOD
%token TOK_UMINUS
%token TOK_SEMICOL
%token TOK_COMMA
%token TOK_LPAR
%token TOK_RPAR
%token TOK_LACC
%token TOK_RACC
%token TOK_STRING
%token TOK_DO

%nonassoc TOK_THEN
%nonassoc TOK_ELSE

%right TOK_AFFECT

%left TOK_OR
%left TOK_AND
%left TOK_BOR
%left TOK_BXOR
%left TOK_BAND
%left TOK_EQ
%left TOK_NE
%left TOK_GT
%left TOK_LT
%left TOK_GE
%left TOK_LE
%left TOK_SRL
%left TOK_SRA
%left TOK_SLL
%left TOK_PLUS
%left TOK_MINUS
%left TOK_MUL
%left TOK_DIV
%left TOK_MOD
%left TOK_UMINUS
%left TOK_NOT
%left TOK_BNOT

%type <intval> TOK_INTVAL;
%type <strval> TOK_IDENT;
%type <strval> TOK_STRING;

%type <ptr> program
%type <ptr> listdecl
%type <ptr> listdeclnonnull
%type <ptr> vardecl
%type <ptr> ident
%type <ptr> type
%type <ptr> listtypedecl
%type <ptr> decl
%type <ptr> maindecl
%type <ptr> listinst
%type <ptr> listinstnonnull
%type <ptr> inst
%type <ptr> block
%type <ptr> expr
%type <ptr> listparamprint
%type <ptr> paramprint

%%

/* à compléter : grammaire hors-contexte et construction de l'arbre */

program 		: listdeclnonnull maindecl
        		{
            		$$ = make_node(NODE_PROGRAM, 2, $1, $2);
            		analyse_tree($$);
        		}
        		| maindecl
        		{
            		$$ = make_node(NODE_PROGRAM, 2, NULL, $1);
            		analyse_tree($$);
        		}
        		;

listdecl		: listdeclnonnull
                {
                    $$ = $1;
                }
				|
                {
                    $$ = NULL;
                }
				;

listdeclnonnull	: vardecl
                {
                    $$ = $1;
                }
				| listdeclnonnull vardecl
                {
                    $$ = make_node(NODE_LIST, 2, $1, $2);
                }
				;

vardecl			: type listtypedecl TOK_SEMICOL
                {
                    $$ = make_node(NODE_DECLS, 2, $1, $2);
                }
				;

type			: TOK_INT
                {
                    $$ = make_final_node(NODE_TYPE, 1, TYPE_INT);
                }
				| TOK_BOOL
                {
                    $$ = make_final_node(NODE_TYPE, 1, TYPE_BOOL);
                }
				| TOK_VOID
                {
                    $$ = make_final_node(NODE_TYPE, 1, TYPE_VOID);
                }
				;

listtypedecl	: decl
                {
                    $$ = $1;
                }
                | listtypedecl TOK_COMMA decl
                {
                    $$ = make_node(NODE_LIST, 2, $1, $3);
                }
				;

decl			: ident
                {
                    $$ = make_node(NODE_DECL, 2, $1, NULL);;
                }
				| ident TOK_AFFECT expr
                {
                    $$ = make_node(NODE_DECL, 2, $1, $3);
                }
				;

maindecl		: type ident TOK_LPAR TOK_RPAR block
                {
                    $$ = make_node(NODE_FUNC, 3, $1, $2, $5);
                }
				;

listinst		: listinstnonnull
                {
                    $$ = $1;
                }
                |
                {
                    $$ = NULL;
                }
				;

listinstnonnull	: inst
                {
                    $$ = $1;
                }
				| listinstnonnull inst
                {
                    $$ = make_node(NODE_LIST, 2, $1, $2);
                }
				;

inst			: expr TOK_SEMICOL
                {
                    $$ = $1;
                }
				| TOK_IF TOK_LPAR expr TOK_RPAR inst TOK_ELSE inst
                {
                    $$ = make_node(NODE_IF, 3, $3, $5, $7);
                }
				| TOK_IF TOK_LPAR expr TOK_RPAR inst %prec TOK_THEN
                {
                    $$ = make_node(NODE_IF, 2, $3, $5);
                }
				| TOK_WHILE TOK_LPAR expr TOK_RPAR inst
                {
                    $$ = make_node(NODE_WHILE, 2, $3, $5);
                }
				| TOK_FOR TOK_LPAR expr TOK_SEMICOL expr TOK_SEMICOL expr TOK_RPAR inst
                {
                    $$ = make_node(NODE_FOR, 4, $3, $5, $7, $9);
                }
				| TOK_DO inst TOK_WHILE TOK_LPAR expr TOK_RPAR TOK_SEMICOL
                {
                    $$ = make_node(NODE_DOWHILE, 2, $2, $5);
                }
				| block
                {
                    $$ = $1;
                }
				| TOK_SEMICOL
                {
                    $$ = NULL;
                }
				| TOK_PRINT TOK_LPAR listparamprint TOK_RPAR TOK_SEMICOL
                {
                    $$ = make_node(NODE_PRINT, 1, $3);
                }
				;

block 			: TOK_LACC listdecl listinst TOK_RACC
                {
                    $$ = make_node(NODE_BLOCK, 2, $2, $3);
                }
				;

expr			: expr TOK_MUL expr
                {
                    $$ = make_node(NODE_MUL, 2, $1, $3);
                }
				| expr TOK_DIV expr
                {
                    $$ = make_node(NODE_DIV, 2, $1, $3);
                }
				| expr TOK_PLUS expr
                {
                    $$ = make_node(NODE_PLUS, 2, $1, $3);
                }
				| expr TOK_MINUS expr
                {
                    $$ = make_node(NODE_MINUS, 2, $1, $3);
                }
				| expr TOK_MOD expr
                {
                    $$ = make_node(NODE_MOD, 2, $1, $3);
                }
				| expr TOK_LT expr
                {
                    $$ = make_node(NODE_LT, 2, $1, $3);
                }
				| expr TOK_GT expr
                {
                    $$ = make_node(NODE_GT, 2, $1, $3);
                }
				| TOK_MINUS expr %prec TOK_UMINUS
                {
                    $$ = make_node(NODE_UMINUS, 1, $2);
                }
				| expr TOK_GE expr
                {
                    $$ = make_node(NODE_GE, 2, $1, $3);
                }
				| expr TOK_LE expr
                {
                    $$ = make_node(NODE_LE, 2, $1, $3);
                }
				| expr TOK_EQ expr
                {
                    $$ = make_node(NODE_EQ, 2, $1, $3);
                }
				| expr TOK_NE expr
                {
                    $$ = make_node(NODE_NE, 2, $1, $3);
                }
				| expr TOK_AND expr
                {
                    $$ = make_node(NODE_AND, 2, $1, $3);
                }
				| expr TOK_OR expr
                {
                    $$ = make_node(NODE_OR, 2 , $1, $3);
                }
				| expr TOK_BAND expr
                {
                    $$ = make_node(NODE_BAND, 2, $1, $3);
                }
				| expr TOK_BOR expr
                {
                    $$ = make_node(NODE_BOR, 2, $1, $3);
                }
				| expr TOK_BXOR expr
                {
                    $$ = make_node(NODE_BXOR, 2, $1, $3);
                }
				| expr TOK_SRL expr
                {
                    $$ = make_node(NODE_SRL, 2, $1, $3);
                }
				| expr TOK_SRA expr
                {
                    $$ = make_node(NODE_SRA, 2, $1, $3);
                }
				| expr TOK_SLL expr
                {
                    $$ = make_node(NODE_SLL, 2, $1, $3);
                }
				| TOK_NOT expr
                {
                    $$ = make_node(NODE_NOT, 1, $2);
                }
				| TOK_BNOT expr
                {
                    $$ = make_node(NODE_BNOT, 1, $2);
                }
				| TOK_LPAR expr TOK_RPAR
                {
                    $$ = $2;
                }
				| ident TOK_AFFECT expr
                {
                    $$ = make_node(NODE_AFFECT, 2, $1, $3);
                }
				| TOK_INTVAL
                {
                    $$ = make_final_node(NODE_INTVAL, 1, $1);
                }
				| TOK_TRUE
                {
                    $$ = make_final_node(NODE_BOOLVAL, 1, 1);
                }
				| TOK_FALSE
                {
                    $$ = make_final_node(NODE_BOOLVAL, 1, 0);
                }
				| ident
                {
                    $$ = $1;
                }
                ;

listparamprint	: listparamprint TOK_COMMA paramprint
                {
                    $$ = make_node(NODE_LIST, 2, $1, $3);
                }
				| paramprint
                {
                    $$ = $1;
                }
				;

paramprint		: ident
                {
                    $$ = $1;
                }
				| TOK_STRING
                {
                    $$ = make_final_node(NODE_STRINGVAL, 1, $1);
                }
				;

ident 			: TOK_IDENT
                {
                    $$ = make_final_node(NODE_IDENT, 1, $1);
                }
				;

%%

/* à compléter : fonctions de création des noeuds de l'arbre */

node_t make_node(node_nature nature, int nb_arg, ...)
{
    node_t nn = (node_t)malloc(sizeof(node_s));
    if(nn == NULL)
    {
        printf("Allocation error!\n");
        exit(1);
    }

    nn->lineno = yylineno;
    nn->node_num = nb_node;
    nb_node++;

    nn->nature = nature;
    nn->nops = nb_arg;
    nn->opr = (node_t*)malloc(sizeof(node_t) * nb_arg);
    if(nn->opr == NULL)
    {
        printf("Allocation error!\n");
        exit(1);
    }

    va_list va;
    va_start(va, nb_arg);

    for(int i = 0; i < nb_arg; i++)
    {
        nn->opr[i] = va_arg(va, node_t);
    }

    va_end(va);


    return nn;
}

node_t make_final_node(node_nature nature, int nb_arg, ...)
{
    node_t nn = (node_t)malloc(sizeof(node_s));
    if(nn == NULL)
    {
        printf("Allocation error!\n");
        exit(1);
    }

    nn->lineno = yylineno;
    nn->node_num = nb_node;
    nb_node++;

    nn->nature = nature;
    nn->nops = 0;
    nn->opr = NULL;

    va_list va;
    va_start(va, nb_arg);

    switch(nn->nature)
    {
        case NODE_IDENT:
            nn->ident = va_arg(va, char*);
            break;

        case NODE_TYPE:
            nn->type = va_arg(va, int);
            break;

        case NODE_INTVAL:
            nn->type = TYPE_INT;
            nn->value = va_arg(va, int64_t);
            break;

        case NODE_BOOLVAL:
            nn->type = TYPE_BOOL;
            nn->value = va_arg(va, int64_t);
            break;

        case NODE_STRINGVAL:
            nn->type = TYPE_STRING;
            nn->str = va_arg(va, char*);
            break;

        default :
            break;
    }

    va_end(va);

    return nn;
}

void yyerror(char* s)
{
    fprintf(stderr, "Grammar Error line %d: %s\n", yylineno, s);
    exit(1);
}
