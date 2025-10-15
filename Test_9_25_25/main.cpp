#include <iostream>

#include <cstdlib>

#include <unordered_map>
#include <unordered_set>
#include <map>
#include <set>

using namespace std;

void test_efficient()
{
    const int num = 1000000;

    unordered_set<int> hash;

    set<int> rb;

    srand(time(0));

    uint time1 = clock();
    for (int i = 0; i < num; ++i)
    {
        //hash.insert(rand() % 100000 + i);
        hash.insert(i);
    }
    uint time2 = clock();
    cout << "hash insert: " << time2 - time1 << "ms" << endl;

    uint time3 = clock();
    for (int i = 0; i < num; ++i)
    {
        //rb.insert(rand() % 10000 + 1);
        rb.insert(i);
    }
    uint time4 = clock();
    cout << "rbtree insert: " << time4 - time3 << "ms" << endl;
}

int main()
{
    test_efficient();

    return 0;
}
