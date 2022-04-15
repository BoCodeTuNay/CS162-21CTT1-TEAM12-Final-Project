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
                    else if (str[j+1] == 0) return false; // the period character cannot be in the end
                    else if (str[j-1] == '.') return false; // consecutive period characters are not allowed
                }
                else if (islower(str[j])) {
                    // do nothing
                }
                else return false;
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
    
    char str[3];
    cin.get(str, 2, '\n');
    while (cin.fail() || cin.get() != '\n' || !) {
        cin.clear();
        fflush(stdin);
        cout << "Invalid choice. Please try again.\n";
        cout << "Your choice: "
    }
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
    char username[MAXSTR+1];
    cout << "Username (max " << MAXSTR << " chars): ";
    cin.get(username, MAXSTR+1, '\n');
    while (cin.fail() || cin.get() != '\n' || !checkAlphaDigit(username)) {
        cin.clear();
        fflush(stdin);
        cout << "Invalid username. Please try again.\n";
        cout << "Username (max " << MAXSTR << " chars): ";
        cin.get(username, MAXSTR+1, '\n');
    }
    
    char password[MAXSTR+1];
    cout << "Password (max " << MAXSTR << " chars): ";
    cin.get(password, MAXSTR+1, '\n');
    while (cin.fail() || cin.get() != '\n' || !checkAlphaDigit(password)) {
        cin.clear();
        fflush(stdin);
        cout << "Invalid password. Please try again.\n";
        cout << "Password (max " << MAXSTR << " chars): ";
        cin.get(password, MAXSTR+1, '\n');
    }
}