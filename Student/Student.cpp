#pragma once
#include "Student.h"
#include <vector>
#include <cstring>

void Student::studentMenu(List <Course*> &pOpenCourse)
{
    clrscr();
    // fstream fin;
    // fin.open(COURSES_FILE, ios::in);
    // load_data(fin, pAllCourses);
    // fin.close();
    std::cout << "WELCOME TO THE SYSTEM, " << acc.name << endl << endl;

    std::cout << "0. View my courses\n";
    std::cout << "1. View courses in registration session\n";
    std::cout << "2. View scoreboard\n";
    std::cout << "3. View profile\n";
    std::cout << "4. Log out\n\n";
    std::cout << "Your choice: ";
    int t{choose(0, 4)};
    if (t == 0) {
        // view the student's courses (both registered and in session)
        viewCourses();
        studentMenu(pOpenCourse);
    }
    else if (t == 1) {
        //viewListOpenCourse(pOpenCourse);
        enrolledCourse(pOpenCourse);
        studentMenu(pOpenCourse);
    }
    else if (t == 2) {
        viewScoreBoard();
        studentMenu(pOpenCourse);
    }
    else if (t == 3) {
        viewProfile();
        studentMenu(pOpenCourse);
    }
    else {
        // lets go back
        // fstream fout;
        // fout.open(COURSES_FILE, ios::out);
        // save_data(fout);
        // fout.close();
        return;
    }
}

void Student::viewProfile()
{
    clrscr();
    std::cout << "WELCOME TO YOUR PERSONAL PAGE.\n\n";

    std::cout << "Name: " << acc.name << endl;
    std::cout << "Email: " << acc.email << endl;
    std::cout << "Social ID: " << acc.socialID << endl;
    std::cout << "ID: " << acc.ID << endl;
    std::cout << std::endl;

    std::cout << "0. Change password\n";
    std::cout << "1. Go back\n\n";
    std::cout << "Your choice: ";
    int t{choose(0, 1)};
    if (t == 0) {
        changePassword();
        viewProfile();
    }
    else {
        // lets go back
        return;
    }
}

void Student::changePassword()
{
    clrscr();
    std::cout << "CHANGE PASSWORD\n";
    std::cout << "Press Enter to go back.\n\n";
    
    bool cont{false};
    char cur_pass[MAXSTR+1];
    do {
        std::cout << "Enter your current password: ";
        fflush(stdin);
        std::cin.get(cur_pass, MAXSTR+1, '\n');
        if (std::cin.fail()) { // nothing was inputted
            std::cin.clear();
            fflush(stdin);
            return;
        }
        else if (std::cin.get() != '\n' || !checkAlphaDigit(cur_pass)) {
            std::cout << "Invalid password. Please try again.\n";
            cont = true;
        }
        else if (strcmp(cur_pass, acc.password)) {
            std::cout << "The password is incorrect. Please try again.\n";
            cont = true;
        }
        else cont = false;
    } while (cont);

    cont = false;
    char new_pass[MAXSTR+1];
    do {
        std::cout << "Enter your new password: ";
        fflush(stdin);
        std::cin.get(new_pass, MAXSTR+1, '\n');
        if (std::cin.fail() || std::cin.get() != '\n' || !checkAlphaDigit(new_pass)) {
            std::cin.clear();
            fflush(stdin);
            std::cout << "Invalid password. Please try again.\n";
            cont = true;
        }
        else cont = false;
    } while (cont);
    strcpy(acc.password, new_pass);
}

bool cmp_CourseScore(const CourseScore &a, const CourseScore &b) {
    return a.pCourse == b.pCourse;
}

int Student::CurCourses() {
    int cnt = 0;
    for (Node<CourseScore>* p = CoursesList.begin(); p; p = p -> pNext)
        cnt += ifDate(getCurrentDate(), (((p->data).pCourse)->info).start_date, (((p->data).pCourse)->info).end_date);
    return cnt;
}

///them courseInfo
void Student::enrolledCourse(List<Course*> pOpenCourse) {
    List<CourseInfo> res;

    // nếu còn thời gian fix: mình check số tín chỉ max <= 22

    if (CurCourses() == 0) init_StudentInfo();

    clrscr();
    if (CurCourses() > 4) {
        cout << "You have registered 5 courses!";
        return;
    }

    if (pOpenCourse.size() == 0) {
        cout << "There is no course to regis!\n";
        system("pause");
        return;
    }

    while (CurCourses() < 5) {
        clrscr();
        vector<Course*> vCourse;

        int Num = 0;
        for (Node <Course*>* p = pOpenCourse.begin(); p; p = p -> pNext) {
            bool check = true;
            Course* data = p->data;
            // system("pause");
            for (int i = 1; i < 7; ++i)
                if ((data->info).day[i] > 0 && fClass[i][(data->info).day[i]])
                    check = false;
            if ((data->student).size() > (data->info).maxStudent) check = false;

            if (!check) continue;

            vCourse.push_back(data);
            cout << ++Num << ". " << (data->info).name << '\n';
        }
        if (Num == 0) {
            cout << "There is no course to regis!\n";
            system("pause");
            return;
        }

        cout << "Please enter the number of course you want to regis (or 0 to exit):" << '\n';
        // ues choose() here to check bad input
        int reg_Num{choose(0, Num)};
        if (reg_Num == 0) return;

        Course* pickCourse = vCourse[reg_Num - 1];
        Score* pickScore = new Score;
        
        for (int i = 1; i < 7; ++i)
            if ((pickCourse->info).day[i] > 0)
                fClass[i][(pickCourse->info).day[i]] = true;

        StudentScore SS;
        SS.score = pickScore;
        SS.acc = acc;  

        pickCourse->student.insert(SS);
            
        CourseScore pickCS = {pickCourse, pickScore};

        CoursesList.insert(pickCS);

        cout << "Enroll success!\n";
        system("pause");

        // delete pickCourse;
        // delete pickScore;
    }
}

void Student::viewCourses() {
    clrscr();
    std::cout << "MANAGE THE AVAILABLE COURSES\n\n";

    /*
    TO-DO:
    - Thực hiện chức năng view thông tin của course (option 0 đến Num - 2) already
    */

    int Num = -1;
    for (Node<CourseScore>* p = CoursesList.begin(); p; p = p -> pNext) {
        ++Num;
        cout << Num << ". View course " << (((p->data).pCourse->info).name) << '\n';
    }

    if (Num > -1) 
        cout << ++Num << ". Remove a course\n";
    else 
        cout << "You haven't regis any course!\n";
    cout << ++Num << ". Go back\n";

    cout << "Your choice: ";
    int t{choose(0, Num)};
    if (t <= Num - 2) {
        Num = 0;
        for (Node<CourseScore>* p = CoursesList.begin(); p; p = p -> pNext) {
            if (Num == t) {
                (p->data).pCourse->info.viewCourseInfo();
                break;
            }
            ++Num;
        }
    } else if (t == Num - 1) {
        cout << "Please enter the number of course you want to remove: ";
        int nCourse{choose(0, Num - 3)};
        Num = 0;
        for (Node<CourseScore>* p = CoursesList.begin(); p; p = p -> pNext) {
            if (Num == nCourse) {
                removeCourse((p->data).pCourse->info.ID);
                break;
            }
            ++Num;
        }
    } 

    return;
}

void Student::viewListOpenCourse(List <Course*> &pOpenCourse)
{
    cout << "LIST OPEN COURSE\n\n";
    for (Node <Course*> *i = pOpenCourse.begin(); i; i = i -> pNext)
    {
        cout << i->data->info.name << " ";
    }
    cout << "\n";
}


void Student::removeCourse(char id[MAXID+1]) {
    CourseScore pick;

    for (Node<CourseScore>* p = CoursesList.begin(); p; p = p -> pNext) {
        if (strcmp(((p->data).pCourse->info).ID, id) == 0) {
            pick = p->data;
            break;
        }
    }

    CoursesList.remove(pick, cmp_CourseScore);
}

void Student::init_StudentInfo() {
    class_id = 0;
    long long MOD = 1333333337;
    long long base = 2017;
    for (int i = 0; i < strlen(class_name); ++i) {
        class_id = ((class_id * base % MOD) + class_name[i]) % MOD;
    }
    memset(fClass, false, sizeof fClass);
}

void Student::listOfCourses() {
    cout << "This semester you study courses:\n";
    int Num = 0;
    for (Node<CourseScore>* p = CoursesList.begin(); p; p = p -> pNext) 
        if (ifDate(getCurrentDate(), ((p->data).pCourse->info).start_date, ((p->data).pCourse->info).end_date)) {
            ++Num;
            cout << Num << ". " << (((p->data).pCourse->info).name) << '\n';
        }
    cout << "\n";

    system("pause");
}

int Student::listOfCourseStudied() {
    cout << "List of course you have studied: \n";
    int Num = 0;
    for (Node<CourseScore>* p = CoursesList.begin(); p; p = p -> pNext) {
            ++Num;
            cout << Num << ". " << (((p->data).pCourse->info).name) << '\n';
        }

    cout << "\n";
    system("pause");
    return Num;
}

void Student::viewScoreBoard() {
    clrscr();
    cout << "STUDENT SCOREBOARD\n\n";
    int Num = 0;
    for (Node<CourseScore>* p = CoursesList.begin(); p; p = p -> pNext) {
        Score* tmp = p->data.pScore;
        cout << ++Num << "\t" << (p->data).pCourse->info.name << '\t';
        cout << tmp->midTerm << '\t' << tmp->Final << '\t' << tmp->HW << '\t' << tmp->GPA << '\n';
    }

    system("pause");
}

void Student::updateResult() {
    int N = listOfCourseStudied();
    if (N==0){
        cout << "This student haven't enrolled in any course yet!";
        system("pause");
        return;
    }
    cout << "Enter course you want to update result (1 -> " << N << "): ";
    int t = choose(1, N);
    cout << "Enter midterm score, final score: ";
    int midTermScore, finalScore;
    cin >> midTermScore >> finalScore;
    CoursesList.get(t-1).pScore->midTerm = midTermScore;
    CoursesList.get(t-1).pScore->Final = finalScore;
}

void Student::load_data(fstream &fin, List<Course*> pAllCourses) {
    if (!fin.is_open()) return;
    fin >> class_name;
    for (int i = 0; i < 8; ++i) 
        for (int j = 0; j < 5; ++j) {
            int x;
            fin >> x;
            fClass[i][j] = false;
            if (x) fClass[i][j] = true;
        }
    int n;
    fin >> n;
    for (int i = 0; i < n; ++i) {
        char inpID[MAXID+1];
        fin >> inpID;
        for (Node<Course*>* p = pAllCourses.begin(); p; p = p -> pNext) 
            if (strcmp(inpID, (p->data->info).ID) == 0) {
                Score* pScore = new Score;
                CourseScore CS = {p->data, pScore};
                CoursesList.insert(CS);

                fin >> (pScore->midTerm) >> (pScore->Final) >> (pScore->HW) >> (pScore->GPA);

                StudentScore tmp;
                tmp.acc = acc;
                tmp.score = pScore;
                (p->data->student).insert(tmp);
                break;
            }
    }
}

void Student::save_data(fstream &fout) {
    // format
    // ID
    // class_name
    // fClass[8][5]
    // nCourse
    // courseID1 CourseScore1
    // courseID2 CourseScore2
    // ...
    if (!fout.is_open()) return;
    fout << acc.ID << '\n';
    fout << class_name << '\n';
    for (int i = 0; i < 8; ++i) {
        for (int j = 0; j < 5; ++j) 
            fout << (fClass[i][j] ? 1 : 0) << ' ';
        fout << '\n';
    }
    fout << CoursesList.size() << '\n';
    for (Node<CourseScore>* p = CoursesList.begin(); p; p = p -> pNext) {
        fout << (p->data).pCourse->info.ID << ' ' << (p->data).pScore->midTerm << ' ';
        fout << (p->data).pScore->Final << ' ' << (p->data).pScore->HW << ' ';
        fout << (p->data).pScore->GPA << '\n';
        // delete p->data.pCourse;
        // delete p->data.pScore;
    }
    fout << '\n';

}