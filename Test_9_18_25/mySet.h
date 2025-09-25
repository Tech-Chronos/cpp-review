//
// Created by 有趣的中国人 on 2025/9/22.
//
#include "RBTRee.h"
#ifndef TEST_9_18_25_MYSET_H
#define TEST_9_18_25_MYSET_H
template <class K>
class myset
{
public:
    struct KeyOfV
    {
        const K& operator()(const K& key)
        {
            return key;
        }
    };
public:
    typedef typename RBTree<K, K, KeyOfV>::Iterator iterator;
    typedef typename RBTree<K, K, KeyOfV>::Const_Iterator const_iterator;

    myset() = default;

    myset(const initializer_list<const K>& il)
    {
        typename initializer_list<const K>::iterator it = il.begin();
        while (it != il.end())
        {
            rb.Insert(*it);
            ++it;
        }
    }

    void insert(const K& key)
    {
        rb.Insert(key);
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

private:
    RBTree<K, K, KeyOfV> rb;
};

void test_set()
{
    // 4, 2, 6, 1, 3, 5, 15, 7, 16, 14
    myset<int> ms;
    ms.insert(4);
    ms.insert(2);
    ms.insert(6);
    ms.insert(1);
    ms.insert(3);
    ms.insert(5);
    ms.insert(15);
    ms.insert(7);
    ms.insert(16);
    ms.insert(14);

    myset<int>::iterator it = ms.begin();

    while (it != ms.end())
    {
        cout << *it <<endl;
        ++it;
    }


}
#endif //TEST_9_18_25_MYSET_H
