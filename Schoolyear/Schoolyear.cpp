#include "Schoolyear.h"

void Schoolyear::createSemester() {
    Semester semester;
    int choose;
    if (listSem.size() > 3) {
        cout << "You can only create 3 semesters." << endl;
        return;
    }
    cout << "Do you really want to create semester " << listSem.size()+1 <<"? (0 for No and 1 for Yes): ";
    cin >> choose;
    if (choose == 0){
        return;
    }
    Semester semester;
    semester.created=true;
    listSem.insert(semester);
    cout << "What is the start date of this semester (example: 2020-01-01)?\n";
    string tmp_str_date;
    cin>>tmp_str_date;
    Date tmp_date(tmp_str_date);
    semester.start_date = tmp_date;
    cout << "What is the end date of this semester (example: 2020-03-31)?\n";
    cin>>tmp_str_date;
    Date tmp_date(tmp_str_date);
    semester.end_date = tmp_date;
}