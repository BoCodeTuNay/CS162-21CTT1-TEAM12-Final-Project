#pragma once
#include "../List/List.h"
#include "../Account/Account.h"
#include "../Constants/Constants.h"
#include "../Student/Student.h"
#include <string.h>

struct Class {
    char ID[MAXSTR+1]; // 21APCS01
    // char name[MAXNAME+1];
    // long long class_id;
    List <Student*> studentsList;

    void initInfo();
    void inputClass();
    List<Account> addStudent(); 
    void importStudentFile();
    void manageStudent();
    void viewStudentList();
};

#include "Class.cpp"