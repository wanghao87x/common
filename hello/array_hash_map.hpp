#include <iostream>
#include <vector>
#include "utils.hpp"

struct Pair {
    int key;
    std::string val;

    Pair(int k, std::string v) : key(k), val(v) {}
};

class Hashmap {
public:
    Hashmap() {
        buckets = std::vector<Pair*>(100);
    }
    ~Hashmap() {
        for (const auto& bucket : buckets) {
            delete bucket;
        }
        buckets.clear();
    }

    std::string get(int key) {
        int index = hash_func(key);

        Pair* pair = buckets[index];

        if (pair) {
            return pair->val;
        }
        return "";
    }

    void put(int key, std::string val) {
        Pair* pair = new Pair(key, val);

        int index = hash_func(key);

        buckets[index] = pair;
    }

    void remove(int key) {
        int index = hash_func(key);

        Pair* pair = buckets[index];

        if (pair) {
            delete pair;
        }
        buckets[index] = nullptr;
    }

    void print() {
        for (const auto& bucket : buckets) {
            if (bucket) {
                std::cout << bucket->key << " : " << bucket->val << std::endl;
            }
        }
    }

private:
    int hash_func(int val) {
        return val % 100;
    }

    std::vector<Pair*> buckets;
};

void test_hashmap() {
    log_func_info(__FILE__, __LINE__, __func__);
    Hashmap* hashmap = new Hashmap();

    hashmap->put(1, "one");
    hashmap->put(2, "two");
    hashmap->print();
    std::cout << hashmap->get(1) << std::endl;
    std::cout << hashmap->get(2) << std::endl;
    hashmap->remove(1);
    hashmap->print();
    delete hashmap;
}
