#include <iostream>
#include <cctype>
// #include "List\\List.h"
// #include "Staff.h"
// #include "Student\\Student.h"


using namespace std;
const int MAXSTR = 50;

struct 

// to check whether a given string consists of only alphabet characters and spaces
bool checkName(const char* str)
{
    for (int i = 0; str[i]; ++i) {
        if (!isalpha(str[i]) && str[i] != ' ')
            return false;
    }
    return true;
}

// to check whether a given string consists of only alphabet characters and digits
bool checkAlphaDigit(const char* str)
{
    for (int i = 0; str[i]; ++i) {
        if (!isalpha(str[i]) && !isdigit(str[i]))
            return false;
    }
    return true;
}

void signup()
{
    char name[MAXSTR+1];
    do {
        cin.clear();
        fflush(stdin);
        cout << "Name (max " << MAXSTR << " chars): ";
        cin.get(name, MAXSTR+1, '\n');
    } while (cin.fail() || cin.get() != '\n' || !checkName(name));

    char ID[MAXSTR+1];
    do {
        cin.clear();
        fflush(stdin);
        cout << "ID (max " << MAXSTR << " chars): ";
        cin.get(ID, MAXSTR+1, '\n');
    } while (cin.fail() || cin.get() != '\n' || !checkAlphaDigit(ID));

    char username[MAXSTR+1];
    cout << "Username (max " << MAXSTR << " chars): ";
    cin.get(username, MAXSTR+1, '\n');
    while (cin.fail() || cin.get() != '\n' || !checkAlphaDigit(username)) {
        cin.clear();
        fflush(stdin);
        cout << "Invalid username. Please try again.\n";
        cout << "Username (max " << MAXSTR << " chars): ";
        cin.get(username, MAXSTR+1, '\n');
    }
    
    char password[MAXSTR+1];
    cout << "Password (max " << MAXSTR << " chars): ";
    cin.get(password, MAXSTR+1, '\n');
    while (cin.fail() || cin.get() != '\n' || !checkAlphaDigit(password)) {
        cin.clear();
        fflush(stdin);
        cout << "Invalid password. Please try again.\n";
        cout << "Password (max " << MAXSTR << " chars): ";
        cin.get(password, MAXSTR+1, '\n');
    }
}

void login()
{
    char username[MAXSTR+1];
    cout << "Username (max " << MAXSTR << " chars): ";
    cin.get(username, MAXSTR+1, '\n');
    while (cin.fail() || cin.get() != '\n' || !checkAlphaDigit(username)) {
        cin.clear();
        fflush(stdin);
        cout << "Invalid username. Please try again.\n";
        cout << "Username (max " << MAXSTR << " chars): ";
        cin.get(username, MAXSTR+1, '\n');
    }
    
    char password[MAXSTR+1];
    cout << "Password (max " << MAXSTR << " chars): ";
    cin.get(password, MAXSTR+1, '\n');
    while (cin.fail() || cin.get() != '\n' || !checkAlphaDigit(password)) {
        cin.clear();
        fflush(stdin);
        cout << "Invalid password. Please try again.\n";
        cout << "Password (max " << MAXSTR << " chars): ";
        cin.get(password, MAXSTR+1, '\n');
    }
}

int main()
{
    

    

    return 0;
}