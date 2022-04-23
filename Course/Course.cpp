#include "Course.h"

void Course::viewStudents()
{
    int index = 0;
    for (Node <StudentScore> *i = Student.begin(); i; i = i ->pNext)
    {
        index++;
        cout << "Student " << index << " : ";
        i->data.profile.view();
    }
}