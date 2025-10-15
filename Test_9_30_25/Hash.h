//
// Created by 有趣的中国人 on 2025/9/30.
//
#include <iostream>
#include <vector>
using namespace std;
#ifndef TEST_9_30_25_HASH_H
#define TEST_9_30_25_HASH_H

enum Status
{
    OCCUPIED,
    DELETED,
    EMPTY
};

template <class K, class V>
struct HashData
{
    pair<K, V> _kv;
    Status _status = EMPTY;
};

// 闭散列的开放地址法
template <class K, class V>
class Hashmap
{
    Hashmap() = default;

    Hashmap(size_t size = 10)
    :_vc(_vc.resize(size))
    {}

public:

    bool insert(const pair<K,V>& kv)
    {
        if (_size == _vc.size())
        {
            size_t newsize = _size * 2;
            auto hashptr = new Hashmap<K, V>(newsize);
            for (auto i = 0; i < _size; ++i)
            {
                hashptr->insert(_vc[i]._kv);
            }
            swap(hashptr->_vc, _vc);
        }

        int loc = kv.first % _vc.size();
        while (_vc[loc]._status != EMPTY)
        {
            ++loc;
            loc %= _vc.size();
        }

        _vc[loc]._kv = kv;
        _vc[loc]._status = OCCUPIED;
        ++_size;
    }

    bool erase(const K& key)
    {
        int loc = key % _vc.size();
        while (_vc[loc]._kv.first != key)
        {
            ++loc;
            loc %= _vc.size();
        }
    }

private:
    vector<HashData<K, V>> _vc;
    size_t _size;
};

#endif //TEST_9_30_25_HASH_H
