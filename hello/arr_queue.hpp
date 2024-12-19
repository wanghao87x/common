#include <iostream>
#include <vector>
#include "utils.hpp"

class ArrayQueue {
public:
    ArrayQueue() :front_index(0), queue_size(0) {}
    ArrayQueue(const ArrayQueue& arr_queue) :queue(arr_queue.queue), queue_size(arr_queue.queue_size) {}
    ArrayQueue& operator=(const ArrayQueue& arr_queue) {
        if (this != &arr_queue) {
            this->queue = arr_queue.queue;
            this->queue_size = arr_queue.queue_size;
        }

        return *this;
    }
    ~ArrayQueue() {}

    int size() {
        return queue_size;
    }

    bool empty() {
        return queue_size == 0;
    }

    int front() {
        if (empty()) {
            std::cout << "array queue is empty" << std::endl;
            return -1;
        }
        return queue[front_index];
    }

    void push(int val) {
        this->queue.push_back(val);
        ++queue_size;
    }

    int pop() {
        if (empty()) {
            std::cout << "array queue is empty" << std::endl;
            return -1;
        }

        int val = front();
        ++front_index;
        --queue_size;
        return val;
    }

    void print() {
        for (size_t i = front_index; i < queue.size(); ++i) {
            std::cout << queue[i] << " ";
        }
        std::cout << std::endl;
    }

private:
    std::vector<int> queue;
    int front_index{};
    int queue_size{};
};

void test_array_queue() {
    log_func_info(__FILE__, __LINE__, __func__);
    ArrayQueue queue;
    queue.push(1);
    queue.push(2);
    queue.push(3);
    std::cout << "array queue size: " << queue.size() << std::endl;
    queue.print();

    while (!queue.empty()) {
        std::cout << queue.front() << " ";
        queue.pop();
    }
    std::cout << std::endl;
    queue.print();

    queue.pop();
}

