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
    cout << "numCredits: " << numCredits << "\n";
    cout << "maxStudent: " << maxStudent << "\n";
    system("pause");
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

    std::cout << "Enter start date(yyyy/mm/dd):\n";
    start_date.enter_date();
    std::cout << "Enter end date:\n";
    end_date.enter_date();
    std::cout << "Enter start date of registration session(yyyy/mm/dd):\n";
    start_regis.enter_date();
    std::cout << "Enter end date of registration session(yyyy/mm/dd):\n";
    end_regis.enter_date();

    for (int i=0; i<=7; i++)
        day[i] = 0;
    
    for (int i=1; i<=2; i++)
    {
        SessionLoop: 
            cout << "Enter day of session " << i << " (2 -> 7 as MON to SAT): ";
            int x{choose(2, 7)};

            while (x < 2 || x > 7) {
                cout << "Invalid day in week!\n";
                cout << "Please input it again.\n";
                goto SessionLoop;
            }

            cout << "Enter session (1 (07:30), 2 (09:30), 3(13:30), 4 (15:30)): ";
            int y{choose(1, 4)};
        
        while (day[x] != 0) {
            cout << "This course already has one session in this day.\n";
            cout << "Please choose another day.\n";
            goto SessionLoop;
        }
        day[x] = y;
    }
    fflush(stdin);
}

void CourseInfo::updateCourseInfo()
{
    clrscr();
    cout << "Which elements you want to edit ?\n";
    cout << "1: id\n2: name\n3: lecturer\n4: numCredits\n5: maxStudents\n6: courseSession\n";
    
    cout << "Your choice: ";
    int t{choose(1, 6)};

    switch (t)
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
                int x{choose(2, 7)};
                cout << "Enter session (S1 (07:30), S2 (09:30), S3(13:30), S4 (15:30)): ";
                int y{choose(1, 4)};
                day[x] = y;
            }
        }
    }
}

void CourseInfo::load_data(fstream& fin)
{
    if (!fin.is_open()) return;

    fin.get();
    fin.get(ID, MAXSTR+1, '\n').get();
    start_date.load_date(fin);
    fin.get();
    end_date.load_date(fin);
    fin.get();
    start_regis.load_date(fin);
    fin.get();
    end_regis.load_date(fin);
    fin.get();
    fin.get(name, MAXSTR+1, '\n').get();
    fin.get(lecturer, MAXSTR+1, '\n').get();
    fin >> numCredits;
    fin >> maxStudent;
    for (int i=2; i<=7; i++)
        fin >> day[i];
    fin.get();
    
    //test load_data courseInfo
    // viewCourseInfo();
    // system("pause");
}
void CourseInfo::save_data(fstream& fout)
{
    // ID
    // start_date
    // end_date
    // start_regis
    // end_regis
    // name
    // lecturer
    // numCredits
    // maxStudent
    // day (1 .. 7)
    if (!fout.is_open()) return;
    fout << ID << "\n";
    start_date.save_date(fout);
    end_date.save_date(fout);
    start_regis.save_date(fout);
    end_regis.save_date(fout);
    fout << name << "\n";
    fout << lecturer << "\n";
    fout << numCredits << "\n";
    fout << maxStudent << "\n";
    for (int i=2; i<=7; i++)
        fout << day[i] << " ";
    fout << "\n";
}