#include "List.h"
#include <iostream>

using namespace std;

struct myStruct {
    int a, b;
};

int main()
{
    List<myStruct> myList;
    myList.insert({1, 2});
    myList.insert({2, 3});
    myList.insert({3, 4});
    myList.get(0) = {1, 3};
    for (Node<myStruct>* cur = myList.begin(); cur; cur = cur->pNext) {
        cout << cur->data.a << ' ' << cur->data.b << endl;
    }
    

    return 0;
}