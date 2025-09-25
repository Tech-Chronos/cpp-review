//
// Created by 有趣的中国人 on 2025/9/22.
//
#include "RBTRee.h"
#include <string>
#include <vector>

#ifndef TEST_9_18_25_MYMAP_H
#define TEST_9_18_25_MYMAP_H

template<class K, class V>
class mymap
{
public:
    struct KeyOfV
    {
        const K& operator()(const std::pair<K, V> kv)
        {
            return kv.first;
        }
    };
public:
    typedef typename RBTree<K, pair<const K, V>, KeyOfV>::Iterator iterator;
    typedef typename RBTree<K, pair<const K, V>, KeyOfV>::Const_Iterator const_iterator;

    mymap() = default;

    mymap(const initializer_list<const pair<K, V>>& il)
    {
        typename initializer_list<const pair<K, V>>::iterator it = il.begin();
        while (it != il.end())
        {
            rb.Insert(*it);
            ++it;
        }
    }

    pair<iterator, bool> insert(const pair<K, V>& kv)
    {
        return rb.Insert(kv);
    }

    //
    V& operator[](const K& key)
    {
        pair<iterator, bool> ret = rb.Insert({key, V()});

        return ret.first->second;
    }

    iterator begin()
    {
        return rb.begin();
    }

    iterator end()
    {
        return rb.end();
    }

    const_iterator begin() const
    {
        return rb.begin();
    }

    const_iterator end() const
    {
        return rb.end();
    }

    bool isbalance()
    {
        return rb.IsBalance();
    }
private:
    RBTree<K, std::pair<const K, V>, KeyOfV> rb;
};

// 4, 2, 6, 1, 3, 5, 15, 7, 16, 14
void test_map1()
{
    mymap<int, int> mp = {
                            {4,4},{2,4},{6,4},
                            {1,4},{3,4},{5,4},
                            {15,4},{7,4},{16,4},
                            {14,4}
                         };

//    mp.insert({4,4});
//    mp.insert({2,4});
//    mp.insert({6,4});
//    mp.insert({1,4});
//    mp.insert({3,4});
//    mp.insert({5,4});
//    mp.insert({15,4});
//    mp.insert({7,4});
//    mp.insert({16,4});
//    mp.insert({14,4});


    mymap<int, int>::iterator it = mp.begin();
    while (it != mp.end())
    {
        cout << it->first << ": " << it->second << endl;
        ++it;
    }
}

void test_map2()
{
    mymap<int, int> mp1 = {
            {4,4},{2,4},{6,4},
            {1,4},{3,4},{5,4},
            {15,4},{7,4},{16,4},
            {14,4}
    };

    mymap<int, int> mp2 = mp1;

    mymap<int, int> mp3{{1,1}};

    mp1 = mp3;
    mymap<int, int>::iterator it = mp1.begin();
    while (it != mp1.end())
    {

        cout << it->first << ": " << it->second << endl;
        ++it;
    }

    //cout << "balance?" << mp2.isbalance() << endl;
//    while (it != mp2.begin())
//    {
//        cout << it->first << ": " << it->second;
//        --it;
//    }

}

void test_map3()
{
    std::vector<std::string> strs = { "苹果", "苹果", "香蕉", "香蕉" };
    mymap<string, int> countmap;
    for (auto& e : strs)
    {
        countmap[e]++;
    }

    for (auto& e : countmap)
    {
        cout << e.first << ": " << e.second << endl;
    }
}

void test_map4()
{
    mymap<int, int> mp1 = {
            {4,4},{2,4},{6,4},
            {1,4},{3,4},{5,4},
            {15,4},{7,4},{16,4},
            {14,4}
    };

    mymap<int, int> mp2 {{1,2},{3,4}};

    mp1 = mp2;

    cout << mp2.isbalance() << endl;
    cout << mp1.isbalance() << endl;
}
#endif //TEST_9_18_25_MYMAP_H
