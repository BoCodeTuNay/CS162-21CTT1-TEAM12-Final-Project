#pragma once
#include "List.h"
#include <string.h>
#include "Profile/Profile.h"
#include "Constants.h"

struct Class {
    char name[MAXNAME+1];
    char ID[MAXSTR+1];

    List<Profile> stu_list;

    Class(){}
    Class(char name[MAXNAME], long long class_id = 0);

    void createClass();
    void addStudent(); //import CSV file
};

#include "Class.cpp"