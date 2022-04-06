#include "Student.h"

struct StudentNode {
    Student *mem;
    StudentNode *next;
};

struct Class {
    StudentNode* stu;
    int Student_num = 0;

    void Add_Student();
};