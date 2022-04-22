#pragma once
#include <iostream>
#include <cctype>
#include <cstdlib>
#include <fstream>
#include <cassert>
#include <cstring>
//#include "..\Student\Student.h"
 //#include "..\Staff\Staff.h"
#include "..\Constants\Constants.h"
//#include "..\Schoolyear\Schoolyear.h"
#include "..\List\List.h"
struct Student {
    char username[MAXSTR+1];
    char password[MAXSTR+1];

    char name[MAXSTR+1];
    char id[MAXID+1];
    char email[MAXSTR+1];

    Student(): username("\0"), password("\0"), name("\0"), id("\0"), email("\0") {}
    Student(const char*, const char*, const char*, const char*, const char*);
};
struct Staff {

    char name[MAXSTR+1];
    char id[MAXID+1];
    char email[MAXSTR+1];

    Staff(): username("\0"), password("\0"), name("\0"), id("\0"), email("\0") {}
    Staff(const char*, const char*, const char*, const char*, const char*);
};

struct Account {
    char username[MAXSTR+1];
    char password[MAXSTR+1];
    char ID[MAXID+1];
};

List<Account> listAccounts;
List<Student> listStudents;
List<Staff> listStaffs;
//List<Schoolyear> listSchoolyears;
int current_year_index = -1;

void clrscr();
// to check whether a given string consists of only alphabet characters and spaces
bool checkName(const char*);
// to check whether a given string consists of only alphabet characters and digits
bool checkAlphaDigit(const char*);
// to check whether a given string consists of only digits
bool checkDigit(const char*);
// to check whether an email is in the valid format
bool checkEmail(const char*);

void loadAccounts();
void save_data();
void loginScreen();
bool checkDatabase(const char*, const char*);
void signup();
void login();

int getCurrentYearIndex();
// return currentYear - firstYear

#include "System.cpp"