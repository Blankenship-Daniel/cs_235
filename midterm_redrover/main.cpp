//
// Daniel Blankenship
// CS 235 Fall Midterm
//

#include "RedRover.h"

/******************************
 * MENU CONTROL
 * manages menu input.
 *****************************/
bool menuControl(string input, string filename, RedRover & roster)
{
    bool valid = false;

    if (input == "1")
    {
        return roster.createRoster(filename); 
    }
    else if (input == "2")
    {
        roster.viewRoster();
        return true;
    }
    else if (input == "3")
    {
        roster.shuffleRoster();
        return true;
    }
    else if (input == "4")
    {
        roster.createTeams();
        return true;
    }
    else if (input == "5")
    {
        roster.viewTeams();
        return true;
    }
    else if (input == "6")
    {
        roster.userPlay();
        return true;
    }
    else if (input == "7")
    {
        cout << "Extra Credit Not Implemented...\n";
        return true;
    }
    else if (input == "8")
    {
        return false;
    }
    return true;
}

/***************************
 * MAIN
 * a simple driver program.
 **************************/
int main()
{
    srand(time(NULL));
    
    string filename = "roster.txt";
    bool valid = false;
    string input = "";
    RedRover roster;
    do
    {
        cout << endl << "//" << endl
             << "// RED ROVER MENU" << endl
             << "//" << endl
             << "/////////////////////////////" << endl << endl
             << "1. Create Roster" << endl
             << "2. View Roster" << endl
             << "3. Shuffle Roster" << endl
             << "4. Create Teams" << endl
             << "5. View Teams" << endl
             << "6. User Play" << endl
             << "7. Auto Play" << endl
             << "8. Quit" << endl;
        cin >> input;
        valid = menuControl(input, filename, roster);
    }
    while (valid);

    return 0;
}
