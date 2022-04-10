#include "Student.h"
#include <string.h>
#include "Constants.h"

struct Class {
    char name[MAXNAME];
    long long class_id;

    Class(char name[MAXNAME], long long class_id = 0);

    List<Student> stu_list;
};

#include "Class.cpp"