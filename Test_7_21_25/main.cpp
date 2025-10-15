#include "RBTree.h"


void test_rbt()
{
    RBTree<int, int> rbt;
    srand((unsigned int)time(nullptr));
    for (int i = 0; i < 1000000; ++i)
    {
        int val = rand() % 1000 + i;
        rbt.insert({val, val});
    }
}

int main()
{
    //test_rbt();
    RBTree<string, string> dict;
    //{ {5, "Apple"}, {3, "Banana"}, {7, "Cherry"}, {2, "Date"}, {8, "Fig"} }
    dict.insert({"apple", "A fruit with red or green skin"});
    dict.insert({"zebra", "An African wild animal with black and white stripes"});
    dict.insert({"cat", "A small domesticated carnivore"});
    dict.insert({"book", "A set of written pages"});

    dict.InOrder();

//    RBTree<int, int> rbt;
//    //{4, 2, 6, 1, 3, 5, 15, 7, 16, 14}
//
//    rbt.insert({4,4});
//    rbt.insert({2,2});
//    rbt.insert({6,6});
//    rbt.insert({1,1});
//    rbt.insert({3,3});
//    rbt.insert({5,5});
//    rbt.insert({15,15});
//    rbt.insert({7,7});
//    rbt.insert({14,14});
//
//    rbt.InOrder();
    return 0;
}
