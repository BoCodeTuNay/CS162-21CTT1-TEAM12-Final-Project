#include "Schoolyear.h"

void Schoolyear::createSemester() {
    Semester semester;
    int semester_id = 0;
    if (numSemesters > 3) {
        cout << "You can only create 3 semesters." << endl;
        return;
    }
    do {
        cout << "What semester you want to create (1, 2, or 3)?\n";
        cin>>semester_id;               
    } while (semester_id<1 || semester_id>3);
    currentSemester = semester_id;
    semester_id--;
    yearSemesters[semester_id].created = true;
    cout << "What is the start date of this semester (example: 2020-01-01)?\n";
    string tmp_str_date;
    cin>>tmp_str_date;
    Date tmp_date(tmp_str_date);
    yearSemesters[semester_id].start_date = tmp_date;
    cout << "What is the end date of this semester (example: 2020-03-31)?\n";
    cin>>tmp_str_date;
    Date tmp_date(tmp_str_date);
    yearSemesters[semester_id].end_date = tmp_date;
}