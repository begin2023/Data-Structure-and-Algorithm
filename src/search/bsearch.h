#include <cstddef>


namespace Search {
template <typename T = int>
int Bsearch(T data[], size_t len, T target)
{
    if (len == 0) {
        return -1;
    }

    size_t head = 0;
    size_t tail = len - 1;
    while (head <= tail) {
        size_t pos = (head + tail) / 2;
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

template <typename T>
int BsearchByRecur(T data[], size_t len);
}   // namespace Search