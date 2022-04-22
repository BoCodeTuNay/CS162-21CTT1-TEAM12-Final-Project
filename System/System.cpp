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

void clrscr()
{
    std::cout << "\033[2J\033[1;1H";
}

int choose(int a, int b)
{
    using namespace std;
    char str[3];
    cin.get(str, 3, '\n');
    while (cin.fail() || cin.get() != '\n' || atoi(str) < a || atoi(str) > b) {
        cin.clear();
        fflush(stdin);
        cout << "Invalid choice. Please try again.\n";
        cout << "Your choice: ";
        cin.get(str, 3, '\n');
    }
    return atoi(str);
}

void signup()
{
    using namespace std;
    Student st;

    cout << "Name (max " << MAXSTR << " chars): ";
    cin.get(st.name, MAXSTR+1, '\n');
    while (cin.fail() || cin.get() != '\n' || !checkName(st.name)) {
        cin.clear();
        fflush(stdin);
        cout << "Invalid name. Please try again.\n";
        cout << "Name (max " << MAXSTR << " chars): ";
        cin.get(st.name, MAXSTR+1, '\n');
    }

    cout << "Email (max " << MAXSTR << " chars): ";
    cin.get(st.email, MAXSTR+1, '\n');
    while (cin.fail() || cin.get() != '\n' || !checkEmail(st.email)) {
        cin.clear();
        fflush(stdin);
        cout << "Invalid email. Please try again.\n";
        cout << "Email (max " << MAXSTR << " chars): ";
        cin.get(st.email, MAXSTR+1, '\n');
    }

    // From now on, the information below needs to be checked in the database first.

    cout << "ID (max " << MAXID << " chars): ";
    cin.get(st.id, MAXID+1, '\n');
    while (cin.fail() || cin.get() != '\n' || !checkDigit(st.id)) {
        cin.clear();
        fflush(stdin);
        cout << "Invalid ID. Please try again.\n";
        cout << "ID (max " << MAXID << " chars): ";
        cin.get(st.id, MAXID+1, '\n');
    }

    cout << "Username (max " << MAXSTR << " chars): ";
    cin.get(st.username, MAXSTR+1, '\n');
    while (cin.fail() || cin.get() != '\n' || !checkAlphaDigit(st.username)) {
        cin.clear();
        fflush(stdin);
        cout << "Invalid username. Please try again.\n";
        cout << "Username (max " << MAXSTR << " chars): ";
        cin.get(st.username, MAXSTR+1, '\n');
    }
    
    cout << "Password (max " << MAXSTR << " chars): ";
    cin.get(st.password, MAXSTR+1, '\n');
    while (cin.fail() || cin.get() != '\n' || !checkAlphaDigit(st.password)) {
        cin.clear();
        fflush(stdin);
        cout << "Invalid password. Please try again.\n";
        cout << "Password (max " << MAXSTR << " chars): ";
        cin.get(st.password, MAXSTR+1, '\n');
    }
}

void login()
{
    using namespace std;
    
    bool cont_out{false}; // to continue looping
    do {
        cout << endl;
        bool cont_in{false}; // to continue looping inside
        char username[MAXSTR+1];
        do {
            cout << "Username (max " << MAXSTR << " chars): ";
            cin.get(username, MAXSTR+1, '\n');
            if (cin.fail() || cin.get() != '\n' || !checkAlphaDigit(username)) {
                cin.clear();
                fflush(stdin);
                cout << "Invalid username. Please try again.\n";
                cont_in = true;
            }
            else cont_in = false;
        } while (cont_in);
        
        cont_in = false;
        char password[MAXSTR+1];
        do {
            cout << "Password (max " << MAXSTR << " chars): ";
            cin.get(password, MAXSTR+1, '\n');
            if (cin.fail() || cin.get() != '\n' || !checkAlphaDigit(password)) {
                cin.clear();
                fflush(stdin);
                cout << "Invalid password. Please try again.\n";
                cont_in = true;
            }
            else cont_in = false;
        } while (cont_in);

        if (!checkDatabase(username, password)) {
            cout << "\nThe account's information does not exist. Please try again.\n";
            cont_out = true;
        }
        else cont_out = false;
    } while (cont_out);

    
}

void load_data()
{
    using namespace std;
    fstream fin("Accounts.dat", ios::in | ios::binary);
    if (!fin.is_open()) return;

    unsigned int N;
    fin.read((char*)&N, sizeof(int));
    Student* std_arr = new Student[N];
    fin.read((char*)std_arr, N * sizeof(Student));
    for (int i = 0; i < N; ++i) {
        listStudents.insert(std_arr[i]);
    }
    delete[] std_arr;

    unsigned int M;
    fin.read((char*)&M, sizeof(int));
    Staff* staff_arr = new Staff[M];
    fin.read((char*)staff_arr, M * sizeof(Staff));
    for (int i = 0; i < M; ++i) {
        listStaffs.insert(staff_arr[i]);
    }
    delete[] staff_arr;

    fin.close();
}

void save_data()
{
    using namespace std;
    fstream fout("Accounts.dat", ios::out | ios::binary);
    if (!fout.is_open()) return;

    unsigned int N{listStudents.size()};
    fout.write((char*)&N, sizeof(int));
    Student* std_arr = new Student[N];
    int idx{0};
    for (Node<Student>* cur = listStudents.begin(); cur; cur = cur->pNext) {
        std_arr[idx++] = cur->data;
    }
    assert(idx == N);
    fout.write((char*)std_arr, N * sizeof(Student));
    delete[] std_arr;

    unsigned int M{listStaffs.size()};
    fout.write((char*)&M, sizeof(int));
    Staff* staff_arr = new Staff[M];
    idx = 0;
    for (Node<Staff>* cur = listStaffs.begin(); cur; cur = cur->pNext) {
        staff_arr[idx++] = cur->data;
    }
    assert(idx == M);
    fout.write((char*)staff_arr, M * sizeof(Staff));
    delete[] staff_arr;

    fout.close();
}

void loginScreen()
{
    clrscr();
    std::cout << "0. Log in\n";
    std::cout << "1. Sign up\n";
    std::cout << "Your choice: ";
    int t{choose(0, 1)};
    if (t == 0) {
        login();
    }
    else {
        signup();
    }
}

bool checkDatabase(const char* username, const char* password)
{
    auto cmp_std = [](const Student& std1, const Student& std2) -> bool {
        return strcmp(std1.username, std2.username) == 0 && strcmp(std1.password, std2.password) == 0;
    };
    Student std(username, password, 0, 0, 0);
    if (listStudents.search(std, cmp_std))
        return true;

    auto cmp_staff = [](const Staff& stf1, const Staff& stf2) -> bool {
        return strcmp(stf1.username, stf2.username) == 0 && strcmp(stf1.password, stf2.password) == 0;
    };
    Staff stf(username, password, 0, 0, 0);
    if (listStaffs.search(stf, cmp_staff))
        return true;
    
    return false;
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