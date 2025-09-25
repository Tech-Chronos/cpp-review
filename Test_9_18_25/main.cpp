#include "myMap.h"
#include "mySet.h"

#include <map>

//void test1()
//{
//    RBTree<int, int> rb1;
//
//    // {4, 2, 6, 1, 3, 5, 15, 7, 16, 14}
//    rb1.Insert({4,10});
//
//    rb1.Insert({2,1});
//
//    rb1.Insert({6,0});
//
//    rb1.Insert({1,9});
////
//    rb1.Insert({3,9});
////
//    rb1.Insert({5,9});
////
//    rb1.Insert({15,9});
////
//    rb1.Insert({7,9});
////
//    rb1.Insert({16,9});
////
//    rb1.Insert({14,9});
//
//    rb1.InOrder();
//
//    rb1.IsBalance();
//
//}

void testmap()
{
    mymap<int, int> map;
    map.insert({2,1});

    myset<int> set;
    set.insert(2);
}

void formal_map_test()
{
    map<int, int> mp1 = {
            {4,4},{2,4},{6,4},
            {1,4},{3,4},{5,4},
            {15,4},{7,4},{16,4},
            {14,4}
    };

    map<int, int>::iterator it = mp1.begin();
    while (it != mp1.end())
    {
        ++it;
        cout << it->first << ": " << it->second << endl;
    }
}

int main()
{
    //test_set();
    //test_map1();

    test_map4();

    //formal_map_test();
    return 0;
}
