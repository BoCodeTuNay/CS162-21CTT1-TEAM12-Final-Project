#pragma once

#include "Constants.h"
#include "Date.h"

#include <iostream>
#include <char>
#include <fstream>

using namespace std;

struct Profile {
    char ID[MAXID]; //21125xxx
    char firstName[MAXNAME];
    char lastName[MAXNAME];
    bool gender; // male: 1, female: 0
    Date DOB; // day of birth
    char socialID[MAXID]; //xxxxxxxx

    void importFromCSV(fstream &fin);

};

#include "Profile.cpp"