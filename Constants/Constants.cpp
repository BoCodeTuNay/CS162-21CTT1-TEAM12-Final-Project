// #include "Constants.h"

void clrscr()
{
    system("cls");
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