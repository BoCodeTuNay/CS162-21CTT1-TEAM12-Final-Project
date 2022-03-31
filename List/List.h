#pragma once
#include <iostream>

template <typename T>
struct Node {
    T key;
    Node<T>* pNext{nullptr};
};

template <typename T>
class List {
private:
    Node<T>* pHead;
    Node<T>* pTail;
    unsigned int sz = 0;
public:
    List() {
        pHead = nullptr;
        pTail = nullptr;
    };
    // the first node of the list
    Node<T>* const head();
    // the last node of the list
    Node<T>* const tail();
    // the current number of nodes in the list
    unsigned int size();
    // insert a new element as the last node in the list, return true/false whether the insertion succeeds
    bool insert(const T&);
    // remove a given element from the list (the first one found), return true/false whether the removal succeeds
    bool remove(const T&, bool (*cmp)(const T&, const T&));
};

#include "List.cpp"