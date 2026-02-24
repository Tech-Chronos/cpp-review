//
// Created by dsj on 2026/2/24.
//

#ifndef LIST_LIST_H
#define LIST_LIST_H
#include <iostream>
#include <string>
#include <utility>

namespace dsj
{
    template<class T>
    struct Node
    {
        Node(const T& val = T())
            :_val(val)
             ,_prev(nullptr)
             ,_next(nullptr)
        {}
    public:
        T _val;
        Node* _prev;
        Node* _next;
    };

    template<class T, class Ptr, class Ref>
    class ListIterator
    {
    public:
        ListIterator(Node<T>* lptr)
            :_lptr(lptr)
        {}

        ListIterator(const ListIterator& other)
        {
            _lptr = other._lptr;
        }

        ListIterator& operator=(const ListIterator& other)
        {
            if (this != &other)
            {
                _lptr = other._lptr;
            }
            return *this;
        }

        ListIterator(ListIterator&& other)
        {
            _lptr = other._lptr;
            other._lptr = nullptr;
        }

        ListIterator& operator=(ListIterator&& other)
        {
            if (this != &other)
            {
                _lptr = other._lptr;
            }
            return *this;
        }

        Ref operator*()
        {
            return _lptr->_val;
        }

        Ptr operator->()
        {
            return &_lptr->_val;
        }

        // 前置++
        ListIterator& operator++()
        {
            _lptr = _lptr->_next;
            return *this;
        }

        // 后置++
        ListIterator operator++(int)
        {
            ListIterator tmp(_lptr);

            _lptr = _lptr->_next;
            return std::move(tmp);
        }

        // 前置--
        ListIterator& operator--()
        {
            _lptr = _lptr->_prev;
            return *this;
        }

        // 后置--
        ListIterator operator--(int)
        {
            ListIterator tmp(_lptr);

            _lptr = _lptr->_prev;
            return std::move(tmp);
        }

        bool operator==(const ListIterator& other)
        {
            return _lptr == other._lptr;
        }

        bool operator!=(const ListIterator& other)
        {
            return _lptr != other._lptr;
        }

        Node<T>* get()
        {
            return _lptr;
        }
    private:
        Node<T>* _lptr;
    };

    template<class T>
    class list
    {
    public:
        typedef Node<T> Node;
        typedef ListIterator<T, T*, T&> iterator;
        typedef ListIterator<T, const T*, const T&> const_iterator;

        // 迭代器
        iterator begin()
        {
            return _head->_next;
        }

        iterator end()
        {
            return _head;
        }

        const_iterator begin() const
        {
            return _head->_next;
        }

        const_iterator end() const
        {
            return _head;
        }

    public:
        // 构造
        list()
        {
            _head = new Node();
            _head->_prev = _head;
            _head->_next = _head;
        }

        list(const std::initializer_list<T>& il)
            :_head(new Node())
        {
            _head->_prev = _head;
            _head->_next = _head;
            auto it = il.begin();

            while (it != il.end())
            {
                emplace_back(*it);
                ++it;
            }
        }

        template <class InputIterator>
        list(const InputIterator& begin, const InputIterator& end)
            :_head(new Node())
        {
            _head->_prev = _head;
            _head->_next = _head;
            InputIterator tmp = begin;
            while (tmp != end)
            {
                emplace_back(*tmp);
                ++tmp;
            }
        }

        list(size_t n, const T& val = T())
            :_head(new Node())
        {
            _head->_prev = _head;
            _head->_next = _head;
            while (n--)
            {
                emplace_back(val);
            }
        }

        list(const list& other)
            :_head(new Node())
        {
            _head->_prev = _head;
            _head->_next = _head;
            for (auto& e : other)
            {
                emplace_back(e);
            }
        }

        list(list&& other)
        {
            _head = other._head;

            other._head = new Node();
            other._head->_next = other._head;
            other._head->_prev = other._head;
        }

        list& operator=(list&& other)
        {
            if (this != &other)
            {
                _head = other._head;

                other._head = new Node();
                other._head->_next = other._head;
                other._head->_prev = other._head;
            }
            return *this;
        }

        void empty_init()
        {
            iterator it = begin();
            while (it != end())
            {
                it = erase(it);
            }
        }

//        list& operator=(const list& other)
//        {
//            empty_init();
//            if (this != &other)
//            {
//                for (auto& e : other)
//                {
//                    emplace_back(e);
//                }
//            }
//            return *this;
//        }

        list& operator=(list other)
        {
            std::swap(other._head, _head);
            return *this;
        }

        ~list()
        {
            empty_init();
            delete _head;
            _head = nullptr;
        }

        // 修改相关操作
        void insert(iterator pos, const T& val)
        {
            Node* next = pos.get();
            Node* prev = next->_prev;

            Node* new_node = new Node(val);
            new_node->_next = prev->_next;
            new_node->_prev = prev;

            prev->_next = new_node;
            next->_prev = new_node;
        }

        iterator erase(iterator pos)
        {
            Node* cur = pos.get();
            Node* prev = cur->_prev;
            Node* next = cur->_next;

            prev->_next = next;
            next->_prev = prev;

            delete cur;
            cur = nullptr;
            return next;
        }

        void push_back(const T& val)
        {
            insert(end(), val);
        }

        void push_back(T&& val)
        {
            emplace_back(std::move(val));
        }

        void push_front(const T& val)
        {
            insert(begin(), val);
        }

        void push_front(T&& val)
        {
            emplace_front(std::move(val));
        }

        iterator pop_back()
        {
            return erase(--end());
        }

        iterator pop_front()
        {
            return erase(begin());
        }

        template<class... Args>
        void emplace_back(Args&&... args)
        {
            emplace(--end(), std::forward<Args>(args)...);
        }

        template<class... Args>
        void emplace_front(Args&&... args)
        {
            emplace(begin(), std::forward<Args>(args)...);
        }

        template<class... Args>
        void emplace(iterator pos, Args&&... args)
        {
            Node* new_node = new Node(std::forward<Args>(args)...);
            Node* next = pos.get();
            Node* prev = next->_prev;

            new_node->_next = next;
            new_node->_prev = prev;

            prev->_next = new_node;
            next->_prev = new_node;
        }

    private:
        Node* _head;
    };
} // dsj

#endif //LIST_LIST_H
