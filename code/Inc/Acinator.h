#ifndef ACINATOR_H
#define ACINATOR_H

typedef struct node_t 
{
    char* str;
    struct node_t* l_node;
    struct node_t* r_node;
} node;


//tree func
int add_l_node (node* tree, const char* str);

int add_r_node (node* tree, const char* str);

int rm_node (node* tree);

node* node_ctor (char* str); 

//debug
void grafic_damp (node* tree);

#endif