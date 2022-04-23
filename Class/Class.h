#pragma once
#include "../List/List.h"
#include <string.h>
#include "../Account/Account.h"
#include "../Constants/Constants.h"

struct Class {
    char name[MAXNAME];
    char ID[MAXID];

    List<Profile> stu_list;

    Class(){}
    Class(char name[MAXNAME], long long class_id = 0);

    void createClass();
    List <Account> addStudent(); 
    List <Account> importStudentFile();
};

#include "Class.cpp"