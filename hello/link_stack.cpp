#include <iostream>

#include "link_list.hpp"

class LinkStack{
public:
    LinkStack() :link_stack(nullptr), stack_size(0) {}

    ~LinkStack() {
        free_link_list(link_stack);
    }

    LinkStack(const LinkStack& link_stack) : link_stack(link_stack.link_stack), stack_size(link_stack.stack_size) {}
    LinkStack& operator=(const LinkStack& link_stack) {
        if (this != &link_stack) {
            this->link_stack = link_stack.link_stack;
            this->stack_size = link_stack.stack_size;
        }
        return *this;
    }

    int size() {
        return stack_size;
    }

    int empty() {
        return link_stack == nullptr;
    }

    int top() {
        if (!link_stack) {
            std::cout << "link stack is empty" << std::endl;
            return -1;
        }

        return link_stack->val;
    }

    void push(int val) {
        ListNode* node = new ListNode(val);

        node->next = link_stack;
        link_stack = node;

        ++stack_size;
    }

    int pop() {
        if (empty()) {
            std::cout << "link stack is empty" << std::endl;
            return -1;
        }
        int val = top();

        ListNode* p = link_stack;
        link_stack = link_stack->next;
        delete p;

        --stack_size;
        return val;
    }

    void print() {
        ListNode* p = link_stack;
        while (p) {
            std::cout << p->val << " ";
            p = p->next;
        }
        std::cout << std::endl;
    }

private:
    ListNode* link_stack;
    int stack_size;
};

void test_link_stack() {
    log_func_info(__FILE__, __LINE__, __func__);
    LinkStack link_stack;
    link_stack.push(1);
    link_stack.push(2);
    link_stack.push(3);
    link_stack.push(4);
    link_stack.push(5);
    std::cout << "link stack size: " << link_stack.size() << std::endl;
    link_stack.print();
    std::cout << std::endl;
    std::cout << "link stack top: " << link_stack.top() << std::endl;
    std::cout << std::endl;
    std::cout << "link stack pop: " << link_stack.pop() << std::endl;
    std::cout << std::endl;
    std::cout << "link stack size: " << link_stack.size() << std::endl;
    link_stack.print();

}

