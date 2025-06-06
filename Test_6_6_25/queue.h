//
// Created by 有趣的中国人 on 2025/6/6.
//
#include <iostream>
#include <queue>
#include <string>
#include <vector>
#include <list>
#include <deque>

#ifndef TEST_6_6_25_QUEUE_H
#define TEST_6_6_25_QUEUE_H
namespace dsj
{
    // 队列
    template<typename T, typename Container>
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

        const T& front()
        {
            return _con[0];
        }

        const T& back()
        {
            return _con[_con.size() - 1];
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

    template<class T>
    class CompareHeapGreater
    {
    public:
        bool operator()(const T& val1, const T& val2)
        {
            return val1 < val2;
        }
    };

    // 优先级队列 -> 堆
    template<class T, class Container = std::vector<int>, class Compare = CompareHeapGreater<T>>
    class priority_queue
    {
    private:
        void adjust_up()
        {
            Compare com;
            size_t child = _con.size() - 1;
            size_t parent = (child - 1) / 2;
            while (child > 0)
            {
                if (com(_con[parent], _con[child]))
                {
                    std::swap(_con[parent], _con[child]);
                }
                child = parent;
                parent = (child - 1) / 2;
            }
        }

        void adjust_down()
        {
            Compare com;
            size_t parent = 0;
            size_t child = (parent * 2) + 1;
            while (child < _con.size())
            {
                if (size() > child + 1 && com(_con[child], _con[child + 1]))
                {
                    ++child;
                }
                if (com(_con[parent], _con[child]))
                {
                    std::swap(_con[parent], _con[child]);
                }
                parent = child;
                child = (parent * 2) + 1;
            }
        }
    public:
        void push(const T& val)
        {
            _con.push_back(val);
            adjust_up();
        }

        void pop()
        {
            std::swap(_con[0], _con[_con.size() - 1]);
            _con.pop_back();
            adjust_down();
        }

        bool empty()
        {
            return _con.empty();
        }

        size_t size()
        {
            return _con.size();
        }

        const T& top()
        {
            return _con[0];
        }
    private:
        Container _con;
    };
}
#endif //TEST_6_6_25_QUEUE_H
