//
// Created by dsj on 2026/3/1.
//

#ifndef HASH_HASH_H
#define HASH_HASH_H
#include <iostream>
#include <vector>
#include <string>

using namespace std;

template <class T>
struct HashFunc
{
    size_t operator()(const T& val)
    {
        return (size_t)val;
    }
};

template<>
struct HashFunc<string>
{
    size_t operator()(const string& str)
    {
        size_t ret = 0;
        for (auto e : str)
        {
            ret += e;
            ret *= 131;
        }
        return ret;
    }
};

namespace open_address
{
    enum Status
    {
        EXIST,
        EMPTY,
        DELETE
    };

    template <class K, class V>
    struct HashData
    {
        pair<K, V> _kv;
        Status _status;
    };

    template <class K, class V>
    class Hash
    {
    public:
        Hash(size_t size = 10)
        {
            _hash_tb.resize(size);
        }

        bool insert(const pair<K, V>& val)
        {
            if (find(val.first))
                return false;
            if (_size * 10 / _hash_tb.size() >= 7)
            {
                size_t newsize = 2 * _hash_tb.size();
                Hash newhash(newsize);

                for (int i = 0; i < _hash_tb.size(); ++i)
                {
                    if (_hash_tb[i]._status == EXIST)
                    {
                        newhash.insert(_hash_tb[i]._kv);
                    }
                }
                std::swap(_hash_tb, newhash._hash_tb);
            }

            int hashi = val.first % _hash_tb.size();
            while (_hash_tb[hashi]._status == EXIST)
            {
                ++hashi;
                hashi %= _hash_tb.size();
            }
            _hash_tb[hashi]._kv = val;
            _hash_tb[hashi]._status = EXIST;
            ++_size;
            return true;
        }

        HashData<K, V>* find(const K& key)
        {
            size_t hashi = key % _hash_tb.size();

            while (_hash_tb[hashi]._status != EMPTY)
            {
                if (_hash_tb[hashi]._kv.first == key)
                {
                    return &_hash_tb[hashi];
                }
                ++hashi;
                hashi %= _hash_tb.size();
            }
            return nullptr;
        }

        bool erase(const K& key)
        {
            auto pos = find(key);
            if (!pos)
                return false;
            pos->_status = DELETE;
            --_size;
            return true;
        }

    private:
        vector<HashData<K, V>> _hash_tb;
        size_t _size;
    };
}

namespace Bucket
{
    template <class K, class V>
    struct HashNode
    {
        typedef HashNode<K, V> Node;
        HashNode()
        {}

        HashNode(const pair<K, V>& val)
            :_kv(val)
        {}
        Node* _next;
        pair<K, V> _kv;
    };

    template <class K, class V>
    class HashBucket
    {
    public:
        typedef HashNode<K, V> Node;
        HashBucket(size_t size)
        {
            _hash_tb.resize(size);
        }

        bool insert(const pair<K, V>& val)
        {
            if (find(val.first))
                return false;
            if (_size == _hash_tb.size())
            {
                vector<Node*> newht;
                newht.resize(2 * _hash_tb.size());
                for (int i = 0; i < _hash_tb.size(); ++i)
                {
                    Node* cur = _hash_tb[i];
                    Node* next = nullptr;
                    while (cur)
                    {
                        next = cur->_next;
                        size_t hashi = cur->_kv.first % newht.size();

                        cur->_next = newht[hashi];
                        newht[hashi] = cur;

                        cur = next;
                    }
                }
                std::swap(newht, _hash_tb);
            }
            size_t hashi = val.first % _hash_tb.size();

            Node* new_node = new Node(val);

            new_node->_next = _hash_tb[hashi];
            _hash_tb[hashi] = new_node;
            ++_size;
            return true;
        }

        HashNode<K, V>* find(const K& key)
        {
            size_t hashi = key % _hash_tb.size();
            Node* cur = _hash_tb[hashi];
            while (cur)
            {
                if (cur->_kv.first == key)
                {
                    return cur;
                }
                cur = cur->_next;
            }
            return nullptr;
        }

        bool erase(const K& key)
        {
            size_t hashi = key % _hash_tb.size();
            Node* cur = _hash_tb[hashi];
            Node* prev = nullptr;
            while (cur)
            {
                if (cur->_kv.first == key)
                {
                    if (prev == nullptr)
                    {
                        _hash_tb[hashi] = cur->_next;
                    }
                    else
                    {
                        prev->_next = cur->_next;
                    }
                    --_size;
                    delete cur;
                    return true;
                }
                else
                {
                    prev = cur;
                    cur = cur->_next;
                }
            }
            return false;
        }

    private:
        vector<Node*> _hash_tb;
        size_t _size = 0;
    };
}


#endif //HASH_HASH_H
