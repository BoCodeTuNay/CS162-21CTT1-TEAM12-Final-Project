#include "List.h"

template <typename T>
List<T>::List()
{
    pHead = nullptr;
    pTail = nullptr;
    sz = 0;
}

template <typename T>
List<T>::~List()
{
    Node<T>* cur = pHead;
    while (cur) {
        Node<T>* tmp = cur;
        cur = cur->pNext;
        delete tmp;
    }
    pHead = nullptr;
    pTail = nullptr;
}

template <typename T>
Node<T>* const List<T>::begin() {
    return pHead;
}

template <typename T>
Node<T>* const List<T>::end() {
    return pTail;
}

template <typename T>
unsigned int List<T>::size() {
    return sz;
}

template <typename T>
bool List<T>::insert(const T& new_elem) {
    if (pHead == nullptr) {
        pHead = new Node<T>;
        if (pHead) {
            pHead->data = new_elem;
            pTail = pHead;
            ++sz;
            return true;
        }
        else return false;
    }
    else {
        pTail->pNext = new Node<T>;
        if (pTail->pNext) {
            pTail = pTail->pNext;
            pTail->data = new_elem;
            ++sz;
            return true;
        }
        return false;
    }
}

template <typename T>
bool List<T>::remove(const T& mem, bool (*cmp)(const T&, const T&)) {
    if (cmp(pHead->data, mem)) {
        if (pHead == pTail) {
            delete pHead;
            pHead = nullptr;
            pTail = nullptr;
        }
        else {
            Node<T>* cur = pHead;
            pHead = pHead->pNext;
            delete cur;
        }
        --sz;
        return true;
    }
    else {
        for (Node<T>* cur = pHead; cur->pNext; cur = cur->pNext) {
            if (cmp(cur->pNext->data, mem)) {
                if (cur->pNext == pTail) {
                    pTail = cur;
                }
                Node<T>* tmp = cur->pNext;
                cur->pNext = cur->pNext->pNext;
                delete tmp;
                --sz;
                return true;
            }
        }
        return false;
    }
}

template <typename T>
T& List<T>::get(unsigned int index) {
    Node<T>* cur = pHead;
    for (int i = 0; i < index; ++i) {
        cur = cur->pNext;
    }
    return cur->data;
}

template <typename T>
int List<T>::indexOf(const T& val, bool (*cmp)(const T&, const T&)) {
    int i = 0;
    for (Node<T>* cur = pHead; cur; cur = cur->pNext) {
        if (cmp(cur->data, val)) {
            return i;
        }
        ++i;
    }
    return -1;
}
// if the Node is invalid, the indexOf is -1