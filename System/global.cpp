#include "System.h"

// temporary Student and Staff

using namespace std;

int main()
{
    loadAccounts();
    login();

    return 0;
}

void studentMenu(Student &student)
{
    // CourseInfo courseInfo = student.enrollCourse(listRegisCourses); // return courseInfo
    // Schoolyear &schoolyearX = getSchoolyearByID(courseInfo.schoolyearID);
    // Semester &semesterX = getSemesterByID(courseInfo.semesterID);
    // Course &courseX = getCourseByID(courseInfo.ID);
    // courseX.addStudent(student);

    CourseInfo coursein4 = student.enrolledCourse(listRegisCourses);
    Course &courseX = listSchoolyears.get(coursein4.schoolyearID).listSemesters.get(coursein4.semesterID).listCourses.get(coursein4.ID);
    courseX.updateCourseStudent(student.profile);
    // add student to student list of courseX

}

void staffMenu()
{
    clrscr();
    cout << "0. Manage schoolyears.\n"
                "1. Manage classes.\n"
                "2. View profile.\n"
                "3. Log out.\n";
    int t{choose(0, 3)};
    if (t == 0) {
        manageSchoolyears();
    }
    else if (t == 1) {
        manageClasses();
    }
    else if (t == 2) {
        // view the profile of the current staff, should be an independent function to do this
        // create a new struct named staffInfo if necessary, but I doubt not
        // including the change-password feature -> shouldn't be a problem
    }
    else {
        // go back to loginScreen()
    }
}

void manageSchoolyears()
{
    viewAllSchoolYears();
    chooseSchoolYears();
    if (choose == createSchoolYear)
    {
        createSchoolYear(listSchoolyears);
    }
    else (choose == viewSchoolYearX)
    {
        manageSemesters(schoolYearX);
    }
    
}

void manageSemesters(Schoolyear &schoolyearX)
{
    viewAllSemester();
    chooseSemesters();
    if (choose == createSemester)
    {
        createSemester(schoolyearX.listSemester);
    }
    else(choose == semesterX)
    {
        manageCourse(semesterX);
    }
}

void manageSemesterX(Semester &semesterX)
{
    viewAllCourse();
    choose();
    semesterX.createCourseRegistration(listRegisCourses);
    // add course to this semester
}

// bỏ Profile -> account
// sửa mảng semester trong schoolyear
// courseRegistration() -> add course
// enrollCourse() // update accountList in course
// unEnrollCourse() // update accountList in course
// ID đổi thành index (chỉ số mảng)
