#include "binaryTree.h"
/*
        6
    9       4
3       8


*/

int main()
{
    Tree *tree = joinTrees(joinTrees(initTree(3),initTree(8),9),initTree(4),6);
    Tree *stree = joinTrees(tree,tree,10);
    showTreePrefix(stree);
    printf("\n");
    printf("this tree has %d nodes.\n",countTreeNodes(stree));

    printf("%d\n",exitInTree(stree,4));
    printf("the height of the tree is %d\n",TreeHeight(stree));
    deleteTree(tree);

    return 0;
}