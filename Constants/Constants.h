/*

This file includes all the constants used in the program.
The purpose is to avoid re-definitions of these constants.

*/

#pragma once
#include <iostream>

const char* ACCOUNTS_FILE = "Accounts.txt";
const char* COURSES_FILE = "Courses.txt";
const char* CLASSES_FILE = "Classes.txt";

const int MAXNAME = 40; // for students and staffs name length
const int MAXSTR = 50; // for other features' convenience
const int MAXID = 8; // 21125XXX for Student's id, 20202021 for Schoolyear's id
const int YEARLENGTH = 9; // of the format, e.g. 2020-2021 -> exactly 9 chars

void clrscr();
int choose(int, int);
// to check whether a given string consists of only alphabet characters and spaces
bool checkName(const char*);
// to check whether a given string consists of only alphabet characters and digits
bool checkAlphaDigit(const char*);
// to check whether a given string consists of only digits
bool checkDigit(const char*);
// to check whether an email is in the valid format
bool checkEmail(const char*);

#include "Constants.cpp"

