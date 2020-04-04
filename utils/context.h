#ifndef _CONTEXT_H_
#define _CONTEXT_H_

#include <stdint.h>
#include <stdbool.h>

// 26 lower + 26 upper case letters, 10 figures, and '_'
#define NB_ELEM_ALPHABET 63

typedef struct _noeud_s
{
    bool idf_existant;
    struct _noeud_s* suite_idf[NB_ELEM_ALPHABET];
    char lettre;
    void* data; // node_t corresponding to the variable decl
} noeud_s;

typedef noeud_s* noeud_t;

typedef struct _context_s
{
    noeud_t root;
} context_s;

typedef context_s* context_t;

context_t create_context();
void free_context(context_t context);
bool context_add_element(context_t context, char* idf, void* data);
void* get_data(context_t context, char* idf);

#endif
