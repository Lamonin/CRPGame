#ifndef CRPGAME_BILIST_H
#define CRPGAME_BILIST_H

#include <iostream>

using namespace std;

template <typename T>
class bilist {
private:
    class node
    {
    public:
        T value;
        node* left;
        node* right;
        explicit node(T val = T()):value(val) { left = right = nullptr;}
    };

    node* find_by_index(int index)
    {
        node* current = head;
        size_t counter = 0;
        if (index <= list_size / 2){
            do {
                if (counter++ == index) break;
                current = current->right;
            } while (current != tail);
        }
        else {
            current = tail;
            counter = list_size;
            do {
                if (--counter == index) break;
                current = current->left;
            } while (current != head);
        }
        return current;
    }

    node* head;
    node* tail;
    size_t list_size;

public:
    template <bool isConst>
    class bilist_iterator
    {
        friend class bilist_iterator<!isConst>;
        using node_pointer = std::conditional_t<isConst, const node*, node*>;
        node_pointer ptr;

    public:
        explicit bilist_iterator(node_pointer p):ptr(p) { }

        using difference_type = std::ptrdiff_t;
        using value_type = T;
        using pointer = std::conditional_t<isConst, const T*, T*>;
        using reference = std::conditional_t<isConst, const T&, T&>;
        using iterator_category = std::bidirectional_iterator_tag;

        reference operator*() const { return ptr->value; }

        auto& operator++() {
            if (ptr == nullptr || ptr->right == nullptr) return *this;
            ptr = ptr->right; return *this;
        }

        auto operator++(int) {
            if (ptr == nullptr || ptr->right == nullptr) return *this;
            auto result = *this; ++*this; return result;
        }

        auto& operator--() {
            if (ptr == nullptr || ptr->left == nullptr) return *this;
            ptr = ptr->left; return *this;
        }

        auto operator--(int) {
            if (ptr == nullptr || ptr->left == nullptr) return *this;
            auto result = *this; --*this; return result;
        }

        template<bool R>
        bool operator==(const bilist_iterator<R>& it) const { return ptr == it.ptr; }

        template<bool R>
        bool operator!=(const bilist_iterator<R>& it) const { return ptr != it.ptr; }

        operator bilist_iterator<true>() const { return bilist_iterator<true>(ptr); }
    };

    using iterator = bilist_iterator<false>;
    using const_iterator = bilist_iterator<true>;

    bilist(): list_size(0), head(nullptr), tail(nullptr) { }
    bilist(initializer_list<T> init_list):list_size(0), head(0), tail(0) { push_back(init_list); }
    ~bilist(){ clear(); }

    void push_back(T value);
    void push_back(initializer_list<T> values);
    void removeAt(size_t index);

    void pop_front();
    void pop_back();
    void clear();

    iterator begin() { return iterator(head); }
    iterator end() { return iterator(tail == nullptr ? nullptr : tail->right); }
    const_iterator cbegin() const { return const_iterator(head); }
    const_iterator cend() const { return const_iterator(tail == nullptr ? nullptr : tail->right); }

    size_t size() const { return list_size; }

    T& operator[](size_t index);

    void cout_list()
    {
        if (head == nullptr) return;
        node* temp = head;
        do {
            cout << temp->value << " ";
            temp = temp->right;
        } while (temp != tail->right);
        cout << endl;
    }
};

template<typename T>
void bilist<T>::push_back(T value)
{
    if (head == nullptr) {
        head = tail = new node(value);
        tail->right = new node(); //Fictive element
        tail->right->left = tail;
    }
    else {
        node* temp = tail->right;
        tail->right = new node(value);
        tail->right->left = tail;
        tail = tail->right;

        tail->right = temp; //Move fictive element
        tail->right->left = tail;
    }
    ++list_size;
}

template<typename T>
void bilist<T>::push_back(initializer_list<T> values) {
    for (auto elem : values)  {
        push_back(elem);
    }
}

template<typename T>
void bilist<T>::pop_front() {
    if (head == nullptr) return;
    if (list_size == 1)
    {
        delete tail->right;
        delete head;
        head = tail = nullptr;
    }
    else
    {
        node* temp = head;
        head = head->right;
        head->left = nullptr;
        delete temp;
    }
    --list_size;
}

template<typename T>
void bilist<T>::pop_back() {
    if (head == nullptr) return;
    if (list_size == 1) pop_front();
    else
    {
        node* temp = tail;
        tail = tail->left;
        tail->right = temp->right;
        temp->right->left = tail;
        delete temp;
    }
    --list_size;
}

template<typename T>
void bilist<T>::clear() { while(list_size) pop_front(); }

template<typename T>
T& bilist<T>::operator[](const size_t index) {
    assert(!(index < 0 || index >= list_size) && "Index out of bounds!");
    return find_by_index(index)->value;
}

template<typename T>
void bilist<T>::removeAt(size_t index) {
    if (index < 0 || index >= list_size) return;

    if (index == 0) pop_front();
    else if (index == list_size-1) pop_back();
    else
    {
        node* temp = find_by_index(index);
        temp->left->right = temp->right;
        temp->right->left = temp->left;
        delete temp;
    }
    --list_size;
}



#endif //CRPGAME_BILIST_H
