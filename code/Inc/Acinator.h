#ifndef ACINATOR_H
#define ACINATOR_H

typedef struct 
{
    char* str;
    node* l_node;
    node* r_node;
} node;


//tree func
int add_l_node (node* tree, char* str);

int add_r_node (node* tree, char* str);

int rm_node (node* tree);

node* node_ctor (char* str); 

//debug
void graphic_dump (node tree);

#endif