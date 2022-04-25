#pragma once
#include "../List/List.h"
#include "../Account/Account.h"
#include "../Constants/Constants.h"
#include "../Student/Student.h"
#include <string.h>
#include <cassert>

struct Class {
    char ID[MAXSTR+1]; // 21APCS01
    // char name[MAXNAME+1];
    // long long class_id;
    List <Student*> studentsList;

    void manageStudent(List <Student>& listStudents); // CHECKED
    // void initInfo();
    void inputClass();
    bool addStudent(List<Student>& listStudents); 
    void importStudentFile(List <Student>& listStudents);
    void viewScoreBoard();
    void viewStudentList();
    void updateStudentResult();
};

#include "Class.cpp"