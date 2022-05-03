#pragma once
#include <iostream>
#include <cctype>
#include <cstdlib>
#include <fstream>
#include <cassert>
#include <cstring>
#include "..\Student\Student.h"
 #include "..\Staff\Staff.h"
#include "..\Constants\Constants.h"
#include "..\Schoolyear\Schoolyear.h"
#include "..\List\List.h"
#include "../Account/Account.h"

List <Student> listStudents;
List <Staff> listStaffs;
List <Class> listClasses;
List <Course*> pOpenCourse;
List <Course*> pAllCourse;

int current_year_index = -1;

void loadAccounts();
void saveAccounts();
void load_data();
void save_data();
void load_students();
void save_students();

/*
return 0 if no such account is found
return 1 if the account found is of student
return 2 if the account found is of staff
*/
int checkDatabase(const char*, const char*);
// return true if go to that screen again, return false otherwise
void login();
bool loginScreen();

int getCurrentYearIndex();
// return currentYear - firstYear

#include "System.cpp"