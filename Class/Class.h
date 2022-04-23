#pragma once
#include "../List/List.h"
#include <string.h>
#include "../Account/Account.h"
#include "../Constants/Constants.h"

struct Class {
    char ID[MAXID+1];
    char name[MAXNAME+1];
    long long class_id;
    List <Account> StudentsList;

    void initInfo();
    void inputClass();
    void addStudent(); 
    void importStudentFile();
};

#include "Class.cpp"