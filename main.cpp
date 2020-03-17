#include "display.h"

int main()
{
    srand((unsigned)time(NULL));
    int choice;
    while (1)
    {
        choice = display_choice();
        if (choice == 1)
            dpll_branch();
        else if (choice == 2)
            sodoku_branch();
        else
            break;
    }
    cout << "always welcome" << endl;
    return 0;
}
