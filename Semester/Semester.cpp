#include "Semester.h"
#include <cassert>

void Semester::createCourseRegistration(List<Course*> &pOpenCourse) {
    Course newCourse;
    int check{0};
    do {
        newCourse.info.inputCourseInfo();
        cout << "Are you sure about all of the information of the course you want to create? (0 for No and 1 for Yes): ";
        cin >> check;
    } while (check == 0);

    listCourses.insert(newCourse);
    pOpenCourse.insert(&newCourse);
}

void Semester::manageCourses()
{
    clrscr();
    std::cout << "MANAGE THE AVAILABLE COURSES\n\n";

    int N{0};
    for (Node<Course>* cur = listCourses.begin(); cur; cur = cur->pNext) {
        std::cout << N++ << ". View course " << cur->data.info.ID << std::endl;
    }
    std::cout << N++ << ". Create a new course registration session\n";
    std::cout << N++ << ". Delete a course\n";
    std::cout << N++ << ". Go back\n\n";

    std::cout << "Your choice: ";
    int t{choose(0, N - 1)};
    if (t < N - 3) {
        listCourses.get(t).manageCourseInfo();
        manageCourses();
    }
    else if (t == N - 3){
        // create a course registration session...
    }
    else if (t == N - 2) {
        deleteCourse();
        manageCourses();
    }
    else if (t == N - 1) {
        // lets go back
    }
    else assert(false); // just to make sure this case cannot happen
}

void Semester::addCourseToSemester(List <CourseInfo> &listRegis){
    CourseInfo newCourseInfo;
    newCourseInfo.inputCourseInfo();
    Course newCourse;
    newCourse.info = newCourseInfo;
    listCourses.insert(newCourse);
    listRegis.insert(newCourseInfo);
}

void Semester::viewListCourses(){
    for (Node <Course> *i = listCourses.begin(); i; i = i -> pNext)
    {
        cout << i->data.info.name << "\n";
    }
}

// void Semester::updateCourseInfomation(){
//     Semester::viewListCourses();
//     char inputID[MAXSTR+1];
//     cout << "Which course ID do you want to update?\n";
//     cin.get(inputID, MAXSTR+1, '\n');

//     for (Node<Course>* i = listCourses.begin(); i != nullptr; i = i->pNext){
//         if (strcmp(i->data.info.ID, inputID)){
//             i->data.updateCourse();
//             return;
//         }
//     }
//     cout << "Do not have this course ID.\n";
// }

void Semester::deleteCourse(){
    char inputID[MAXSTR+1];
    cout << "Which course ID do you want to update?\n";
    cin.get(inputID, MAXSTR+1, '\n');
    if (listCourses.remove(Course(inputID), cmp_course)) {
        cout << "Course delete successfully!\n";
    }
    else {
        cout << "Do not have this course ID.\n";
    }
}

