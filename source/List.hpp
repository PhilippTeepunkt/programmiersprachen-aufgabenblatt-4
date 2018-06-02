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
        using Self = ListIterator<T>;

        using value_type = T;
        using pointer = T*;
        using reference = T&;
        using difference_type = ptrdiff_t;
        using iterator_category = std::bidirectional_iterator_tag;

        ListIterator():
           node{nullptr} 
        {};

        ListIterator(ListNode<T>* n):
            node{n}
        {};

        reference operator*()const{
            return node->value;
        }

        pointer operator->()const{
            return *node;
        }

        Self& operator ++(){
            node = node->next;
            return *this;
        }

        Self operator ++(int){
            Self it(*this);
            ++(*this);
            return it;
        }

        bool operator ==(Self const& x)const{
            return node == x.node;
        }

        bool operator !=(Self const& x)const{
            return node != x.node;
        }

        Self next()const{
            if(node)
                return ListIterator(node->next);
            else
                return ListIterator(nullptr);
        }

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

        List(List<T> const& list):
            first_{nullptr},
            last_{nullptr},
            size_{0}
        {
            for(auto it = list.begin();it!=list.end();it++)
            {
                push_back(*it);
            }
        };

        ~List()
        {
            clear();
        }
    
    #pragma region Getter

        bool empty()const
        {
            return size_==0;            
        }

        std::size_t size() const
        {
            return size_;
        }

        T front(){

            if(empty())
            {
                std::cout<<"List is empty! Can't return first value";
                return 0;
            }
            return (*first_).value;
        }
        T back(){
            if(empty())
            {
                std::cout<<"List is empty! Can't return last value";
                return 0;
            }
            return last_->value;
        }

    #pragma endregion        
        
    #pragma region ModifireMethods
        void push_front(T const data){
            ListNode<T>* node = new ListNode<T>;
            (*node).value = data;

            if(!empty())
            {
                (*first_).prev = node;
                (*node).next = first_;
            }
            else
            {
                last_ = node;
            }
            first_ = node;
            size_++;
            node = nullptr; 
        }

        void push_back(T const data){
            ListNode<T>* node = new ListNode<T>;
            (*node).value = data;

            if(!empty())
            {
                (*last_).next = node;
                (*node).prev = last_;                
            }
            else
            {   
                first_= node;   
            }
            last_ = node;
            size_++;
            node = nullptr;
        }

        void pop_front(){
            if(!empty())
            {
                ListNode<T>* del = first_;
                first_=(*first_).next;
                (*first_).prev = nullptr;
                delete del;
                del = nullptr;
                size_--;
            }
            else
            {
                std::cout<<"Can't remove first elment, because the list is already empty!";
            }
        }

        void pop_back(){

            if(!empty())
            {
                ListNode<T>* del = last_; 
                last_=(*last_).prev;
                if(last_!=nullptr)
                {
                    (*last_).next = nullptr;
                }
                delete del;
                del = nullptr;
                size_--;
            }
            else
            {
                std::cout<<"Can't remove last elment, because the list is already empty!";
            }
        }

        void clear()
        {
            while(!empty())
            {
                pop_back();
            }
            std::cout<<"List is now empty.";
        }

    #pragma endregion 

    ListIterator<T> begin()const
    {
        return ListIterator<T>{first_};
    }

    ListIterator<T> end()const
    {
        return ListIterator<T>{last_}.next();
    }

    private:
        std::size_t size_;
        ListNode<T>* first_;
        ListNode<T>* last_;
};

template<typename T>
bool operator ==(List<T>const& xs,List<T>const& ys)
{
    if(xs.size()!=ys.size())
    {
        return false;
    }
    
    ListIterator<T> xIt = xs.begin();
    ListIterator<T> yIt = ys.begin();
    while(xIt!=xs.end())
    {
        if(*xIt!=*yIt){
            return false;
        }
        xIt++;
        yIt++;
    }

    return true;
}

template<typename T>
bool operator !=(List<T> const& xs, List<T> const& ys)
{
    return !(xs==ys);
}
#endif
