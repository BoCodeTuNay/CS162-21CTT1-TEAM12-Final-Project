#pragma once

#include "../Constants/Constants.h"
#include "../Date/Date.h"

#include <iostream>
#include <string>
#include <fstream>

using namespace std;

struct Profile {
    string ID[MAXID]; //21125xxx
    string firstName[MAXNAME];
    string lastName[MAXNAME];
    bool gender; // male: 1, female: 0
    Date DOB; // day of birth
    string socialID[MAXID]; //xxxxxxxx

    void importFromCSV(fstream &fin);

};

#include "Profile.cpp"