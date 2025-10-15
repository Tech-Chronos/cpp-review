//
// Created by 有趣的中国人 on 2025/6/5.
//
#include <iostream>
#include <cassert>

namespace dsj
{
    // 链表节点类型
    template<typename T>
    class ListNode
    {
    public:
        ListNode(const T& val = T())
                :_prev(nullptr)
                ,_next(nullptr)
                ,_val(val)
        {}


        ListNode(T&& val)
                :_prev(nullptr)
                ,_next(nullptr)
                ,_val(std::move(val))
        {}

        template<class ...Args>
        ListNode(Args&& ...args)
                :_prev(nullptr)
                ,_next(nullptr)
                ,_val(std::forward<T>(args)...)
        {}

    public:
        ListNode* _prev;
        ListNode* _next;
        T _val;
    };

    // 反向迭代器直接复用正向迭代器
    template<class iterator, class Ref, class Ptr>
    class ReverseIterator
    {
        typedef ReverseIterator<iterator, Ref, Ptr> Self;
    public:
        ReverseIterator(iterator it)
                :_it(it)
        {}

        Ref operator*()
        {
            iterator it = _it;
            --it;
            return *it;
        }


//        Ptr operator->()
//        {
//            Self tmp(_it);
//            return &(*(--tmp));
//        }

        Self& operator++()
        {
            --_it;
            return *this;
        }

        Self& operator--()
        {
            ++_it;
            return *this;
        }

        bool operator!=(const Self& rit)
        {
            return _it != rit._it;
        }
    private:
        iterator _it;
    };

    // 迭代器类型
    template<typename T, typename Ref, typename Ptr>
    class ListIterator
    {
    public:
        typedef ListNode<T> Node;
        typedef ListIterator<T, Ref, Ptr> Self;

        ListIterator(Node* node)
                :_node(node)
        {}

        // 解引用
        Ref operator*()
        {
            return _node->_val;
        }

        Ptr operator->()
        {
            return &_node->_val;
        }
        // 前置++
        Self& operator++()
        {
            _node = _node->_next;
            return *this;
        }

        // 后置++
        Self operator++(int)
        {
            Self tmp(this->_node);
            _node = _node->_next;
            return tmp;
        }

        // 前置--
        Self& operator--()
        {
            _node = _node->_prev;
            return *this;
        }
        // 后置--
        Self operator--(int)
        {
            Self tmp(_node);
            _node = _node->_next;
            return tmp;
        }
        // !=
        bool operator!=(const Self& it)
        {
            return _node != it._node;
        }
    public:
        Node* _node;
    };

    // const 迭代器
//    template<typename T>
//    class ListConstIterator
//    {
//    public:
//        typedef ListNode<T> Node;
//        typedef ListConstIterator<T> Self;
//
//        ListConstIterator(Node* node)
//                :_node(node)
//        {}
//
//        // 解引用
//        const T& operator*()
//        {
//            return _node->_val;
//        }
//
//        const T* operator->()
//        {
//            return &_node->_val;
//        }
//        // 前置++
//        Self& operator++()
//        {
//            _node = _node->_next;
//            return *this;
//        }
//
//        // 后置++
//        Self operator++(int)
//        {
//            Self tmp(this->_node);
//            _node = _node->_next;
//            return tmp;
//        }
//
//        // 前置--
//        Self& operator--()
//        {
//            _node = _node->_prev;
//            return *this;
//        }
//        // 后置--
//        Self operator--(int)
//        {
//            Self tmp(_node);
//            _node = _node->_next;
//            return tmp;
//        }
//        // !=
//        bool operator!=(const Self& it)
//        {
//            return _node != it._node;
//        }
//    public:
//        Node* _node;
//    };

    // 链表类
    template<typename T>
    class list
    {
    public:
        typedef ListNode<T> Node;
        typedef ListIterator<T, T&, T*> iterator;
        typedef ListIterator<T, const T&, const T*> const_iterator;

        typedef ReverseIterator<iterator, T&, T*> reverse_iterator;
        typedef ReverseIterator<iterator, const T&, const T*> const_reverse_iterator;

        // construct
        list()
        {
            _head = new Node;
            // 指向自身
            _head->_prev = _head;
            _head->_next = _head;
        }

        list(const T& val)
        {
            _head = new Node;
            Node* newnode = new Node(val);
            _head->_next = newnode;
            _head->_prev = newnode;
            newnode->_prev = _head;
            newnode->_next = _head;
        }

        list(const std::initializer_list<T>& il)
        {
            // 哨兵位头节点
            _head = new Node;
            // 指向自身
            _head->_prev = _head;
            _head->_next = _head;
            typename std::initializer_list<T>::iterator it = il.begin();
            while (it != il.end())
            {
                push_back(*it);
                ++it;
            }
        }

        // 拷贝构造 ls1(ls2)
        list(const list<T>& ls)
        {
            // 哨兵位头节点
            _head = new Node;
            // 指向自身
            _head->_prev = _head;
            _head->_next = _head;

            for (auto& e : ls)
            {
                push_back(e);
            }
        }

        // 赋值重载 ls1 = ls3
        list<T>& operator=(list<T> ls)
        {
            swap(ls);
            return *this;
        }

        void swap(list<T> ls)
        {
            std::swap(_head, ls._head);
        }

        // iterator
        iterator begin()
        {
            return iterator(_head->_next);
        }

        iterator end()
        {
            return iterator(_head);
        }

        const_iterator begin() const
        {
            return const_iterator(_head->_next);
        }

        const_iterator end() const
        {
            return const_iterator(_head);
        }

        reverse_iterator rbegin()
        {
            return reverse_iterator(iterator(_head));
        }

        reverse_iterator rend()
        {
            return reverse_iterator(iterator(_head->_next));
        }

        const_reverse_iterator rbegin() const
        {
            return const_reverse_iterator(iterator(_head));
        }

        const_reverse_iterator rend() const
        {
            return const_reverse_iterator(iterator(_head->_next));
        }
        // modify
        void insert(iterator pos, const T& val = T())
        {
            Node* newnode = new Node(val);
            Node* cur = pos._node;
            Node* prev = cur->_prev;
            newnode->_prev = prev;
            newnode->_next = cur;
            cur->_prev = newnode;
            prev->_next = newnode;
        }

        void insert(iterator pos, T&& val)
        {
            Node* newnode = new Node(std::move(val));
            Node* cur = pos._node;
            Node* prev = cur->_prev;
            newnode->_prev = prev;
            newnode->_next = cur;
            cur->_prev = newnode;
            prev->_next = newnode;
        }

        template<class ...Args>
        void emplace(iterator pos, Args ...args)
        {
            Node* newnode = new Node(args...);
            Node* cur = pos._node;
            Node* prev = cur->_prev;
            newnode->_prev = prev;
            newnode->_next = cur;
            cur->_prev = newnode;
            prev->_next = newnode;
        }

        void push_front(const T& val)
        {
            insert(begin(), val);
//            Node* newnode = new Node(val);
//            Node* tail = _head->_prev;
//            newnode->_prev = tail;
//            newnode->_next = _head;
//            _head->_prev = newnode;
//            tail->_next = newnode;
        }

        void push_back(const T& val)
        {
            insert(end(), val);
        }

        // 移动构造，val本身是左值，完美转发
        void push_back(T&& val)
        {
            //insert(end(), std::move(val));

            insert(end(), std::forward<T>(val));
        }

        template<class ...Args>
        void emplace_back(Args ...args)
        {
            emplace(end(), args...);
        }

        iterator erase(iterator pos)
        {
            Node* cur = pos._node;
            Node* prev = cur->_prev;
            Node* next = cur->_next;

            prev->_next = next;
            next->_prev = prev;

            delete cur;

            return next;
        }

        void pop_back()
        {
            erase(--end());
        }

        void pop_front()
        {
            erase(begin());
        }
    private:
        Node* _head; // 💂 哨兵位头节点
    };
}

