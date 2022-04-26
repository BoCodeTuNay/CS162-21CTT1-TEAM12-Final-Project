#include "System.h"

// temporary Student and Staff

using namespace std;

int main()
{
    loadAccounts();
    load_data();

    while (loginScreen());
    
    saveAccounts();
    save_data();

    return 0;
}
