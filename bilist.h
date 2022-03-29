//
// Created by mazez on 27.03.2022.
//

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

    size_t list_size;
    node* head;
    node* tail;

public:
    template <bool isConst>
    class bilist_iterator
    {
        using node_pointer = std::conditional<isConst, const node*, node*>;
        node_pointer ptr;

    public:
        explicit bilist_iterator(node_pointer p):ptr(p) { }

        using difference_type = std::ptrdiff_t;
        using value_type = T;
        using pointer = std::conditional<isConst, const T*, T*>;
        using reference = std::conditional<isConst, const T&, T&>;
        using iterator_category = std::bidirectional_iterator_tag;

        reference operator*() const { return ptr->value; }
        auto& operator++() {
            if (ptr == nullptr || ptr->right->right == nullptr) return *this;
            ptr = ptr->right; return *this;
        }

        auto operator++(int)
        {
            if (ptr == nullptr || ptr->right->right == nullptr) return *this;
            auto result = *this; ++*this; return result;
        }

        auto& operator--() {
            if (ptr == nullptr || ptr->left== nullptr) return *this;
            ptr = ptr->left; return *this;
        }

        auto operator--(int)
        {
            if (ptr == nullptr || ptr->left == nullptr) return *this;
            auto result = *this; --*this; return result;
        }

        template<bool R>
        bool operator==(const bilist_iterator<R>& it) const { return ptr == it.ptr; }

        template<bool R>
        bool operator!=(const bilist_iterator<R>& it) const { return ptr != it.ptr; }

        operator bilist_iterator<true>() const { return bilist_iterator<true>(ptr); }
    };

    class const_iterator;

    class iterator{
        using node_pointer = node*;
        node_pointer ptr;
    public:
        using difference_type = std::ptrdiff_t;
        using value_type = T;
        using pointer = T*;
        using reference = T&;
        using iterator_category = std::bidirectional_iterator_tag;

        explicit iterator(node_pointer p):ptr(p) { }

        reference operator*() const { return ptr->value; }
        iterator& operator++() { ptr = ptr->right; return *this; }
        iterator operator++(int) { iterator result = *this; ++*this; return result; }
        iterator& operator--() { ptr = ptr->left; return *this; }
        iterator operator--(int) { iterator result = *this; --*this; return result; }

        bool operator==(const iterator& c_iter) const { return ptr == c_iter.ptr; }
        bool operator!=(const iterator& c_iter) const { return ptr != c_iter.ptr; }

        bool operator==(const const_iterator& c_iter) const { return ptr == c_iter.ptr; }
        bool operator!=(const const_iterator& c_iter) const { return ptr != c_iter.ptr; }

        operator const_iterator() const { return const_iterator(ptr); } //Implicit transformation
    };

    class const_iterator{
        using node_pointer = const node*;
        node_pointer ptr;

    public:
        using difference_type = std::ptrdiff_t;
        using value_type = T;
        using pointer = const T*;
        using reference = const T&;
        using iterator_category = std::bidirectional_iterator_tag;

        explicit const_iterator(node_pointer p):ptr(p) { }

        reference operator*() const { return ptr->value; }
        const_iterator& operator++() {
            if (ptr == nullptr || ptr->right->right == nullptr) return *this; //If node is not exist, or next node is fictive
            ptr = ptr->right; return *this;
        }
        const_iterator operator++(int) {
            if (ptr == nullptr || ptr->right->right == nullptr) return *this; //If node is not exist, or next node is fictive
            const_iterator result = *this;
            ++*this; return result;
        }
        const_iterator& operator--() { ptr = ptr->left; return *this; }
        const_iterator operator--(int) { const_iterator result = *this; --*this; return result; }

        bool operator==(const const_iterator& c_iter) const { return this->ptr == c_iter.ptr; }
        bool operator!=(const const_iterator& c_iter) const { return this->ptr != c_iter.ptr; }
    };

    bilist(): list_size(0), head(nullptr), tail(nullptr) { }
    ~bilist(){ clear(); }

    void push_back(T value);
    void pop_front();
    void clear();

    iterator begin() { return iterator(head); }
    iterator end() { return iterator(tail== nullptr ? nullptr : tail->right); }
    const_iterator cbegin() const { return const_iterator(head); }
    const_iterator cend() const { return const_iterator(tail== nullptr ? nullptr : tail->right); }

    size_t size() const { return list_size; }

    T& operator[](size_t index);

    void write_list()
    {
        if (head == nullptr) return;
        node* temp = head;
        do {
            cout << temp->value << " ";
            temp = temp->right;
        } while (temp != nullptr);
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
    list_size++;
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
    list_size--;
}

template<typename T>
void bilist<T>::clear() { while(list_size) pop_front(); }

template<typename T>
T& bilist<T>::operator[](const size_t index) {
    assert(!(index < 0 || index >= list_size) && "Index out of bounds!");

    node* current = head;
    size_t counter = 0;
    if (index <= list_size / 2){
        do {
            if (counter++ == index) return current->value;
            current = current->right;
        } while (current != tail);
    }
    else {
        current = tail;
        counter = list_size;
        do {
            if (--counter == index) return current->value;
            current = current->left;
        } while (current != head);
    }
}

#endif //CRPGAME_BILIST_H
