//
// Created by mazez on 27.03.2022.
//

#ifndef CRPGAME_DOUBLELIST_H
#define CRPGAME_DOUBLELIST_H

#include <iostream>
using namespace std;

template <typename T>
class doublelist {
private:
    class node
    {
    public:
        T value;
        node* left;
        node* right;
        explicit node(T val):value(val) { left = right = nullptr;}
        node& operator++() { return right; }
        node& operator--() { return left; }
    };
    friend bool operator==(const node& n1, const node& n2) { return n1.value == n2.value;}
    friend bool operator!=(const node& n1, const node& n2) { return !(n1==n2); }

    void insert_node_between(node* n, node* n1, node* n2)
    {
        n1->right = n2->left = n;
        n->left = n1;
        n->right = n2;
    }

    size_t size;
    node* head;

public:
    class iterator{
        typedef T value_type;
        typedef T* pointer;
        typedef T& reference;
        typedef std::bidirectional_iterator_tag iterator_category;
    };

    doublelist():size(0), head(nullptr) { }
    ~doublelist(){ clear(); }
    void push_back(T value);
    void pop_front();
    void clear();
    size_t get_size() { return size; }

    T& operator[](size_t index);


    void compare()
    {
        cout << "BAR" << endl;
        if (head == head->right)
        {
            cout <<"FOO!";
        }
    }

    void write_list()
    {
        if (head == nullptr) return;
        node* temp = head;
        do {
            cout << temp->value << " ";
            temp = temp->right;
        } while (temp != head);
    }
};

template<typename T>
void doublelist<T>::push_back(T value)
{
    if (head == nullptr) {
        head = new node(value);
        insert_node_between(head, head, head);
        node* fictive = new node(T());
        insert_node_between(fictive, head, head);
    }
    else {

        node* current = head;

        while (current->right != head->left) current = current->right;
        insert_node_between(new node(value), head->left->left, head->left);
    }
    size++;
}

template<typename T>
void doublelist<T>::pop_front() {
    if (head == nullptr) return;
    if (size == 1)
    {
        delete head;
        head = nullptr;
    }
    else
    {
        node* temp = head;
        head->right->left = head->left;
        head->left->right = head->right;
        head = head->right;
        delete temp;
    }
    size--;
}

template<typename T>
void doublelist<T>::clear() { while(size) pop_front(); }

template<typename T>
T& doublelist<T>::operator[](const size_t index) {
    assert(!(index < 0 || index >= size));

    node* current = head;
    size_t counter = 0;
    if (index <= size / 2){
        do {
            if (counter++ == index) return current->value;
            current = current->right;
        } while (current != head);
    }
    else {
        counter = size;
        do {
            if (counter-- == index) return current->value;
            current = current->left;
        } while (current != head);
    }
}

#endif //CRPGAME_DOUBLELIST_H
