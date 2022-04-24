#pragma once

#include "../Constants/Constants.h"
#include "../Date/Date.h"

#include <iostream>
#include <fstream>

/*
Chắc tụi mình tạm thời bỏ Date DOB đi cho dễ quản lý nhỉ? Tới lúc cuối deadline cần thiết thì thêm vào
ok ong
*/

//#include "Profile.cpp"
struct Account {
    char ID[MAXID+1]; //21125xxx
    char password[MAXSTR+1];

    char name[MAXNAME+1];
    char email[MAXSTR+1];
    //bool gender; // male: 1, female: 0
    //Date DOB; // day of birth
    char socialID[MAXSTR+1]; //xxxxxxxx

    //void importFromCSV(fstream &fin);
    Account() {}
    Account(const char*, const char*, const char*, const char*, const char*);
    void read_data(std::fstream&);
    void save_data(std::fstream&);
    void view();
};

#include "Account.cpp"
