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
    clrscr();
    
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