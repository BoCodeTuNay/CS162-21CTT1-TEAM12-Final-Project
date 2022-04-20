/*
How to use?
1. Khai báo: List<kiểu dữ liệu> tên;
VD: List<Student> A;
2. Duyệt:
for(Node<kiểu dữ liệu>* p = A.begin(); p; p = p->pNext) {

}
3. Thêm: A.insert(<biến thuộc kiểu dữ liệu>);
4. Xóa: A.remove(<biến thuộc kiểu dữ liệu mà cần xóa>, <hàm so sánh>);
-> Hàm so sánh (kiểu trả về luôn là bool) dùng để định nghĩa lại toán tử so sánh (==) cho kiểu dữ liệu tự định nghĩa (struct).
5. Số lượng node trong List hiện tại: <tên biến List>.size();

Lưu ý: Vì đã có cơ chế tự hủy (Destructor) nên mọi con trỏ đều sẽ được tự động giải phóng.

Code mẫu: https://ideone.com/Irn5C8
*/

#pragma once
#include <iostream>

template <typename T>
struct Node {
    T data;
    Node<T>* pNext{nullptr};
};

template <typename T>
class List {
private:
    Node<T>* pHead;
    Node<T>* pTail;
    unsigned int sz{0};
public:
    List();
    ~List();
    // the first node of the list
    Node<T>* const begin();
    // the current number of nodes in the list
    unsigned int size();
    // insert a new element as the last node in the list, return true/false whether the insertion succeeds
    bool insert(const T&);
    // remove a given element from the list (the first one found), return true/false whether the removal succeeds
    bool remove(const T&, bool (*cmp)(const T&, const T&));
    bool rmv(const T& mem);
    // return value on the given index, return nullptr if the index is out of range
    T& get(unsigned int);
    int indexOf(const T&);
    bool search(const T&);
};
#include "List.cpp"
