#pragma once
#include "..\\List\List.h"
#include <string.h>
#include "..\\Profile\Profile.h"
#include "..\\Constants\Constants.h"

struct Class {
    char name[MAXNAME];
    char ID[MAXID];

    List<Profile> stu_list;

    Class(){}
    Class(char name[MAXNAME], long long class_id = 0);

    void createClass();
    List<Profile> addStudent(); 
    List<Profile> importStudentFile();
};

#include "Class.cpp"