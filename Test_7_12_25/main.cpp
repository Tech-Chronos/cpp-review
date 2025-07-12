#include "AVLTree.h"

void Test_AVL()
{
    AVLTree<string, string> avl;
    avl.insert({"China","中国"});
    avl.insert({"America","美国"});
    avl.insert({"French","法国"});
    avl.insert({"Germany","德国"});
    avl.insert({"British","英国"});
    avl.insert({"Dubai","迪拜"});
    avl.insert({"Egypt","埃及"});

    //AVLTreeNode<string, string>* node = avl.find("Germany");

    //cout << node->_val.first << " : " << node->_val.second << endl;
    avl.InOrder();
}

int main()
{
    Test_AVL();
    return 0;
}