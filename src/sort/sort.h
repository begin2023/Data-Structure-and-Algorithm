#ifndef SORT_H
#define SORT_H

#include <cstddef>

namespace Sort {
template <typename T = int>
void BubbleSort(T* data, size_t len)
{
    if (len == 0U) {
        return;
    }

    for (size_t i = 0U; i < len - 1; i++) {
        for (size_t j = i + 1; j < len; j++) {
            if (data[i] > data[j]) {
                T tmp = data[i];
                data[i] = data[j];
                data[j] = tmp;
            }
        }
    }
}
}   // namespace Sort

#endif