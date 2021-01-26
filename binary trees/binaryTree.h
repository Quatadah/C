#ifndef _TREE_
#define _TREE_

#include <stdio.h>
#include <stdlib.h>

typedef struct Tree{
    int value;
    struct Tree *leftTree;
    struct Tree *rightTree;
    struct Tree *parent;
}Tree;

Tree *initTree(int root);
void deleteTree(Tree *tree);
Tree *joinTrees(Tree *left, Tree *right, int root);
void showTreePrefix(Tree *tree);
int countTreeNodes(Tree *tree);
int exitInTree(Tree *tree,int x);
int max(int a,int b);
int TreeHeight(Tree *tree);
#endif