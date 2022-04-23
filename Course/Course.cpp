#include "Course.h"

void Course::viewStudents()
{
    int index = 0;
    for (Node <StudentScore> *i = Student.begin(); i; i = i ->pNext)
    {
        index++;
        cout << "Student " << index << " : ";
        i->data.acc.view();
    }
}

bool cmp_course(const Course& s1, const Course& s2)
{
    return strcmp(s1.info.ID, s2.info.ID); // so sánh bằng MSSV
}