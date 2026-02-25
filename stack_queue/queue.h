//
// Created by dsj on 2026/2/24.
//

#ifndef STACK_QUEUE_QUEUE_H
#define STACK_QUEUE_QUEUE_H
#include <iostream>
#include <deque>
#include <vector>

namespace dsj
{
    template <class T, class Container = std::deque<T>>
    class queue
    {
    public:
        void push(const T& val)
        {
            _con.push_back(val);
        }

        void pop()
        {
            _con.pop_front();
        }

        T& front()
        {
            return _con.front();
        }

        T& back()
        {
            return _con.back();
        }

        bool empty()
        {
            return _con.empty();
        }

        size_t size()
        {
            return _con.size();
        }

    private:
        Container _con;
    };

    // 建立大堆
    template <class T>
    struct less
    {
        bool operator()(const T& _val, const T& other)
        {
            return _val > other;
        }
    };

    template <class T>
    struct greater
    {
        bool operator()(const T& _val, const T& other)
        {
            return _val < other;
        }
    };

    template <class T, class Container = std::vector<T>, class Compare = greater<T>>
    class priority_queue
    {
    private:
        void AdjustUp(size_t child)
        {
            size_t parent = (child - 1) / 2;
            while (child > 0)
            {
                Compare com;
                if (com(_con[child], _con[parent]))
                {
                    std::swap(_con[child], _con[parent]);
                    child = parent;
                    parent = (child - 1) / 2;
                }
                else
                    break;
            }
        }

        void AdjustDown(size_t parent)
        {
            size_t child = parent * 2 + 1;
            if (child + 1 < _con.size() && _con[child] < _con[child + 1])
            {
                ++child;
            }
            while (child < _con.size())
            {
                Compare com;
                if (com(_con[child], _con[parent]))
                {
                    std::swap(_con[child], _con[parent]);
                    parent = child;
                    child = parent * 2 + 1;
                }
                else
                    break;
            }
        }
    public:
        void push(const T& val)
        {
            _con.push_back(val);
            AdjustUp(_con.size() - 1);
        }

        void pop()
        {
            std::swap(_con.front(), _con.back());
            _con.pop_back();
            AdjustDown(0);
        }

        const T& top()
        {
            return _con.front();
        }

        size_t size() const
        {
            return _con.size();
        }

    private:
        Container _con;
    };
}
#endif //STACK_QUEUE_QUEUE_H
