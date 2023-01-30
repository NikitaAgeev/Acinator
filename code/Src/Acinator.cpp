#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include <Acinator.h>


int main()
{
   node* tree = node_ctor("yes");
   add_l_node(tree, "yes2");
   add_r_node(tree, "no");

   grafic_damp(tree);  
}

//tree func
int add_l_node (node* tree, const char* str)
{
    tree->l_node = node_ctor(str);
    return 0;
}

int add_r_node (node* tree, const char* str)
{
    tree->r_node = node_ctor(str);
    return 0;
}

int rm_node (node* tree);

node* node_ctor (char* str)
{
    node* nod = (node*)calloc(1, sizeof(node));
    char* string = (char*)calloc(strlen(str), sizeof(char));
    
    string = strcpy(string, str);

    nod->str = string;
    nod->l_node = nullptr;
    nod->r_node = nullptr;

    return nod;
} 

//graphic debug
static void grafic_node_damp (node* tree, FILE* output_file)
{
    fprintf(output_file, "n%p[label = \"%s\";];\n", tree, tree->str);
    if(tree->l_node != nullptr)
    {
        grafic_node_damp(tree->l_node, output_file);
        fprintf(output_file, "n%p -> n%p [label = \"yes\";];\n", tree, tree->l_node);
    }

    if(tree->r_node != nullptr)
    {
        grafic_node_damp(tree->r_node, output_file);
        fprintf(output_file, "n%p -> n%p [label = \"no\";];\n", tree, tree->r_node);
    }
}

static void print_grafic_damp (node* tree, FILE* output_file)
{
    fprintf(output_file, "digraph {\n");
    //fprintf(output_file, "rankdir=LR;\n");
    fprintf(output_file, "pack=true;\n");

    fprintf(output_file, "splines=ortho;\n");
  
    fprintf(output_file, "node [ shape=record ];\n");

    grafic_node_damp(tree, output_file);

    fprintf(output_file, "}\n");

}

void grafic_damp (node* tree)
{   
    FILE* dump_file = fopen("dump_file.dot", "w");

    print_grafic_damp(tree, dump_file);

    fclose(dump_file);

    system("dot -T png dump_file.dot -o outfile.png\n");
    system("eog outfile.png\n");
    
}