#pragma once
#include "Student.h"

bool cmp_Course(const CourseScore &a, const CourseScore &b) {
    return strcmp(a.pCourse.ID, b.pCourse.ID);
}

int Student::CurCourses() {
    int cnt = 0;
    for (Node<CourseScore>* p = CoursesList.begin(); p; p = p -> pNext)
        cnt += ifDate(getCurrentDate(), (p->data->pScourse).start_date, (p->data.pScoure).end_date);
    return cnt;
}

///them courseInfo
List<CourseInfo> Student::enrolledCourse(List<Course> pOpenCourse) {
    List<CourseInfo> res;
    
    if (CurCourses() > 4) {
        cout << "You have registered 5 courses!";
        return res;
    }

    while (CurCourses() < 5) {
        clrscr();
        vector<Course*> vCourse;
        
        int reg_Num, Num = 0;
        for (Node<Course>* p = pOpenCourse.begin(); p; p = p.pNext) {
            bool check = true;
            for (int i = 1; i < 7; ++i) 
                if ((p->data).info.day[i] > 0 && !fClass[i][(p->data).info.day[i]])
                    check = false;
            if ((p->data).Student.size() >= (p->data).info.maxStudents) check = false;

            if (!check) continue;
            vCourse.push_back(&(p->data));
            ++Num;
            cout << Num << ". " << (p->data).info.name << '\n'; 
        }

        cout << "Please enter the number of course you want to regis: ";
        cin >> reg_Num;

        Course* pickCourse = vCourse[reg_Num - 1];

        for (int i = 1; i < 7; ++i)
            if (*pickCourse.info.day[i] > 0)
                fClass[i][*pickCourse.info.day[i]] = true;
        
        Score* tmp = NULL;

        CoursesList.insert(CourseScore(pickCourse, tmp));
        res.insert((*pickCourse).info);
    }
}

void Student::viewEnrolledCourses() {
    for (Node<CourseScore>* p = pScore.begin(); p; p = p -> pNext) {
        /// Hiển thị danh sách sinh viên đã enroll
    }
}

void Student::removeCourse(char id[MAXNAME]) {
    CourseScore pick;

    for (Node<CourseScore>* p = pScore.begin(); p; p = p -> pNext) {
        if (strcmp(p -> data.pCourse.ID, id)) {
            pick = p->data;
            break;
        }
    }

    pScore.remove(pick, cmp_Course);
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
    int cnt = 0;
    for (Node<CourseScore>* p = pScore.begin(); p; p = p -> pNext) 
        if (ifDate(getThisDate(), (p->data.pCourse.start_date), (p->data.pCourse.end_date))) 
            cout << ++cnt << '.' << (p->data.pCourse.name) << '\n';
}