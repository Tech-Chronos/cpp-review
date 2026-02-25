//
// Created by dsj on 2026/2/24.
//

#ifndef STACK_QUEUE_STACK_H
#define STACK_QUEUE_STACK_H
#include <iostream>
#include <deque>


namespace dsj
{
    template <class T, class Container = std::deque<T>>
    class stack
    {
    public:
        void push(const T& val)
        {
            _con.push_back(val);
        }

        void pop()
        {
            _con.pop_back();
        }

        int size() const
        {
            return _con.size();
        }

        bool empty() const
        {
            return _con.empty();
        }

        T& top()
        {
            return _con.back();
        }
    private:
        Container _con;
    };
}
#endif //STACK_QUEUE_STACK_H
