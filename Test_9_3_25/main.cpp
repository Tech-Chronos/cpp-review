#include "RBTree.h"


void TestRBTree1()
{
    RBTree<int, int> rb;
    //{16, 3, 7, 11, 9, 26, 18, 14, 15}
    rb.Insert({16,16});
    std::cout << rb.IsBlackHeightBalanced() << std::endl;

    rb.Insert({3,3});
    std::cout << rb.IsBlackHeightBalanced() << std::endl;

    rb.Insert({7,7});
    std::cout << rb.IsBlackHeightBalanced() << std::endl;

    rb.Insert({11,11});
    std::cout << rb.IsBlackHeightBalanced() << std::endl;

    rb.Insert({9,9});
    std::cout << rb.IsBlackHeightBalanced() << std::endl;

    rb.Insert({26,26});
    std::cout << rb.IsBlackHeightBalanced() << std::endl;

    rb.Insert({18,18});
    std::cout << rb.IsBlackHeightBalanced() << std::endl;

    rb.Insert({14,14});
    std::cout << rb.IsBlackHeightBalanced() << std::endl;

    rb.Insert({15,15});

    rb.InOrder();
    std::cout << rb.IsBlackHeightBalanced() << std::endl;
}

void TestRBTree2()
{
    RBTree<int, int> rb;
    rb.Insert({1,1});

    std::cout << rb.IsBlackHeightBalanced() << std::endl;

}
int main()
{
    TestRBTree1();
    return 0;
}
