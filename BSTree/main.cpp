#include <iostream>
#include "BSTree.h"

int main()
{
    BSTree<int> bst;
    bst.insert(1);
    bst.insert(9);
    bst.insert(8);
    bst.insert(7);
    bst.insert(10);
    bst.insert(3);

    bst.InOrder();

    return 0;
}
