#include "Course.h"
#include <string.h>

void Course::manageCourseInfo()
{
    clrscr();
    cout << "MANAGE COURSE " << info.name << ".\n\n";

    cout << "id: " << "\t" << info.ID<< "\n";
    // cout << "name: " << "\t" << name << "\n";
    cout << "lecturer: " << "\t" << info.lecturer << "\n";
    cout << "numCredits: " << "\t" << info.numCredits << "\n";
    cout << "maxStudents: " << "\t" << info.maxStudent << "\n";
    // cout << "day: " << "\t" << day << "\n";
    cout << endl;

    cout << "0. Change courseInfo\n";
    cout << "1. Export list students\n";
    cout << "2. Import score board\n";
    cout << "3. View score board\n";
    cout << "4. Go back\n\n";
    cout << "Your choice: ";
    int t{choose(0, 2)};
    if (t == 0) {
        info.updateCourseInfo();
        manageCourseInfo();
    }
    else if (t == 1) {
        exportStudentsToCSV();
        manageCourseInfo();
    }
    else if (t == 2) {
        importStudentsFromCSV();
        manageCourseInfo();
    }
    else if (t == 3){
        viewScoreboard();
        manageCourseInfo();
    }
    else {
        // lets go back
    }
}

void Course::viewScoreboard()
{
    clrscr();
    std::cout << "SCORE BOARD " << endl << endl;

    cout << "No\tStudentID\tStudentName\tmidTerm\tFinal\n";
    int N{0};
    for (Node <StudentScore> *cur = student.begin(); cur; cur = cur -> pNext)
    {
        cout << ++N << "\t"
             << cur->data.acc.ID << "\t"
             << cur->data.acc.name << "\t"
             << cur->data.score->midTerm << "\t"
             << cur->data.score->Final << "\n";
    }

    system("pause");
}

void Course::viewStudents()
{
    int index = 0;
    for (Node <StudentScore> *i = student.begin(); i; i = i ->pNext)
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
    fout.open("studentList.csv", ios::out);
    
    fout << "No, StudentID, StudentName, midTerm, Final\n";
    int N{0};
    for (Node <StudentScore> *cur = student.begin(); cur; cur = cur -> pNext)
    {
        fout << ++N << ","
             << cur->data.acc.ID << ","
             << cur->data.acc.name << ","
             << cur->data.score->midTerm << ","
             << cur->data.score->Final << "\n";
    }
    
    fout.close();
}

void Course::importStudentsFromCSV(){
    ifstream fin;
    fin.open("studentList.csv", ios::in);
    if (!fin.is_open())
    {
        cout << "File not found!" << endl;
        return;
    }

    string line;
    getline(fin, line);
    string N, ID, name;
    double midTerm, final;
    
    for (Node <StudentScore> *cur = student.begin(); cur; cur = cur -> pNext){
        getline(fin, line);

        int pos = line.find(",");
        N = line.substr(0, pos);
        line = line.substr(pos + 1);

        pos = line.find(",");
        ID = line.substr(0, pos);
        line = line.substr(pos + 1);

        pos = line.find(",");
        name = line.substr(0, pos);
        line = line.substr(pos + 1);

        pos = line.find(",");
        midTerm = stod(line.substr(0, pos));
        line = line.substr(pos + 1);

        pos = line.find(",");
        final = stod(line.substr(0, pos));

        strcpy(cur->data.acc.ID, ID.c_str());
        strcpy(cur->data.acc.name, name.c_str());
        cur->data.score->midTerm = midTerm;
        cur->data.score->Final = final;
    }

    fin.close();
}

void Course::load_data(fstream &fin) {

}

void Course::save_data(fstream &fout) {
    info.save_data();
    
}

