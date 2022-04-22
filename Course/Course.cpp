#include "Course.h"

void Course::inputCourses()
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
    cin >> maxStudents;

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

void Course::viewCourses()
{
    cout << "id: " << "\t" << ID << "\n";
    cout << "name: " << "\t" << name << "\n";
    cout << "lecturer: " << "\t" << lecturer << "\n";
    cout << "numCredits: " << "\t" << numCredits << "\n";
    cout << "maxStudents: " << "\t" << maxStudents << "\n";
    cout << "day: " << "\t" << day << "\n";
    // cout << "session: " << "\t" << session << "\n";

}

void Course::updateCourse()
{
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
            cin >> maxStudents;
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