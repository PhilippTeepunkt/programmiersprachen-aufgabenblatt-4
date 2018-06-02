#ifndef BUW_LIST_HPP
#define BUW_LIST_HPP

#include<cstddef>

template <typename T>
class List;

template <typename T>
struct ListNode
{
    T value = T();
    ListNode* prev = nullptr;
    ListNode* next = nullptr;
};

template<typename T>
class ListIterator
{
    public:

    private:
        ListNode<T>* node;
};

template <typename T>
class ListConstIterator
{
    public:

    private:
        ListNode<T>* node;
};

template <typename T>
class List
{
    public:
        using value_type = T;
        using pointer = T;
        using const_pointer = T const*;
        using reference = T&;
        using const_reference = T const&;
        using iterator = ListIterator<T>;
        using const_iterator = ListConstIterator<T>;

        List():
            first_{nullptr},
            last_{nullptr},
            size_{0}
        {};

        List(ListNode<T>* first):
            first_{first},
            last_{first},
            size_{1}
        {};

        bool empty()const
        {
            return size_==0;            
        }

        std::size_t size() const
        {
            return size_;
        }

    private:
        std::size_t size_;
        ListNode<T>* first_;
        ListNode<T>* last_;
};
#endif
