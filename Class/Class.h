#pragma once
#include "../List/List.h"
#include <string.h>
#include "../Account/Account.h"
#include "../Constants/Constants.h"

struct Class {
    char name[MAXNAME];
    char ID[MAXID];

    List <Account> stu_list;

    Class(){}
    Class(char name[MAXNAME], long long class_id = 0);

    void inputClass();
    void addStudent(); 
    void importStudentFile();
};

#include "Class.cpp"