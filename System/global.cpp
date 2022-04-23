#include "System.h"

// temporary Student and Staff

using namespace std;

int main()
{
    loadAccounts();
    while (loginScreen());
    saveAccounts();

    return 0;
}
