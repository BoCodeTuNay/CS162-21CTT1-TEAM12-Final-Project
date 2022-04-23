#include "Staff.h"

// 1. Create a school year
void createSchoolYear(List <Schoolyear> &listSchoolyears)
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
    newSchoolYear.index = listSchoolyears.size();
    listSchoolyears.insert(newSchoolYear);
}

// 2. Create several classes for 1st year students
void createClasses(List <Class> &classes){
    // do create class  
    Class newClass;
    newClass.inputClass();
    classes.insert(newClass);
}

// 3. Add new 1st year students to 1st-year classes
void addStudentToClasses(Class &class){
    // do add student to class
    class.addStudent();
}

// 4. Add students by CSV file
void importStudentFromCSVFile(Class &class)
{
    class.importStudentFile();
}

// At the beginning of a semester:

// 6. Create a semester: 1, 2, or 3, school year, start date, end date
void createSemester(Schoolyear &schoolyear){
    schoolyear.createSemester();
    // char scyear[YEARLENGTH+1];
    // do{
    //     if (listSchoolyears.size() == 0){
    //         cout << "You don't have any school year yet.\n";
    //         return;
    //     }
    //     cout << "What school year of this semester (example: 2021-2022)?\n";
    //     cin>>scyear;
    //     for (Node<Schoolyear>* schoolyear = listSchoolyears.begin(); schoolyear != nullptr; schoolyear = schoolyear->pNext){
    //         if (schoolyear->data.ID==scyear){
    //             schoolyear->data.createSemester();
    //             return;
    //         }
    //     }
    //     cout << "Do not have this school year or your school year invalid. Please try again.\n";
    // } while (strlen(scyear) != 9 || scyear[4] != '-');
}

// 7, 8. Add a course to this semester
// input school year and semester, add course to semester in school year
void addCourseToSemester(Semester &semester, List <CourseInfo> &listRegis){
    CourseInfo newCourseInfo;
    newCourseInfo.inputCourseInfo();
    Course newCourse;
    newCourse.info = newCourseInfo;
    semester.listCourses.insert(newCourse);
    listRegis.insert(newCourseInfo);
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
