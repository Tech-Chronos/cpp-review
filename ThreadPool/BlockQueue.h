//
// Created by dsj on 2026/3/14.
//

#ifndef THREADPOOL_BLOCKQUEUE_H
#define THREADPOOL_BLOCKQUEUE_H
#include <iostream>
#include <queue>
#include <thread>
#include <mutex>
#include <condition_variable>

template <class T>
class BlockQueue
{
private:
    bool IsEmpty()
    {
        return _tasks.empty();
    }

    bool IsFull()
    {
        return _tasks.size() == _max_size;
    }
public:
    BlockQueue(int max_size)
        :_max_size(max_size)
    {
    }

    // 生产者进队列，要有空间
    void Enque(const T& task)
    {
        std::unique_lock<std::mutex> lock(_mutex);
        while (IsFull())
        {
            _cond_space.wait(lock);
        }
        _tasks.push(task);
        _cond_data.notify_one();
    }

    // 消费者拿任务，要有数据
    void Deque(T* task)
    {
        std::unique_lock<std::mutex> lock(_mutex);
        while (IsEmpty())
        {
            _cond_data.wait(lock);
        }
        *task = _tasks.front();
        _tasks.pop();
        _cond_space.notify_one();
    }
private:
    std::queue<T> _tasks;
    int _max_size;
    std::mutex _mutex;
    std::condition_variable _cond_space;
    std::condition_variable _cond_data;
};

#endif //THREADPOOL_BLOCKQUEUE_H
