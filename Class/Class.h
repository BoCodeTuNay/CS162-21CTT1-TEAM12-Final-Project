#include "Student.h"
#include <string.h>

struct Class {
    char name[10];
    long long class_id;

    Class(char name[10], long long class_id = 0);

    List<Student> stu_list;
};

#include "Class.cpp"