#include <iostream>
#include "link_list.hpp"
#include "utils.hpp"

class LinkQueue {
public:
    LinkQueue() :front(nullptr), rear(nullptr), queue_size(0) {}
    LinkQueue(const LinkQueue& link_queue) 
        :front(link_queue.front), rear(link_queue.rear), queue_size(link_queue.queue_size) {}
    
    LinkQueue& operator=(const LinkQueue& link_queue) {
        if (this != &link_queue) {
            this->front = link_queue.front;
            this->rear = link_queue.rear;
            this->queue_size = link_queue.queue_size;
        }
        return *this;
    }

    ~LinkQueue() {
        free_link_list(front);
    }

    int size() {
        return queue_size;
    }

    bool empty() {
        return queue_size == 0;
    }

    int top() {
        if (empty()) {
            std::cout << "link queue is empty" << std::endl;
            return -1;
        }
        return front->val;
    }

    void push(int val) {
        ListNode* node = new ListNode(val);
        if (empty()) {
            front = node;
            rear = node;
        } else {
            rear->next = node;
            rear = node;
        }
        ++queue_size;
    }

    int pop() {
        if (empty()) {
            std::cout << "link queue is empty" << std::endl;
            return -1;
        }
        int val = top();

        ListNode* t = front;
        front = front->next;
        delete t;
        --queue_size;
        return val;
    }

    void print() {
        ListNode* p = front;
        while (p) {
            std::cout << p->val << " ";
            p = p->next;
        }
        std::cout << std::endl;

    }

private:
    ListNode* front;
    ListNode* rear;
    int queue_size;
};

void test_link_queue() {
    log_func_info(__FILE__, __LINE__, __func__);
    LinkQueue lq;

    for (int i = 0; i < 5; ++i) {
        lq.push(i);
    }
    lq.print();

    for (int i = 0; i < 5; ++i) {
        lq.pop();
    }
    lq.print();

    for (int i = 0; i < 5; ++i) {
        lq.push(i);
    }
    lq.print();

    lq.pop();
    lq.print();

}

