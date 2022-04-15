#include "System.h"
#include "..\List\List.h"

// temporary Student and Staff
List<Student> listStudents;
List<Staff> listStaffs;

using namespace std;

void loginScreen()
{
    clrscr();
    cout << "0. Log in\n";
    cout << "1. Sign up\n";
    cout << "Your choice: ";
    int t = choose(0, 1);
}

int main()
{
    
    return 0;
}