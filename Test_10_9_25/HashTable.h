//
// Created by 有趣的中国人 on 2025/10/9.
//
#include <iostream>
#include <vector>
#include <string>
using namespace std;

#ifndef TEST_10_9_25_HASHTABLE_H
#define TEST_10_9_25_HASHTABLE_H

// 如果不是int类型的比较，可以用仿函数来解决：
template<class K>
struct HashFunc
{
    size_t operator()(const K& key)
    {
        return (size_t)key;
    }
};

// string 常用来被作为key值，因此可以用模版特化一下
template<>
struct HashFunc<string>
{
    size_t operator()(const string& str)
    {
        size_t ret = 0;
        for (auto i : str)
        {
            ret += i;
            ret *= 131;
        }
        return ret;
    }
};

namespace close_hash
{
    template<class T>
    class HashData
    {
    public:
        HashData() = default;

        explicit HashData(const T& kv)
          :_kv(kv)
        {}
    public:
        T _kv;
        HashData* _next = nullptr;
    };

    // 先声明
    template<class K, class T, class KeyOfT, class HashFunc>
    class HashBucket;

    // 迭代器
    template<class K, class T,class Ref, class Ptr, class KeyOfT, class HashFunc>
    class __HBIterator
    {
    public:
        typedef HashData<T> Node;
        typedef __HBIterator<K, T, Ref, Ptr, KeyOfT, HashFunc> Self;

        __HBIterator(Node* node,const HashBucket<K, T, KeyOfT, HashFunc>* phb)
          : _node(node)
          , _phb(phb)
        {}

        Ref operator*()
        {
            return _node->_kv;
        }

        Ptr operator->()
        {
            return &_node->_kv;
        }

        Self& operator++()
        {
            KeyOfT kot;
            HashFunc hf;

            if (_node->_next)
            {
                _node = _node->_next;
            }
            else
            {
                size_t hashi = hf(kot(_node->_kv)) % _phb->_table.size();
                ++hashi;
                for (; hashi < _phb->_table.size(); ++hashi)
                {
                    if (_phb->_table[hashi])
                    {
                        _node = _phb->_table[hashi];
                        break;
                    }
                }

                if (hashi >= _phb->_table.size())
                {
                    _node = nullptr;
                }
            }

            return *this;
        }

        bool operator==(const Self& self)
        {
            return _node == self._node;
        }

        bool operator!=(const Self& self)
        {
            return _node != self._node;
        }

    private:
        Node* _node;
        const HashBucket<K, T, KeyOfT, HashFunc>* _phb;
    };

    template<class K, class T, class KeyOfT, class HashFunc>
    class HashBucket
    {
        typedef HashData<T> Node;
    public:
        // 声明友元
        friend __HBIterator<K, T, T&, T*, KeyOfT, HashFunc>;
        friend __HBIterator<K, T, const T&, const T*, KeyOfT, HashFunc>;

        typedef __HBIterator<K, T, T&, T*, KeyOfT, HashFunc> Iterator;
        typedef __HBIterator<K, T, const T&, const T*, KeyOfT, HashFunc> Const_Iterator;

        Const_Iterator begin() const
        {
            for (size_t i = 0; i < _table.size(); ++i)
            {
                if (_table[i])
                {
                    return Const_Iterator(_table[i], this);
                }
            }
            return {nullptr, this};
        }

        Const_Iterator end() const
        {
            return {nullptr, this};
        }

        Iterator begin()
        {
            for (size_t i = 0; i < _table.size(); ++i)
            {
                if (_table[i])
                {
                    return Iterator(_table[i], this);
                }
            }
            return {nullptr, this};
        }

        Iterator end()
        {
            return {nullptr, this};
        }

        explicit HashBucket(size_t size = 5)
        {
            _table.resize(size);
            _size = 0;
        }

        ~HashBucket()
        {
            for (size_t i = 0; i < _table.size(); ++i)
            {
                if (_table[i])
                {
                    Node* cur = _table[i];
                    while (cur)
                    {
                        Node* next = cur->_next;
                        delete cur;
                        cur = next;
                    }
                }
            }
        }

        pair<Iterator, bool> Insert(const T& kv)
        {
            KeyOfT kot;
            HashFunc hf;

            Iterator it = Find(kot(kv));
            if (it != Iterator(nullptr, this))
            {
                return {it, false};
            }

            if (_table.size() == _size)
            {
                vector<Node*> newvec(_table.size() * 2);

                for (size_t i = 0; i < _table.size(); ++i)
                {
                    if (_table[i])
                    {
                        Node* cur = _table[i];
                        while (cur)
                        {
                            Node* next = cur->_next;
                            size_t hashi = hf(kot(cur->_kv)) % newvec.size();
                            cur->_next = newvec[hashi];
                            newvec[hashi] = cur;
                            cur = next;
                        }
                    }
                    _table[i] = nullptr;
                }
                _table.swap(newvec);
//                HashBucket<K, V> hb(_table.size() * 2);
//                for (size_t i = 0; i < _table.size(); ++i)
//                {
//                    if (_table[i])
//                    {
//                        Node* cur = _table[i];
//                        while (cur)
//                        {
//                            hb.Insert(_table[i]->_kv);
//                            cur = cur->_next;
//                        }
//                    }
//                }
            }
            Node* newnode = new Node(kv);

            size_t hashi = hf(kot(kv)) % _table.size();
            newnode->_next = _table[hashi];
            _table[hashi] = newnode;
            ++_size;

            it = {newnode, this};
            return {it, true};
        }

        Iterator Find(const K& key)
        {
            HashFunc hf;
            KeyOfT kot;
            size_t hashi = hf(key) % _table.size();
            Node* cur = _table[hashi];
            while (cur)
            {
                if (kot(cur->_kv) == key)
                {
                    return {cur, this};
                }
                cur = cur->_next;
            }
            return {nullptr, this};
        }

        bool Erase(const K& key)
        {
            HashFunc hf;
            KeyOfT kot;

            size_t hashi = hf(key) % _table.size();

            Node* node = _table[hashi];
            Node* prev = nullptr;

            while(node)
            {
                if (hf(kot(node->_kv)) != key)
                {
                    prev = node;
                    node = node->_next;
                }
                else
                {
                    prev = node->_next;
                    delete node;
                    return true;
                }
            }
            return false;
        }
    private:
        vector<Node*> _table;
        size_t _size;
    };

//    void Test1()
//    {
//        HashBucket<int, int> hs;
//        hs.Insert({1,1});
//        hs.Insert({10001,13});
//        hs.Insert({2,12});
//    }

//    void Test2()
//    {
//        int arr[] = {1,2,4,10001,44,89,28,93};
//
//        {
//            HashBucket<int, int> hb;
//            for (auto i : arr)
//            {
//                hb.Insert(make_pair(i,i));
//            }
//        }
//
//        int i = 0;
//    }
}


/////////////////////
//闭散列的开放地址法////
/////////////////////
namespace open_address
{
    // 如果不是int类型的比较，可以用仿函数来解决：
    template<class K>
    struct HashFunc
    {
        size_t operator()(const K& key)
        {
            return (size_t)key;
        }
    };

    // string 常用来被作为key值，因此可以用模版特化一下
    template<>
    struct HashFunc<string>
    {
        size_t operator()(const string& str)
        {
            size_t ret = 0;
            for (auto i : str)
            {
                ret += i;
                ret *= 131;
            }
            return ret;
        }
    };

    enum Status
    {
        EMPTY,
        OCCUPIED,
        DELETE
    };

    template<class K, class V>
    struct HashData
    {
        pair<K, V> _kv;
        Status _status = EMPTY;
    };

    template<class K, class V, class HashFunc = HashFunc<K>>
    class HashTable
    {
    public:
        explicit HashTable(size_t size = 10)
        {
            _table.resize(size);
            _size = 0;
        }

        bool Insert(const pair<K, V>& kv)
        {
            HashFunc hf;
            if (Find(kv.first) != nullptr)
            {
                return false;
            }

            // 负载因子大于0.7扩容
            if ((_size * 10) / _table.size() >= 7)
            {
                size_t newsize = _table.size() * 2;
                HashTable<K, V> newHT(newsize);

                for (size_t i = 0; i < _table.size(); ++i)
                {
                    if (_table[i]._status == OCCUPIED)
                    {
                        newHT.Insert(_table[i]._kv);
                    }
                }
                _table.swap(newHT._table);
            }

            size_t hashi = hf(kv.first) % _table.size();
            while (_table[hashi]._status != EMPTY)
            {
                ++hashi;
                hashi %= _table.size();
            }
            _table[hashi]._kv = kv;
            _table[hashi]._status = OCCUPIED;
            ++_size;

            return true;
        }

        HashData<K, V>* Find(const K& key)
        {
            HashFunc hf;
            size_t hashi = hf(key) % _table.size();
            while (_table[hashi]._status != EMPTY)
            {
                // 如果是删除过的数据不能找到
                if (_table[hashi]._status != DELETE &&
                    _table[hashi]._kv.first == key)
                {
                    return &_table[hashi];
                }
                ++hashi;
            }
            return nullptr;
        }

        bool Erase(const K& key)
        {
            HashData<K, V>* ret = Find(key);
            if (ret == nullptr)
            {
                return false;
            }

            ret->_status = DELETE;
            --_size;
            return true;
        }
    private:
        vector<HashData<K,V>> _table;
        size_t _size;
    };

    void Test1()
    {
        HashTable<int, int> hash;
        hash.Insert({1,1});
        hash.Insert({2,1});
        hash.Insert({3,1});
        hash.Insert({4,1});

        cout << hash.Find(3) << endl;
        cout << hash.Find(4) << endl;

        hash.Erase(3);
        cout << hash.Find(3) << endl;
        cout << hash.Find(4) << endl;
    }

    void Test2()
    {
        HashTable<string, string> hash;
        hash.Insert({"sort","排序"});
        hash.Insert({"left","左边"});
        hash.Insert({"right","右边"});
        hash.Insert({"middle","中间"});


    }
}

#endif //TEST_10_9_25_HASHTABLE_H
