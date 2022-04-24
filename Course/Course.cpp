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
    return strcmp(s1.info.ID, s2.info.ID); // so sánh bằng Course ID
}

void Course::exportStudentsToCSV(){
    fstream fout;
  
    // opens an existing csv file or creates a new file.
    fout.open("studentList.csv", ios::out | ios::app);
    
    cout << "No, StudentID, StudentName, midTerm, Final\n";
    int N{0};
    for (Node <StudentScore> *cur; cur; cur = cur -> pNext)
    {
        cout << ++N << ","
             << cur->data.acc.ID << ","
             << cur->data.acc.name << ","
             << cur->data.score->midTerm << ","
             << cur->data.score->Final << ","
             << "\n";
    }
    
    fout.close();
}

void Course::manageCourseInfo()
{
    clrscr();
    cout << "MANAGE COURSE " << info.name << ".\n\n";

    cout << "id: " << "\t" << info.ID<< "\n";
    // cout << "name: " << "\t" << name << "\n";
    cout << "lecturer: " << "\t" << info.lecturer << "\n";
    cout << "numCredits: " << "\t" << info.numCredits << "\n";
    cout << "maxStudents: " << "\t" << info.maxStudents << "\n";
    // cout << "day: " << "\t" << day << "\n";
    cout << endl;

    cout << "0. Change courseInfo\n";
    cout << "1. Export list students\n";
    cout << "2. Go back\n\n";
    cout << "Your choice: ";
    int t{choose(0, 1)};
    if (t == 0) {
        info.updateCourseInfo();
        manageCourseInfo();
    }
    else if (t == 1) {

    }
    else {
        // lets go back
    }
}