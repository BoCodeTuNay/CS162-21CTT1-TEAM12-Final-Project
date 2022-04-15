#pragma once
#include <iostream>
#include <cctype>
#include "..\Student\Student.h"
#include "..\Staff\Staff.h"
#include "..\Constants\Constants.h"
#include "..\List\List.h"
#include "..\Schoolyear\Schoolyear.h"

List<Student> listStudents;
List<Staff> listStaffs;
List<Schoolyear> listSchoolyears;
int current_year_index = -1;
struct Student {
    char username[MAXSTR+1];
    char password[MAXSTR+1];

    char name[MAXSTR+1];
    char id[MAXID+1];
    char email[MAXSTR+1];
};
struct Staff {
    char username[MAXSTR+1];
    char password[MAXSTR+1];

    char name[MAXSTR+1];
    char id[MAXID+1];
    char email[MAXSTR+1];
};

void clrscr();
// to check whether a given string consists of only alphabet characters and spaces
bool checkName(const char*);
// to check whether a given string consists of only alphabet characters and digits
bool checkAlphaDigit(const char*);
// to check whether a given string consists of only digits
bool checkDigit(const char*);
// to check whether an email is in the valid format
bool checkEmail(const char*);

int choose(int, int);
void signup();
void login();

#include "System.cpp"