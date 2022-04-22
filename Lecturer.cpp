#include <bits/stdc++.h>

using namespace std;

struct myStruct {
    static vector<int> v;
    int a, b;
};

vector<int> myStruct::v;

int main()
{
    ios::sync_with_stdio(false); cin.tie(0);
    myStruct X;
    X.v.push_back(1);

    myStruct Y;
    Y.v.push_back(2);

    myStruct Z;
    for (int& x : myStruct::v)
        cout << x << endl;

    return 0;
}