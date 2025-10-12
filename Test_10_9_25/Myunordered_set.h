//
// Created by 有趣的中国人 on 2025/10/10.
//
#include "HashTable.h"
#ifndef TEST_10_9_25_MYUNORDERED_SET_H
#define TEST_10_9_25_MYUNORDERED_SET_H

namespace dsj
{
    template<class K, class HashFunc = HashFunc<K>>
    class unordered_set
    {
    public:
        struct KeyOfT
        {
            const K& operator()(const K& key)
            {
                return key;
            }
        };
    public:
        typedef close_hash::HashData<K> Node;
        typedef typename close_hash::HashBucket<K, K, KeyOfT, HashFunc>::Iterator iterator;
        typedef typename close_hash::HashBucket<K, K, KeyOfT, HashFunc>::Const_Iterator const_iterator;

        const_iterator begin() const
        {
            return _hb.begin();
        }

        const_iterator end() const
        {
            return _hb.end();
        }

        iterator begin()
        {
            return _hb.begin();
        }

        iterator end()
        {
            return _hb.end();
        }

        pair<iterator, bool> insert(const K& key)
        {
            return _hb.Insert(key);
        }

        iterator find(const K& key)
        {
            return _hb.find(key);
        }

        bool erase(const K& key)
        {
            return _hb.Erase(key);
        }

    private:
        close_hash::HashBucket<K, K, KeyOfT, HashFunc> _hb;
    };

    void Test1()
    {
        unordered_set<int> uset;
        int arr[] = {1,2,3,4,5,6,8,9,0};

        for (auto i : arr)
        {
            uset.insert(i);
        }

        unordered_set<int>::iterator it = uset.begin();
        while (it != uset.end())
        {
            std::cout << *it << std::endl;
            if (*it == 9)
            {
                int i = 0;
            }
            ++it;
        }

    }
}

#endif //TEST_10_9_25_MYUNORDERED_SET_H
