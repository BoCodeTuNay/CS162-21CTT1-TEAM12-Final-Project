#pragma once

#include "../Constants/Constants.h"
#include "../Date/Date.h"

#include <iostream>
#include <fstream>

using namespace std;

/*
Chắc tụi mình tạm thời bỏ Date DOB đi cho dễ quản lý nhỉ? Tới lúc cuối deadline cần thiết thì thêm vào
ok ong
*/

struct Account {
    char username[MAXSTR+1];
    char password[MAXSTR+1];

    char ID[MAXID+1]; //21125xxx
    char name[MAXNAME+1];
    char email[MAXSTR+1];
    char socialID[MAXSTR+1];
    //void importFromCSV(fstream &fin);

};

//#include "Profile.cpp"