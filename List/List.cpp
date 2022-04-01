#include "List.h"

Node<T>* const List::head() {
    return pHead;
}

Node<T>* const List::tail() {
    return pTail;
}

unsigned int List::size() {
    return sz;
}

bool List::insert(const T& new_elem) {
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

bool List::remove(const T& mem, bool (*cmp)(const T&, const T&)) {
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
        for(Node<T>* cur = pHead; cur->pNext; cur = cur->pNext) {
            if (cmp(cur->pNext->data, mem)) {
                if(cur->pNext == pTail) {
                    pTail = cur;
                }
                Node<T> *tmp = cur->pNext;
                cur->pNext = cur->pNext->pNext;
                delete tmp;
                --sz;
                return true;
            }
        }
        return false;
    }
}