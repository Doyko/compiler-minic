#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <stdbool.h>
#include <stdarg.h>
#include <string.h>
#include <assert.h>

#include "defs.h"
#include "common.h"

void analyse_tree(node_t n);
void analyse_tree_rec(node_t n);
void analyse_decls(node_t n);
void analyse_decls_rec(node_t n, node_type type);
void free_tree(node_t n);

node_t is_declared(char* ident, scope* s);
node_t is_declared_in_scope(char* ident, scope* s);

int str_size(char* s);

list_node* add_node_to_list(node_t n, list_node* ln);
list_node* add_node_to_end_list(node_t n, list_node* ln);
void delete_list_node(list_node* ln);

scope* creat_scope(scope* prec);
void delete_scope(scope* s);

void second_pass(node_t n);
int load_register(node_t n);
void create_print_inst(node_t n);

//print_tree
void print_tree(node_t n);
void build_tab(int** tab, node_t n, int deep, int* lign);
int32_t get_max_deeth(node_t n, int32_t deep);
int32_t get_nb_lines(node_t n);
char* node_to_str(node_nature n);
