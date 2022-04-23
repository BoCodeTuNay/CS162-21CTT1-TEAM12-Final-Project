#include "Semester.h"

// void Semester::createCourseRegistration(List <CourseInfo>& listCourseInfo, int schoolyearID) {
//     CourseInfo courseInfo;
//     int check;
//     do {
//         courseInfo.input();
//         cout << "Are you sure about all of the information of the course you want to create? (0 for No and 1 for Yes): ";
//         cin >> check;
//     } while (check == 0);

//     listCourseInfo.insert(courseInfo);
//     courseInfo.semesterID = ID;
//     courseInfo.schoolyearID = schoolyearID;
//     Course course;
//     course.info = courseInfo;
    
//     listCourses.insert(course);
// }

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

void Semester::updateCourseInfomation(){
    Semester::viewListCourses();
    char inputID[MAXSTR+1];
    cout << "What course ID do you want to update?\n";
    cin.get(inputID, MAXSTR+1, '\n');

    for (Node<Course>* i = listCourses.begin(); i != nullptr; i = i->pNext){
        if (strcmp(i->data.info.ID, inputID)){
            i->data.updateCourse();
            return;
        }
    }
    cout << "Do not have this course ID.\n";
}

void Semester::deleteCourse(List <CourseInfo> &listRegis){
    Semester::viewListCourses();
    char inputID[MAXSTR+1];
    cout << "What course ID do you want to update?\n";
    cin.get(inputID, MAXSTR+1, '\n');
    listCourses.remove(Course("???", inputID), cmp_course);
    
    cout << "Do not have this course ID.\n";
}

