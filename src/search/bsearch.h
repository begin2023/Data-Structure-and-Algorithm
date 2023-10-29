#include <cstddef>


namespace Search {
template <typename T = int>
auto Bsearch(T data[], size_t len, T target) noexcept -> int
{
    if (len == 0) {
        return -1;
    }

    size_t head = 0;
    size_t tail = len - 1;
    while (head <= tail) {
        size_t pos = head + ((tail - head) >> 1);
        if (data[pos] == target) {
            return pos;
        }
        else if (data[pos] < target) {
            head = pos + 1;
        }
        else {
            tail = pos - 1;
        }
    }
    return -1;
}

template <typename T = int>
auto Recursion(T data[], size_t low, size_t high, T target) noexcept -> int
{
    if (low > high) {
        return -1;
    }
    size_t mid = low + ((high - low) >> 1);
    if (data[mid] == target) {
        return mid;
    }
    else if (data[mid] < target) {
        return Recursion(data, mid + 1, high, target);
    }
    else {
        return Recursion(data, low, mid - 1, target);
    }
}

template <typename T = int>
auto BsearchByRecur(T data[], size_t len, T target) noexcept -> int
{
    if (len == 0) {
        return -1;
    }
    return Recursion(data, 0, len - 1, target);
}
}   // namespace Search