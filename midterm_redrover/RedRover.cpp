//
// Daniel Blankenship
// CS 235 Fall Midterm
//

#include "RedRover.h"

RedRover::RedRover()
{

}

RedRover::~RedRover()
{

}

// CREATE ROSTER - Option 1
bool RedRover::createRoster(string filename)
{
    roster.clear();
    ifstream myRosterFile(filename.c_str());
    
    if (myRosterFile.is_open())
    {
        while (!myRosterFile.eof())
        {
            string name;
            getline(myRosterFile, name);
            string strength;
            getline(myRosterFile, strength);
            string speed;
            getline(myRosterFile, speed);

            int str = atoi(strength.c_str());
            int spd = atoi(speed.c_str());

            if (name != "")
            {
                roster.insert_back(name, str, spd);
            }
        }
    }
    else
    {
        cout << "\nFailed to open file...roster not created\n";
        return false;
    }
    cout << "\nRoster successfully created!\n";
    return true;
}

// VIEW ROSTER - Option 2
void RedRover::viewRoster()
{
    if (roster.size() > 0)
    {
        roster.print();
    }
    else
    {
        cout << "\nRoster is empty...\n";
    }
}

// SHUFFLE ROSTER - Option 3
void RedRover::shuffleRoster()
{
    if (roster.size() > 0)
    {
        cout << "\nRoster successfully shuffled!\n";
    }
    else
    {
        cout << "\nRoster is empty...\n";
        return;
    }
    int size = roster.size();
    Deque temp_roster;

    for (int i = 0; i < size; i++)
    {
        string name  = roster.getFrontName();
        int strength = roster.getFrontStrength();
        int speed    = roster.getFrontSpeed();
        temp_roster.insert_back(name, strength, speed);
        roster.remove_front();
    }

    for (int i = 0; i < size; i++)
    {
        string name  = temp_roster.getFrontName();
        int strength = temp_roster.getFrontStrength();
        int speed    = temp_roster.getFrontSpeed();

        int random = rand() % 2 + 1;
        if (random == 1)
        {
            roster.insert_front(name, strength, speed);                       
        }
        else
        {
            roster.insert_back(name, strength, speed);
        }
        temp_roster.remove_front();
    }

    temp_roster.clear();
}

// CREATE TEAMS - Option 4
void RedRover::createTeams()
{
    teamA.clear();
    teamB.clear();
    int size = 0;
    
    if (roster.size() % 2 == 0)
    {
        size = roster.size();  
    }
    else
    {
        size = roster.size() - 1; 
    }

    if (size < 4)
    {
        cout << "\nNot enough players on roster...teams not created.\n";
        return;
    }
    for (int i = 0; i < size; i++)
    {
        string name  = roster.getFrontName();
        int strength = roster.getFrontStrength();
        int speed    = roster.getFrontSpeed();
        roster.remove_front();

        if (i % 2 == 0)
        {
            teamA.insert_back(name, strength, speed);
        }
        else
        {
            teamB.insert_back(name, strength, speed);
        }
    }
    cout << "\nTeams successfully created!\n";
}

// VIEW TEAMS - Option 5
void RedRover::viewTeams()
{
    cout << "Team A:\n";
    teamA.print();
    cout << "Team B:\n";
    teamB.print();
}

// USER PLAY - Option 6
void RedRover::userPlay()
{
    do
    {
        if (teamA.size() > 1 && teamB.size() > 1)
        {
            teamATurn();
        }
        else
        {
            break;
        }
        if (teamA.size() > 1 && teamB.size() > 1)
        {
            teamBTurn();
        }
        else
        {
            break;
        }
    }
    while (teamA.size() > 1 && teamA.size() > 1);

    cout << endl;
    cout << "//" << endl
         << "// RESULTS\n"
         << "//\n"
         << "///////////////////\n\n";
    
    cout << "Team A: ";
    teamA.printNames();
    cout << "Team B: ";
    teamB.printNames();
    
    if (teamA.size() > teamB.size())
    {
        cout << "\nAnd the winner is...Team A!\n";
    }
    else
    {
        cout << "\nAnd the winner is...Team B!\n";
    }
}

// -- PRIVATE FUNCTIONS

// team a turn
void RedRover::teamATurn()
{
    string nameA = "";
    string nameB = "";

    cout << endl;
    cout << "//" << endl
         << "// NEW ROUND\n"
         << "//\n"
         << "///////////////////\n\n";
    
    cout << "Team A: ";
    teamA.printNames();
    cout << "Team B: ";
    teamB.printNames();
    cout << endl;

    do
    {
        cout << "Team A: ";
        teamA.printNames();
        cout << "\tPick: ";
        cin >> nameA;
    }
    while (!teamA.personExists(nameA));

    do
    {
        cout << "Team B: ";
        teamB.printNames();
        cout << "\tPick: ";
        cin >> nameB;
    }
    while (!teamB.personExists(nameB));

    int strA = teamA.getCurrStrength(nameA);
    int spdA = teamA.getCurrSpeed(nameA);

    string prevName = nameB;
    string nextName = teamB.getNameAfter(nameB);
    if (nextName == "NULL")
    {
        prevName = teamB.getNameBefore(nameB);
        nextName = nameB;
    }
    int beforeStr = teamB.getCurrStrength(prevName);
    int beforeSpd = teamB.getCurrSpeed(prevName);
    int afterStr = teamB.getCurrStrength(nextName);
    int afterSpd = teamB.getCurrSpeed(nextName);

    int aPower = strA + spdA;
    int bPower = beforeStr + afterStr;

    if (aPower > bPower)
    {
        if (beforeStr > afterStr)
        {
            teamA.insert(nameA, prevName, beforeStr, beforeSpd);
            teamB.remove(prevName);
        }
        else
        {
            teamA.insert(nameA, nextName, afterStr, afterSpd);
            teamB.remove(nextName);
        }
    }
    else
    {
        teamB.insert(prevName, nameA, strA, spdA);
        teamA.remove(nameA);
    }
}

// team b turn
void RedRover::teamBTurn()
{
    string nameA = "";
    string nameB = "";
    
    cout << endl;
    cout << "//" << endl
         << "// NEW ROUND\n"
         << "//\n"
         << "///////////////////\n\n";
 
    cout << "Team A: ";
    teamA.printNames();
    cout << "Team B: ";
    teamB.printNames();
    cout << endl;
    
    do
    {
        cout << "Team B: ";
        teamB.printNames();
        cout << "\tPick: ";
        cin >> nameB;
    }
    while (!teamB.personExists(nameB));

    do
    {
        cout << "Team A: ";
        teamA.printNames();
        cout << "\tPick: ";
        cin >> nameA;
    }
    while (!teamA.personExists(nameA));

    int strB = teamB.getCurrStrength(nameB);
    int spdB = teamB.getCurrSpeed(nameB);

    string prevName = nameA;
    string nextName = teamA.getNameAfter(nameA);
    if (nextName == "NULL")
    {
        prevName = teamA.getNameBefore(nameA);
        nextName = nameA;
    }
    int beforeStr = teamA.getCurrStrength(prevName);
    int beforeSpd = teamA.getCurrSpeed(prevName);
    int afterStr = teamA.getCurrStrength(nextName);
    int afterSpd = teamA.getCurrSpeed(nextName);

    int bPower = strB + spdB;
    int aPower = beforeStr + afterStr;

    if (bPower > aPower)
    {
        if (beforeStr > afterStr)
        {
            teamB.insert(nameB, prevName, beforeStr, beforeSpd);
            teamA.remove(prevName);
        }
        else
        {
            teamB.insert(nameB, nextName, afterStr, afterSpd);
            teamA.remove(nextName);
        }
    }
    else
    {
        teamA.insert(prevName, nameB, strB, spdB);
        teamB.remove(nameB);
    }
}
