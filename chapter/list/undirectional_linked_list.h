// 单项链表，包括头插，尾插，带头结点，不带头结点，指定值增删改节点，指定地址增删改节点

#ifndef UNDIRECTIONAL_LINKED_LIST_H
#define UNDIRECTIONAL_LINKED_LIST_H

template <typename T>
struct Node {
    T data;
    Node *next;
};

using NodePtr = Node*;
// 头插法链表
template <typename T, size_t N>
class HeadList {
public:
    HeadList(T t[N])
    {}

    auto GetList() noexcept -> (Node *)&
    {
        return head;
    }

    auto GetSize() noexcept -> size_t
    {
        return size;
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
    Node *head;
    size_t size;
};
#endif