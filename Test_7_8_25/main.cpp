#include "BSTree.h"

void test1()
{
    BSTree<int> bst;
    int a[] = {50, 30, 70, 20, 40, 60, 80, 10, 25, 35, 45, 65, 75, 85};
    cout << "插入节点" << endl;
    for (auto e : a)
    {
        bst.insert(e);
    }
    bst.InOrder();

    cout << "删除节点" << endl;
    for (auto e : a)
    {
        bst.InOrder();
        bst.erase(e);
    }


}
int main()
{
    test1();
    return 0;
}
