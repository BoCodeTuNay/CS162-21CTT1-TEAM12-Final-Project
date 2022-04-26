#include "Account.h"

Account::Account(const char* _ID, const char* _password, const char* _name, const char* _email, const char* _socialID)
{
    strcpy(ID, _ID);
    strcpy(password, _password);
    strcpy(name, _name);
    strcpy(email, _email);
    strcpy(socialID, _socialID);
}

void Account::read_data(fstream& fin)
{
    using namespace std;
    if (!fin.is_open()) return;
    std::cerr << "BEGIN TO READ AN ACCOUNT" << std::endl;
    (fin >> ID >> password).get();
    //fin.ignore(); // eat the enter
    fin.get(name, MAXNAME+1, '\n').get();
    fin.get(email, MAXSTR+1, '\n').get();
    fin.get(socialID, MAXSTR+1, '\n').get();
    std::cerr << "What been read are:" << std::endl;
    std::cerr << ID << std::endl << password << std::endl << name << std::endl << email << std::endl << socialID << std::endl;
    system("pause");
}

void Account::save_data(fstream& fout)
{
    using namespace std;
    if (!fout.is_open()) return;

    fout << ID << endl << password << endl << name << endl << email << endl << socialID << endl;
}

void Account::view()
{
    // char ID[MAXID+1]; //21125xxx
    // char password[MAXSTR+1];

    // char firstName[MAXNAME+1];
    // char lastName[MAXNAME+1];
    // bool gender; // male: 1, female: 0
    // Date DOB; // day of birth
    // char socialID[MAXID]; //xxxxxxxx

    cout << "ID: " << ID << '\n';
    // cout << "firstname: " << firstName << "\n";
    // cout << "lastname: " << lastName << "\n";
    // cout << "gender (male: 1, female: 0): " << gender << "\n";
    //cout << DOB.day << "/" << DOB.month << "/" << DOB.year << "\n";
    cout << "socialID: " << socialID << "\n";
}

void importFromCSV(fstream &fin)
{
    
}