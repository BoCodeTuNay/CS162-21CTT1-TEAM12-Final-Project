#include "System.h"

using namespace std;

int main()
{
    loadAccounts();
    load_data();
    load_students();

    while (loginScreen());
    
    save_students();
    saveAccounts();
    save_data();

    return 0;
}
