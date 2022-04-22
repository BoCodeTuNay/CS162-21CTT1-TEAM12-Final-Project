#include "Semester.h"

void Semester::createCourseRegistration(List <CourseInfo>& listCourseInfo) {
    CourseInfo course;
    int check;
    do {
        course.enterCourseInfo();
        cout << "Are you sure about all of the information of the course you want to create? (0 for No and 1 for Yes): ";
        cin >> check;
    } while (check == 0);
    listCourseInfo.insert(course);
}
