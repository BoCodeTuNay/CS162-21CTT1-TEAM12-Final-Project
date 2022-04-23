#include "Account.h"

Account::Account(const char* _ID, const char* _password, const char* _name, const char* _email, const char* _socialID)
{
    strcpy(ID, _ID);
    strcpy(password, _password);
    strcpy(name, _name);
    strcpy(email, _email);
    strcpy(socialID, _socialID);
}

void Account::view()
{
    char ID[MAXID+1]; //21125xxx
    char password[MAXSTR+1];

    char firstName[MAXNAME+1];
    char lastName[MAXNAME+1];
    bool gender; // male: 1, female: 0
    Date DOB; // day of birth
    char socialID[MAXID]; //xxxxxxxx

    cout << "ID: " << ID << '\n';
    cout << "firstname: " << firstName << "\n";
    cout << "lastname: " << lastName << "\n";
    cout << "gender (male: 1, female: 0): " << gender << "\n";
    cout << DOB.day << "/" << DOB.month << "/" << DOB.year << "\n";
    cout << "socialID: " << socialID << "\n";
}

void importFromCSV(fstream &fin)
{
    
}