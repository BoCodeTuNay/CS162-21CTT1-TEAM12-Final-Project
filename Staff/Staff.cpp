#include "Staff.h"
#include "..\Student\Student.h"
#include "..\Constants\Constants.h"
#include "..\List\List.h"
#include "..\Schoolyear\Schoolyear.h"
#include "../Constants/Constants.h"

// Create a school year
void Staff::createSchoolYear(List <Schoolyear> &listSchoolyears)
{
    Schoolyear newSchoolYear;
    cout << "What school year you want to create (example: 2021-2022)?\n";
    cin>>newSchoolYear.ID;
    for (Node<Schoolyear> *schoolyear = listSchoolyears.begin(); schoolyear != nullptr; schoolyear = schoolyear->pNext) {
        if (schoolyear->data.ID == newSchoolYear.ID){
            cout<<"This school year already exists.\n";
            return;
        }
    }
    listSchoolyears.insert(newSchoolYear);
    // current_year_index = listSchoolyears.size()-1;
}

// Create several classes for 1st year students
void Staff::createClasses(List <Class> &classes){
    // do create class  
    Class newClass;
    newClass.createClass();
    classes.insert(newClass);
}

// Add new 1st year students to 1st-year classes
void Staff::addStudentToClasses(){
    // do add student to class
}

// At the beginning of a semester:

// Create a semester: 1, 2, or 3, school year, start date, end date
void Staff::createSemester(List <Schoolyear> &listSchoolyears){
    char scyear[YEARLENGTH+1];
    do{
        if (listSchoolyears.size() == 0){
            cout << "You don't have any school year yet.\n";
            return;
        }
        cout << "What school year of this semester (example: 2021-2022)?\n";
        cin>>scyear;
        for (Node<Schoolyear>* schoolyear = listSchoolyears.begin(); schoolyear != nullptr; schoolyear = schoolyear->pNext){
            if (schoolyear->data.ID==scyear){
                schoolyear->data.createSemester();
                return;
            }
        }
        cout << "Do not have this school year or your school year invalid. Please try again.\n";
    } while (strlen(scyear) != 9 || scyear[4] != '-');
}

// Add a course to this semester
// input school year and semester, add course to semester in school year
void addCourseToSemester(List <Schoolyear> &listSchoolyears){
    if (listSchoolyears.size() == 0){
        cout << "You don't have any school year yet.\n";
        return;
    }
    Schoolyear schoolYear=listSchoolyears.get(getCurrentYearIndex());
    Course newCourse;
    newCourse.inputCourses();
    schoolYear.yearSemesters[schoolYear.currentSemester-1].listCourses.insert(newCourse);
}

// View the list of courses
void viewListCourses(List <Schoolyear> &listSchoolyears){
    if (listSchoolyears.size() == 0){
        cout << "You don't have any school year yet.\n";
        return;
    }
    Schoolyear schoolYear=listSchoolyears.get(getCurrentYearIndex());
    for (Node<Course>*currentCourse = schoolYear.yearSemesters[schoolYear.currentSemester - 1].listCourses.begin(); currentCourse != nullptr; currentCourse = currentCourse->pNext){
        currentCourse->data.viewCourses();
    }
}

// Update course information
void updateCourseInfomation(List <Schoolyear> &listSchoolyears){
    if (listSchoolyears.size() == 0){
        cout << "You don't have any school year yet.\n";
        return;
    }
    string courseID;
    cout << "What course ID do you want to update?\n";
    cin>>courseID;
    Schoolyear schoolYear=listSchoolyears.get(getCurrentYearIndex());
    for (Node<Course>* currentCourse = schoolYear.yearSemesters[schoolYear.currentSemester - 1].listCourses.begin(); currentCourse != nullptr; currentCourse = currentCourse->pNext){
        if (currentCourse->data.ID == courseID){
            currentCourse->data.updateCourse();
            return;
        }
    }
    cout << "Do not have this course ID.\n";
}

bool cmp_course(const Course& c1, const Course& c2)
{
    return (strcmp(c1.ID, c2.ID));
}
// Delete a course by ID
void deleteCourse(List <Schoolyear> &listSchoolyears){
    if (listSchoolyears.size() == 0){
        cout << "You don't have any school year yet.\n";
        return;
    }
    string courseID;
    cout << "What course ID do you want to delete?\n";
    cin>>courseID;
    Schoolyear schoolYear=listSchoolyears.get(getCurrentYearIndex());
    for (Node<Course>* currentCourse = schoolYear.yearSemesters[schoolYear.currentSemester - 1].listCourses.begin(); currentCourse != nullptr; currentCourse = currentCourse->pNext){
        if (currentCourse->data.ID == courseID){
            schoolYear.yearSemesters[schoolYear.currentSemester-1].listCourses.remove(currentCourse->data,cmp_course);
            return;
        }
    }
    cout << "Do not have this course ID.\n";
}

// At the end of a semester, an academic staff member can:

// Export a list of students in a course to a CSV file
void exportListStudentsToCSVFile();

// Import the scoreboard of a course
void importScoreboard();

// View the scoreboard of a course
void viewScoreboardOfCourse();

// Update student result
void updateStudentResult();

// View the scoreboard of a class
void viewScoreboardOfClass();

void staffMenu(Staff& curStaff)
{
    clrscr();
    std::cout << "0. Manage schoolyears.\n"
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
    
}