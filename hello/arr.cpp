/*************************************************************************
	* File Name: arr.cpp
	* Author: goodwang
	* Created Time: 2024年12月17日 星期二 12时35分48秒
 ************************************************************************/

#include <iostream>
#include "utils.hpp"

#define sizeofarr(arr) (sizeof(arr) / sizeof(arr[0]))

void insert_arr(int nums[], int size, int num, int index) {
    if (index < 0 || index > size) {
        std::cout << "index out of range" << std::endl;
        return;
    }
    
    for (int i = size - 1; i > index; --i) {
        nums[i] = nums[i - 1];
    }
    nums[index] = num;
}

void delete_arr(int nums[], int size, int index) {
    if (index < 0 || index > size) {
        std::cout << "index out of range" << std::endl;
        return;
    }

    for (int i = index; i < size - 1; ++i) {
        nums[i] = nums[i + 1];
    }

    // the last element is not used
    nums[size - 1] = 0;
}

int find_first_arr(int nums[], int size, int target) {

    for (int i = 0; i < size; ++i) {
        if (nums[i] == target) {
            return i;
        }
    }
    return -1;
}

int* extend(int nums[], int size, int enlarge) {
    int* arr = new int[size + enlarge]();

    for (int i = 0; i < size; ++i) {
        arr[i] = nums[i];
    }
    delete[] nums;
    return arr;
}

void test_arr() {
    log_func_info(__FILE__, __LINE__, __func__);
    int nums[10]{0, 1 ,2, 3, 4, 5, 6, 7, 8, 9};

    std::cout << "init arr: ";
    print_array(nums);

    insert_arr(nums, sizeofarr(nums), 99, 3);

    std::cout << "after insert: ";
    print_array(nums);

    delete_arr(nums, sizeofarr(nums), 3);
    std::cout << "after delete: ";
    print_array(nums);

    int target = 5;
    int target_index = find_first_arr(nums, sizeofarr(nums), target);
    if (target_index == -1) {
        std::cout << "not found target: " << target << " in nums" << std::endl;
    } else {
        std::cout << "find target: " << target << " in index: " << target_index << std::endl;
    }

    int* arr = new int[10]{0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    // we cannot use like extend(arr, sizeofarr(arr), 3), because arr is a pointer, not an array
    int* new_arr = extend(arr, 10, 3);

    for (int i = 0; i < 13; ++i) {
        std::cout << *(new_arr + i) << " ";
    }
    std::cout << std::endl;

}

