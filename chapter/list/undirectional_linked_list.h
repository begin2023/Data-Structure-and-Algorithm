// 单项链表，包括头插，尾插，带头结点，不带头结点，指定值增删改节点，指定地址增删改节点

#ifndef UNDIRECTIONAL_LINKED_LIST_H
#define UNDIRECTIONAL_LINKED_LIST_H

#include <cstddef>
#include <string>
#include <type_traits>
#include <iostream>
#include <typeinfo>
#include <vector>

namespace List {
template <typename T>
struct Node {
    T data;
    Node *next;
};

// 尾插法
template <typename T>
class TailList {
public:
    TailList() noexcept
    {
        headNode_ = new Node<T>();
        headNode_->next = nullptr;
        size_ = 0;
    }

    ~TailList() noexcept
    {
        while (headNode_ != nullptr) {
            auto p = headNode_;
            headNode_ = headNode_->next;
            delete p;
            p = nullptr;
        }
    }

    TailList(std::vector<T> &t) noexcept : TailList()
    {
        auto p = headNode_;
        for (auto val : t) {
            Node<T> *newNode = new Node<T>();
            newNode->data = val;
            newNode->next = nullptr;
            p->next = newNode;
            p = newNode;
            size_++;
        }
    }

    auto Size() const noexcept -> size_t
    {
        return size_;
    }

    auto Empty() const noexcept -> bool
    {
        return (size_ == 0U);
    }

    auto PushFront(T t) noexcept -> bool
    {
        auto p = new Node<T>();
        if (p == nullptr) {
            return false;
        }
        p->data = t;
        p->next = headNode_->next;
        headNode_->next = p;
        size_++;
        return true;
    }

    auto PushBack(T t) noexcept -> bool
    {
        auto p = headNode_;
        while (p->next != nullptr) {
            p = p->next;
        }
        Node<T> *q = new Node<T>();
        if (p == nullptr) {
            return false;
        }

        q->data = t;
        q->next = nullptr;
        p->next = q;
        size_++;
        return true;
    }

    auto Insert(T t, size_t pos) noexcept -> bool
    {
        if (pos >= size_) {
            return false;
        }

        auto p = headNode_;
        while (pos > 0) {
            p = p->next;
            pos--;
        }
        Node<T> *q = new Node<T>();
        if (p == nullptr) {
            return false;
        }
        q->data = t;
        q->next = p->next;
        p->next = q;
        size_++;
        return true;
    }

    auto Remove(T t) noexcept -> bool
    {
        if (Empty()) {
            return false;
        }
        auto p = headNode_;
        while (p->next != nullptr) {
            if (p->next->data == t) {
                auto q = p->next;
                p->next = q->next;
                delete q;
                q = nullptr;
                size_--;
                return true;
            }
            p = p->next;
        }
        return false;
    }

    auto PopFront() noexcept -> T
    {
        if (Empty()) {
            return T();
        }
        auto p = headNode_->next;
        auto res = p->data;
        headNode_->next = p->next;
        delete p;
        p = nullptr;
        size_--;
        return res;
    }

    auto PopBack() noexcept -> T
    {
        if (Empty()) {
            return T();
        }

        auto p = headNode_;
        while (p->next->next != nullptr) {
            p = p->next;
        }
        auto q = p->next;
        auto res = q->data;
        delete q;
        q = nullptr;
        p->next = nullptr;
        size_--;
        return res;
    }

    auto GetNodeByPos(size_t pos) noexcept -> T
    {
        if (pos >= size_) {
            return T();
        }
        auto p = headNode_->next;
        while (pos > 0) {
            p = p->next;
            pos--;
        }
        return p->data;
    }

    void ToString() noexcept
    {
        if (!(std::is_arithmetic_v<T> || std::is_same_v<T, std::string>)) {
            std::cerr << "Type " << typeid(T).name() << " can not print!" << std::endl;
            return;
        }
        if (Empty()) {
            std::cerr << "Empty list!" << std::endl;
            return;
        }
        auto p = headNode_->next;
        while (p->next != nullptr) {
            std::cout << std::to_string(p->data) << " ";
            p = p->next;
        }
        std::cout << std::to_string(p->data) << std::endl;
    }

private:
    Node<T> *headNode_;
    size_t size_;
};
}  // namespace List
#endif