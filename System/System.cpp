#include "System.h"

bool checkName(const char* str)
{
    for (int i = 0; str[i]; ++i) {
        if (!isalpha(str[i]) && str[i] != ' ')
            return false;
    }
    return true;
}

bool checkAlphaDigit(const char* str)
{
    for (int i = 0; str[i]; ++i) {
        if (!isalpha(str[i]) && !isdigit(str[i]))
            return false;
    }
    return true;
}

bool checkDigit(const char* str)
{
    for (int i = 0; str[i]; ++i) {
        if (!isdigit(str[i]))
            return false;
    }
    return true;
}

bool checkEmail(const char* str)
{
    for (int i = 0; str[i]; ++i) {
        if (str[i] == '@') {
            if (i == 0 || str[i+1] == 0) return false;
            if (i > MAXSTR) return false; // the local-part is too long

            char local_part[MAXSTR+1];
            for (int j = 0; j < i; ++j) {
                local_part[j] = str[j];
            }
            local_part[i] = '\0';
            if (!checkAlphaDigit(local_part))
                return false;

            for (int j = i + 1; str[j]; ++j) {
                if (j - i > MAXSTR) return false; // the domain name is too long
                if (str[j] == '@') return false;
                else if (str[j] == '.') {
                    if (j == i + 1) return false; // the period character cannot be in the beginning
                    else if (str[j+1] == '\0') return false; // the period character cannot be in the end
                    else if (str[j-1] == '.') return false; // consecutive period characters are not allowed
                }
                else if (!islower(str[j])) return false; 
            }
            return true;
        }
    }
    return false;
}

void manageSchoolyears()
{
    // viewAllSchoolYears();
    // chooseSchoolYears();
    // if (choose == createSchoolYear)
    // {
    //     createSchoolYear(listSchoolyears);
    // }
    // else (choose == viewSchoolYearX)
    // {
    //     manageSemesters(schoolYearX);
    // }
    
    int N{0}; // number of commands in this screen
    for (Node<Schoolyear>* cur = Staff::listSchoolyears.begin(); cur; cur = cur->pNext) {
        std::cout << N++ << ". View schoolyear " << cur->data.ID << endl;
    }
    std::cout << N++ << ". Create a new schoolyear\n";
    std::cout << N++ << ". Go back\n";
    std::cout << std::endl;

    std::cout << "Your choice (press Enter to go back): ";
    
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

void login()
{
    using namespace std;
    clrscr();
    std::cout << "PLEASE LOG IN USING YOUR ID AND PASSWORD. KEEP PRESSING ENTER TO GO BACK.\n\n";
    
    bool cont_out{false}; // to continue looping
    char ID[MAXID+1]; ID[0] = 0;
    char password[MAXSTR+1]; password[0] = 0;
    do {
        cout << endl;
        bool cont_in{false}; // to continue looping inside
        do {
            cout << "ID (max " << MAXID << " chars): ";
            cin.get(ID, MAXID+1, '\n');
            if (cin.fail()) { // nothing was inputted
                cin.clear();
                fflush(stdin);
                break;
            }
            else if (cin.get() != '\n' || !checkDigit(ID)) {
                fflush(stdin);
                cout << "Invalid ID. Please try again.\n";
                cont_in = true;
            }
            else cont_in = false;
        } while (cont_in);
        
        cont_in = false;
        do {
            cout << "Password (max " << MAXSTR << " chars): ";
            cin.get(password, MAXSTR+1, '\n');
            if (cin.fail()) { // nothing was inputted
                cin.clear();
                fflush(stdin);
                break;
            }
            else if (cin.get() != '\n' || !checkAlphaDigit(password)) {
                cout << "Invalid password. Please try again.\n";
                cont_in = true;
            }
            else cont_in = false;
        } while (cont_in);

        if (!checkDatabase(ID, password)) {
            cout << "\nThe account's information does not exist. Please try again.\n";
            cont_out = true;
        }
        else cont_out = false;
    } while (cont_out);
    if (ID[0] == 0 && password[0] == 0) 

    if (checkDatabase(ID, password) == 1) {
        // go to Student's menu
    }
    else {
        staffMenu();
    }
}

bool loginScreen()
{
    clrscr();
    std::cout << "0. Log in\n"
                "1. Exit\n";
    int t{choose(0, 1)};
    if (t == 0) {
        login();
        return true;
    }
    else return false;
}

void loadAccounts()
{
    /*
    Cấu trúc quy ước của file Account database:
    N
    Accout of student 1
    Account of student 2
    ...
    Account of student N

    M
    Account of staff 1
    Account of staff 2
    ...
    Account of staff M
    */
    using namespace std;
    fstream fin(ACCOUNTS_FILE, ios::in | ios::binary);
    if (!fin.is_open()) return;

    unsigned int N;
    fin.read((char*)&N, sizeof(int));
    Account* arr = new Account[N];
    fin.read((char*)arr, N * sizeof(Account));
    for (int i = 0; i < N; ++i) {
        Student s;
        s.acc = arr[i];
        listStudents.insert(s);
    }
    delete[] arr;

    unsigned int M;
    fin.read((char*)&M, sizeof(int));
    arr = new Account[M];
    fin.read((char*)arr, M * sizeof(Account));
    for (int i = 0; i < N; ++i) {
        Staff s;
        s.acc = arr[i];
        listStaffs.insert(s);
    }
    delete[] arr;

    fin.close();
}

void saveAccounts()
{
    // Cấu trúc quy ước được ghi trong hàm loadAccounts()
    using namespace std;
    fstream fout(ACCOUNTS_FILE, ios::out | ios::binary);
    if (!fout.is_open()) return;

    unsigned int N{listStudents.size()};
    fout.write((char*)&N, sizeof(int));
    Account* std_arr = new Account[N];
    int idx{0};
    for (Node<Student>* cur = listStudents.begin(); cur; cur = cur->pNext) {
        std_arr[idx++] = cur->data.acc;
    }
    assert(idx == N);
    fout.write((char*)std_arr, N * sizeof(Account));
    delete[] std_arr;

    unsigned int M{listStaffs.size()};
    fout.write((char*)&M, sizeof(int));
    Account* staff_arr = new Account[M];
    idx = 0;
    for (Node<Staff>* cur = listStaffs.begin(); cur; cur = cur->pNext) {
        staff_arr[idx++] = cur->data.acc;
    }
    assert(idx == M);
    fout.write((char*)staff_arr, M * sizeof(Account));
    delete[] staff_arr;
    
    fout.close();
}

int checkDatabase(const char* ID, const char* password)
{
    for (Node<Student>* cur = listStudents.begin(); cur; cur = cur->pNext) {
        if (strcmp(cur->data.acc.ID, ID) == 0 && strcmp(cur->data.acc.password, password) == 0)
            return 1;
    }
    for (Node<Staff>* cur = listStaffs.begin(); cur; cur = cur->pNext) {
        if (strcmp(cur->data.acc.ID, ID) == 0 && strcmp(cur->data.acc.password, password) == 0)
            return 2;
    }
    return 0;
}

Student::Student(const char* usn, const char* pass, const char* nm, const char* i, const char* mail)
{
    strcpy(username, usn);
    strcpy(password, pass);
    strcpy(name, nm);
    strcpy(id, i);
    strcpy(email, mail);
}

Staff::Staff(const char* usn, const char* pass, const char* nm, const char* i, const char* mail)
{
    strcpy(username, usn);
    strcpy(password, pass);
    strcpy(name, nm);
    strcpy(id, i);
    strcpy(email, mail);
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