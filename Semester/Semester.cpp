#include "Semester.h"

void Semester::createCourseRegistration(){
    cout << "What is the start date of course registration session (example: 2020-01-01)?\n";
    string tmp_str_date;
    cin>>tmp_str_date;
    Date tmp_date(tmp_str_date);
    start_registration_date = tmp_date;
    cout << "What is the end date of course registration session (example: 2020-03-31)?\n";
    cin>>tmp_str_date;
    Date tmp_date(tmp_str_date);
    end_registration_date = tmp_date;
}