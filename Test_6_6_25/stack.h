//
// Created by 有趣的中国人 on 2025/6/6.
//
#include <iostream>
#include <queue>
#include <string>
#include <vector>
#include <list>
#include <deque>

#ifndef TEST_6_6_25_STACK_H
#define TEST_6_6_25_STACK_H
namespace dsj
{
    // 容器适配器 Container
    template<typename T, typename Container>
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

        const T& top()
        {
            return _con[_con.size() - 1];
        }

        size_t size()
        {
            return _con.size();
        }

        bool empty()
        {
            return _con.empty();
        }
    private:
         Container _con;
    };
}
#endif //TEST_6_6_25_STACK_H
