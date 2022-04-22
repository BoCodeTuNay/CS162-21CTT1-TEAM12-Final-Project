/*

This file includes all the constants used in the program.
The purpose is to avoid re-definitions of these constants.

*/

#pragma once
#include <iostream>

const int MAXNAME = 25; // for students and staffs name length
const int MAXSTR = 50; // for other features' convenience
const int MAXID = 8; // 21125XXX for Student's id, 20202021 for Schoolyear's id
const int YEARLENGTH = 9; // of the format, e.g. 2020-2021 -> exactly 9 chars

void clrscr();
int choose(int, int);

#include "Constants.cpp"