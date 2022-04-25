#include "CourseInfo.h"

using namespace std;

void CourseInfo::viewCourseInfo(){
    cout << "ID: " << ID << "\n";
    cout << "Start day: "; start_date.output_date(); cout << "\n";
    cout << "End day: "; end_date.output_date(); cout << "\n";
    cout << "Start regis day: "; start_regis.output_date(); cout << "\n";
    cout << "End regis day: "; end_regis.output_date(); cout << "\n";
    cout << "Name: " << name << "\n";
    cout << "Lecturer: " << lecturer << "\n";
    cout << "numCredits " << numCredits << "\n";
    cout << "maxStudent" << maxStudent << "\n";
    //session
}

void CourseInfo::inputCourseInfo()
{
    cout << "Enter Course ID: ";
    cin.get(ID, MAXSTR+1, '\n');


    cout << "Enter Course name: ";
    fflush(stdin);
    cin.get(name, MAXSTR+1, '\n');


    cout << "Enter teacher name: ";
    fflush(stdin);
    cin.get(lecturer, MAXSTR+1, '\n');

    cout << "Enter number of credits: ";
    cin >> numCredits;

    cout << "Enter maximum students: ";
    cin >> maxStudent;

    start_date.enter_date();
    end_date.enter_date();
    start_regis.enter_date();
    end_regis.enter_date();

    for (int i=1; i<=2; i++)
    {
        cout << "Enter day of session " << i << ": ";
        int x;
        cin >> x;
        cout << "Enter session (S1 (07:30), S2 (09:30), S3(13:30), S4 (15:30)): ";
        int y;
        cin >> y;
        day[x] = y;
    }
}

void CourseInfo::updateCourseInfo()
{
    clrscr();
    cout << "Which elements you want to edit ?\n";
    cout << "id: 1\tname: 2\tlecturer: 3\tnumCredits: 4\tmaxStudents: 5\tcourseSession: 6\n";
    int choose;
    cin >> choose;

    switch (choose)
    {
        case 1:
        {
            cout << "Enter Course ID: ";
            fflush(stdin);
            cin.get(ID, MAXSTR+1, '\n');

            break;
        }
        case 2:
        {
            cout << "Enter Course name: ";
            fflush(stdin);
            cin.get(name, MAXSTR+1, '\n');
            break;
        }
        case 3:
        {
            cout << "Enter teacher name: ";
            fflush(stdin);
            cin.get(lecturer, MAXSTR+1, '\n');
            break;
        }
        case 4:
        {
            cout << "Enter number of credits: ";
            cin >> numCredits;
            break;
        }
        case 5:
        {
            cout << "Enter maximum students: ";
            cin >> maxStudent;
            break;
        }
        case 6:
        {
            for (int i=1; i<=2; i++)
            {
                cout << "Enter day of session " << i << ": ";
                int x;
                cin >> x;
                cout << "Enter session (S1 (07:30), S2 (09:30), S3(13:30), S4 (15:30)): ";
                int y;
                cin >> y;
                day[x] = y;
            }
        }
    }
}