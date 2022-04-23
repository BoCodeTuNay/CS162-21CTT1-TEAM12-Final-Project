// #include "Constants.h"

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