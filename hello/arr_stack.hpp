#ifndef ARRAY_STACK_HPP
#define ARRAY_STACK_HPP

#include <vector>
#include <iostream>
#include "utils.hpp"

class ArrayStack {
public:
    ArrayStack() = default;
    
    ~ArrayStack() {}

    ArrayStack(const ArrayStack& arr_stack) :stack(arr_stack.stack) {}

    ArrayStack& operator=(const ArrayStack& arr_stack) {
        if (this != &arr_stack) {
            stack = arr_stack.stack;
        }
        return *this;
    }

    void push(int val) {
        stack.push_back(val);
    }

    int top() {
        if (empty()) {
            std::cout << "stack is empty" << std::endl;
            return -1;
        }
        return stack.back();
    }

    int pop() {
        if (empty()) {
            std::cout << "stack is empty" << std::endl;
            return -1;
        }
        int val = stack.back();
        stack.pop_back();
        return val;
    }

    int size() {
        // return stack.size();
        return stack.end() - stack.begin();
    }

    bool empty() {
        return stack.begin() == stack.end();
    }

    void print() {
        for (auto it = stack.begin(); it != stack.end(); ++it) {
            std::cout << *it << " ";
        }
        std::cout << std::endl;
    }

private:
    std::vector<int> stack;
};

void test_array_stack() {
    log_func_info(__FILE__, __LINE__, __func__);

    ArrayStack stack;
    stack.push(1);
    stack.push(2);

    std::cout << "cur stack size: " << stack.size() << std::endl;
    stack.print();
    std::cout << "pop: " << stack.pop() << std::endl;
    stack.push(3);
    std::cout << "cur stack size: " << stack.size() << std::endl;
    stack.print();

    std::cout << "pop: " << stack.pop() << std::endl;
    std::cout << "pop: " << stack.pop() << std::endl;
    std::cout << "pop: " << stack.pop() << std::endl;
    std::cout << "pop: " << stack.pop() << std::endl;

}

#endif
