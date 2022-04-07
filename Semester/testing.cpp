#include <iostream>
#include "..\List\List.h"

using namespace std;

class Schoolyear {
public:
    int a, b;
    Schoolyear(int _a = 0, int _b = 0) {
        a = _a; b = _b;
    }
    this
};

struct Staff {
    static List<Schoolyear> listCourses;
    void addSY(const Schoolyear& sy) {
        listSY.insert(sy);
    }
    void show() {
        cout << "Schoolyears are:\n";
        for(Node<Schoolyear>* cur = listSY.begin(); cur; cur = cur->pNext) {
            cout << cur->data.a << ' ' << cur->data.b << endl;
        }
    }
};

List<Schoolyear> Staff::listCourses;


int main()
{
    Staff s1;
    s1.addSY(Schoolyear(1, 2));
    s1.addSY(Schoolyear(3, 4));
    s1.show();
    Staff s2;
    s2.addSY(Schoolyear(5, 6));
    s2.addSY(Schoolyear(7, 8));
    s2.show();

    return 0;
}