#ifndef LINK_LIST_HPP
#define LINK_LIST_HPP

#include <iostream>
#include "utils.hpp"

struct ListNode {
    int val;
    ListNode* next;

    ListNode() :val(0), next(nullptr) {}
    ListNode(int v) :val(v), next(nullptr) {}
    ListNode(int v, ListNode* p) :val(v), next(p) {}
};

void print_link_list(ListNode* head) {
    ListNode* p = head;
    while (p) {
        std::cout << p->val << " ";
        p = p->next;
    }
    std::cout << std::endl;

}

void free_link_list(ListNode* head) {
    while (head) {
        ListNode* t = head;
        head = head->next;
        delete t;
    }
    std::cout << "link list freed" << std::endl;
}

ListNode* create_link_list(const std::initializer_list<int>& vals) {
    ListNode* head = nullptr;
    ListNode* tail = nullptr;

    for (int val : vals) {
        ListNode* node = new ListNode(val);

        if (!head) {
            head = node;
            tail = node;
        } else {
            // 先把新节点连接到 tail 后面
            tail->next = node;
            // 然后更新 tail 为新节点
            tail = node;
        }
    }
    return head;
}

// insert
void insert_list_node(ListNode* head, int pos, int val) {
    ListNode* p = head;

    for (int i = 0; i < pos - 1; ++i) {
        p = p->next;
    }

    ListNode* node = new ListNode(val);
    node->next = p->next;
    p->next = node;
}

void remove_list_node(ListNode* head, int pos) {
    ListNode* p = head;
    for (int i = 0; i < pos - 1; ++i) {
        p = p->next;
    }

    ListNode* t = p->next;
    p->next = t->next;

    delete t;
}

ListNode* access_list_node(ListNode* head, int pos) {
    ListNode* p = head;

    for (int i = 0; i < pos; ++i) {
        if (!p) {
            return nullptr;
        }
        p = p->next;
    }
    return p;
}

int find_list_node(ListNode* head, int target) {
    int index = 0;
    ListNode* p = head;

    while (p) {
        if (p->val == target) {
            return index;
        }
        p = p->next;
        ++index;
    }
    return -1;
}


void test_link_list() {
    log_func_info(__FILE__, __LINE__, __func__);
    ListNode* head = create_link_list({1, 2, 3, 4, 5});

    std::cout << "create link list: ";
    print_link_list(head);

    insert_list_node(head, 2, 100);
    std::cout << "insert node: ";
    print_link_list(head);

    remove_list_node(head, 2);
    std::cout << "remove node: ";
    print_link_list(head);

    std::cout << "access node 2: " << access_list_node(head, 2)->val << std::endl;

    std::cout << "find node 4 in index: " << find_list_node(head, 4) << std::endl;

    free_link_list(head);
}

#endif
