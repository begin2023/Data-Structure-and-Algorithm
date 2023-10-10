// 单项链表，包括头插，尾插，带头结点，不带头结点，指定值增删改节点，指定地址增删改节点

#ifndef UNDIRECTIONAL_LINKED_LIST_H
#define UNDIRECTIONAL_LINKED_LIST_H

#include <cstddef>

template <typename T>
struct Node {
    T data;
    Node *next;
};

// 尾插法
template <typename T, size_t N>
class TailList {
public:
    TailList() : headNode_(null), size_(0)
    {}

    ~TailList()
    {}

    TailList(T t[N])
    {
        head = new Node();
        Node *L = head;
        for (auto val : t) {
            Node *newNode = new Node();
            newNode->data = val;
            newNode->next = null;
            L->next = newNode;
            L = newNode;
        }
    }

    auto GetList() noexcept -> (Node *)&
    {
        return headNode_;
    }

    auto Size() noexcept -> size_t
    {
        return size_;
    }

    auto InsertFront(T t) noexcept -> bool
    {}

    auto InsertBack(T t) noexcept -> bool
    {}

    auto InsertPos(T t, size_t pos) noexcept -> bool
    {}

    auto RemoveByNode(Node *node) noexcept -> bool
    {}

    auto RemoveByValue(T t) noexcept -> bool
    {}

private:
    Node<T> *headNode_;
    size_t size_;
};
#endif