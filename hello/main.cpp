#include "arr.cpp"
#include "link_list.hpp"
#include "arr_stack.hpp"
#include "link_stack.cpp"
#include "arr_queue.hpp"
#include "link_queue.hpp"
#include "array_hash_map.hpp"

int main() {
    test_arr();
    test_link_list();

    test_array_stack();
    test_link_stack();

    test_array_queue();
    test_link_queue();

    test_hashmap();

    return 0;
}