#pragma once

#include "../Constants/Constants.h"
#include "../Date/Date.h"

#include <iostream>
#include <fstream>

using namespace std;

struct Account {
    char ID[MAXID+1]; //21125xxx
    char password[MAXSTR+1];

    char firstName[MAXNAME+1];
    char lastName[MAXNAME+1];
    bool gender; // male: 1, female: 0
    Date DOB; // day of birth
    char socialID[MAXID]; //xxxxxxxx

    void importFromCSV(fstream &fin);
    
    void view();
};

#include "Account.cpp"