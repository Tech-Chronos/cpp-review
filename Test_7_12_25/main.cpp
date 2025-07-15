#include "AVLTree.h"

void Test_AVL1()
{
    AVLTree<string, string> avl;
//    avl.insert({"China","中国"});
//    avl.insert({"America","美国"});
//    avl.insert({"French","法国"});
//    avl.insert({"Germany","德国"});
//    avl.insert({"British","英国"});
//    avl.insert({"Dubai","迪拜"});
//    avl.insert({"Egypt","埃及"});

    vector<pair<string,string>> v;
    v.push_back({"China","中国"});
    v.push_back({"America","美国"});
    v.push_back({"French","法国"});
    v.push_back({"Germany","德国"});
    v.push_back({"British","英国"});
    v.push_back({"Dubai","迪拜"});
    v.push_back({"Egypt","埃及"});

    auto it = v.begin();
    for (;it != v.end(); ++it)
    {
        avl.insert(*it);
        cout << "Insert: " << it->first << " -> " << avl.IsBalance() << endl;
    }

    // cout << avl.Height() << endl;
    // AVLTreeNode<string, string>* node = avl.find("Germany");

    //cout << node->_val.first << " : " << node->_val.second << endl;
    avl.InOrder();
}

void Test_AVL2()
{
    AVLTree<int, int> avl;
    srand((unsigned int)time(nullptr));
    for (int i = 0; i < 10000000; ++i)
    {
        int val = rand() % 10000000 + i;
        avl.insert({val, val});
    }

    
    cout << "Height => " << avl.Height() << endl;
    cout << "Size => " << avl.Size() << endl;
    cout << "IsBalance => " << avl.IsBalance() << endl;
}

int main()
{
    Test_AVL2();
    return 0;
}