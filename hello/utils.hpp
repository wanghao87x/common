#ifndef UTILS_HPP
#define UTILS_HPP

#include <iostream>

template <typename T, std::size_t N>
void print_array(const T (&array)[N]) {
    std::cout << "[";
    for (std::size_t i = 0; i < N; ++i) {
        std::cout << array[i];
        if (i < N - 1) {
            std::cout << ", ";
        }
    }
    std::cout << "]" << std::endl;
}

inline void log_func_info(const char* filename, int line, const char* func_name) {
    std::cout << "[LOG_FUNC_INFO] in " << filename << ":" << line << " " << func_name << std::endl;
}

#endif
