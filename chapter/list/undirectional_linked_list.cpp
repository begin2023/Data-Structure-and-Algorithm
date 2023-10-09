// 单项链表，包括头插，尾插，带头结点，不带头结点，指定值增删改节点，指定地址增删改节点

template <typename T>
struct UList {
    T data;
    UList<T>* next;
};

// 头插法建立链表
template <typename T, size_t N>
void EstByHead(T* datas) noexcept
{

}