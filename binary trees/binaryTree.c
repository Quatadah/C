#include "binaryTree.h"

Tree *initTree(int root)
{
    Tree *tree = malloc(sizeof(*tree));
    if (tree == NULL)
    {
        printf("Error in dynamic allocation.\n");
        exit(EXIT_FAILURE);
    }
    tree->value = root;
    tree->parent = NULL;
    tree->leftTree = NULL;
    tree->rightTree = NULL;
    printf("the tree : %d is created\n",root);
    return tree;
    
}

void deleteTree(Tree *tree)
{
    if (tree == NULL)
        return;
    printf("\n%d is deleted",tree->value);
    deleteTree(tree->rightTree);
    deleteTree(tree->leftTree);
    free(tree);
}

Tree *joinTrees(Tree *left, Tree *right, int root)
{
    Tree *parent = initTree(root);

    if (left == NULL || right == NULL || parent==NULL)
    {
        printf("Error in dynamic allocation.\n");
        exit(EXIT_FAILURE);
    }

    parent->leftTree = left;
    left->parent = parent;
    parent->rightTree = right;
    right->parent = parent;
    
    return parent;
}

void showTreePrefix(Tree *tree)
{
    /*
    if (tree == NULL)
        return;
    
    if (tree->parent != NULL)
        printf("(%d) -> (%d)\n",tree->parent->value,tree->value);
    else
        printf("(%d)\n",tree->value);
    
    if (tree->leftTree != NULL)
        showTreePrefix(tree->leftTree);
    if (tree->rightTree != NULL)
        showTreePrefix(tree->rightTree);
    */
   if (tree != NULL)
        printf(" %d -> ",tree->value);
    if(tree->leftTree != NULL)
    showTreePrefix(tree->leftTree);
    if(tree->rightTree != NULL)
    showTreePrefix(tree->rightTree);  
}

int countTreeNodes(Tree *tree)
{
    
    if(tree == NULL)
        return 0;
    return 1 + countTreeNodes(tree->leftTree) + countTreeNodes(tree->rightTree);
    
}

int exitInTree(Tree *tree,int x)
{
    if(tree == NULL)
        return 0;
    if(tree->value == x)
        return 1;
    return exitInTree(tree->leftTree,x) || exitInTree(tree->rightTree,x);
}

int max(int a,int b)
{
    if (a>b)
        return a;
    else
        return b;
}

int TreeHeight(Tree *tree)
{
    if (tree == NULL)
        return 0;
    if(tree->leftTree != NULL || tree->rightTree !=NULL)
    return 1 + max(TreeHeight(tree->rightTree),TreeHeight(tree->leftTree));
}