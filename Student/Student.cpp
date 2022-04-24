#pragma once
#include "Student.h"
#include <vector>
#include <cstring>

void Student::studentMenu()
{
    clrscr();
    std::cout << "WELCOME TO THE SYSTEM, " << acc.name << endl << endl;

    std::cout << "0. View my courses\n";
    std::cout << "1. View courses in registration session\n";
    std::cout << "2. View profile\n";
    std::cout << "3. Log out\n\n";
    std::cout << "Your choice: ";
    int t{choose(0, 3)};
    if (t == 0) {
        // view the student's courses (both registered and in session)
        viewEnrolledCourses();
        studentMenu();
    }
    else if (t == 1) {
        // traverse listOpenCourse ...
        //enrolledCourse(pOpenCourse);
    }
    else if (t == 2) {
        viewProfile();
        studentMenu();
    }
    else {
        // lets go back
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
    
    if (CurCourses() > 4) {
        cout << "You have registered 5 courses!";
        return;
    }

    while (CurCourses() < 5) {
        clrscr();
        vector<Course*> vCourse;

        int reg_Num, Num = 0;
        for (Node <Course*>* p = pOpenCourse.begin(); p; p = p -> pNext) {
            bool check = true;
            Course* data = p->data;
            for (int i = 1; i < 7; ++i)
                if ((data->info).day[i] > 0 && fClass[i][(data->info).day[i]])
                    check = false;
            if ((data->Student).size() > (data->info).maxStudents) check = false;

            if (!check) continue;

            vCourse.push_back(data);
            cout << ++Num << ". " << (data->info).name << '\n';
        }

        cout << "Please enter the number of course you want to regis: " << '\n';
        cin >> reg_Num;

        Course* pickCourse = vCourse[reg_Num - 1];
        Score* pickScore = new Score;
        
        for (int i = 1; i < 7; ++i)
            if ((pickCourse->info).day[i] > 0)
                fClass[i][(pickCourse->info).day[i]] = true;

        StudentScore* SS = new StudentScore;
        SS->score = pickScore;
        SS->acc = acc;

        pickCourse->Student.insert(*SS);
            
        CourseScore* pickCS = new CourseScore(pickCourse, pickScore);

        CoursesList.insert(*pickCS);
    }
}

void Student::viewEnrolledCourses() {
    clrscr();

    int Num = 0;
    for (Node<CourseScore>* p = CoursesList.begin(); p; p = p -> pNext) {
        ++Num;
        cout << Num << ". " << (((p->data).pCourse->info).name) << '\n';
    }

    int cNum = 0;
    cout << ++cNum << ". Remove a course\n";
    cout << ++cNum << ". Go back\n";

    cout << "Your choice: ";
    int t{choose(0, cNum - 1)};
    if (t == 0) {
        cout << "Please enter the number of course you want to remove: ";
        int nCourse{choose(0, Num - 1)};
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

void Student::removeCourse(char id[MAXID+1]) {
    CourseScore pick;

    for (Node<CourseScore>* p = CoursesList.begin(); p; p = p -> pNext) {
        if (strcmp(((p->data).pCourse->info).ID, id)) {
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
}

void Student::viewScoreBoard() {

}