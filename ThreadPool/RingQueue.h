//
// Created by dsj on 2026/3/14.
//

#ifndef THREADPOOL_RINGQUEUE_H
#define THREADPOOL_RINGQUEUE_H
#include <iostream>
#include <vector>
#include <mutex>
#include <thread>
#include <semaphore>
#include <cstddef>

template <class T>
class RingQueue
{
private:
    void P(std::counting_semaphore<>& sem)
    {
        sem.acquire();
    }

    void V(std::counting_semaphore<>& sem)
    {
        sem.release();
    }
public:
    explicit RingQueue(ptrdiff_t size)
        :_max_size(size)
        ,_sem_p(size)
        ,_sem_c(0)
        ,_tasks(static_cast<long long>(size))
        ,_produce_step(0)
        ,_consume_step(0)
    {}

    // 进队列，预定空间，释放资源
    void Enqueue(const T& task)
    {
        P(_sem_p);
        std::unique_lock<std::mutex> lock(_mutex);
        _tasks[_produce_step++] = task;
        _produce_step %= _max_size;
        lock.unlock();
        V(_sem_c);
    }

    // 出队列，预定任务，释放空间
    void Deque(T* task)
    {
        P(_sem_c);
        std::unique_lock<std::mutex> lock(_mutex);
        *task = _tasks[_consume_step++];
        _consume_step %= _max_size;
        lock.unlock();
        V(_sem_p);
    }

private:
    std::vector<T> _tasks;
    ptrdiff_t _max_size;
    std::counting_semaphore<> _sem_p;
    std::counting_semaphore<> _sem_c;

    std::mutex _mutex;

    int _produce_step;
    int _consume_step;
};

#endif //THREADPOOL_RINGQUEUE_H
