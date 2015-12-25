#include "Pathfinder.h"

Pathfinder::Pathfinder()
{
    for (int z = 0; z < Z; z++)
        for (int y = 0; y < Y; y++)
            for (int x = 0; x < X; x++)
            {
                MazeLocation m(false, "1");
                maze[x][y][z] = m;   
            }
}

void Pathfinder::resetMaze()
{
    for (int z = 0; z < Z; z++)
        for (int y = 0; y < Y; y++)
            for (int x = 0; x < X; x++)
            {
                MazeLocation m(false, "1");
                maze[x][y][z] = m;
            }
}

string Pathfinder::getMaze()
{
    string newMaze;
    
    for (int z = 0; z < Z; z++)
        for (int y = 0; y < Y; y++)
            for (int x = 0; x < X; x++)
            {
                MazeLocation m = maze[x][y][z];
                newMaze += m.get_val();
            }
    
    newMaze = formatMaze(newMaze);
    
    return newMaze;
}

void Pathfinder::createRandomMaze()
{
    
    for (int z = 0; z < Z; z++)
       for (int y = 0; y < Y; y++)
           for (int x = 0; x < X; x++)
           {
                int num = rand() % 2;

                string s_num;
                ostringstream convert;
                
                convert << num;
                s_num = convert.str();
                
                MazeLocation m(false, s_num);
                maze[x][y][z] = m;
           }
    
    MazeLocation m(false, "1");
    maze[0][0][0] = m;
    maze[4][4][4] = m;
}

string Pathfinder::formatMaze(string curr_maze)
{
    string newMaze;

    for (int i = 1; i <= curr_maze.length(); i++)
    {
        if (i % 25 != 0)
        {
            if (i % 5 != 0)
            {
                newMaze += curr_maze[i - 1];
                newMaze += " ";
            }
            else
            {
                newMaze += curr_maze[i - 1];
                newMaze += "\n";
            }
        }
        else if (i != curr_maze.length())
        {
            newMaze += curr_maze[i - 1];
            newMaze += "\n\n";
        }
        else
        {
            newMaze += curr_maze[i - 1];
            newMaze += "\n";
        }
    }
    return newMaze;
}

bool Pathfinder::validMaze(string curr_maze)
{
    if (curr_maze[0] != '1' || curr_maze[curr_maze.length()-1] != '1' || curr_maze.length() != 125)
        return false;

    return true;
}

void Pathfinder::setMaze(string curr_maze)
{
    int x = 1;
    int y = 1;
    int z = 1;

    for (int i = 1; i <= curr_maze.length(); i++)
    {
        string loc = string(1, curr_maze[i - 1]);
        MazeLocation m(false, loc);
        maze[x - 1][y - 1][z - 1] = m;
        
        if (x == X)
        {
            x = 1;
            y++;
        }
        else
        {
            x++;
        }

        if (i % 25 == 0)
        {
            y = 1; 
            z++;
        }
    } 
}

bool Pathfinder::importMaze(string file_name)
{
    string piece;
    stringstream ss;
    ifstream myfile(file_name.c_str());
    
    if (myfile.is_open())
    {
        string curr_maze;
        ss << myfile.rdbuf();
        
        while (ss >> piece)
            curr_maze += piece;

        if (!validMaze(curr_maze))
        {
            return false;
        }
        setMaze(curr_maze);
        return true;
    }
    else
    {
        return false;
    }
}

bool Pathfinder::findMazePath(int x, int y, int z)
{
    string string_x, string_y, string_z;
    stringstream ss;
    ss << x << " " << y << " " << z;
    ss >> string_x >> string_y >> string_z;
    
    /*
    ostringstream convert_x;
    string string_x;
    convert_x << x;
    string_x = convert_x.str();

    ostringstream convert_y;
    string string_y;
    convert_y << y;
    string_y = convert_y.str();

    ostringstream convert_z;
    string string_z;
    convert_z << z;
    string_z = convert_z.str();
    */
    
    // cell is out of bonds
    if (x < 0 || x >= X ||
        y < 0 || y >= Y ||
        z < 0 || z >= Z)
    {
        return false;
    } // found maze exit
    else if (x == X - 1 && y == Y - 1 && z == Z - 1)
    {
        maze[x][y][z].set_visited(true);
        mazeStack.push("(" + string_x + ", " + string_y + ", " + string_z + ")");
        return true;
    } // barrier has been reached
    else if (maze[x][y][z].get_val() != "1")
    {
        return false;
    } // check to see if visited
    else if (maze[x][y][z].get_visited())
    {
        return false;
    }
    else
    {
        maze[x][y][z].set_visited(true);
        
        if (findMazePath(x, y, z + 1) || findMazePath(x, y, z - 1) || 
            findMazePath(x - 1, y, z) || findMazePath(x + 1, y, z) ||
            findMazePath(x, y + 1, z) || findMazePath(x, y - 1, z))
        {
            mazeStack.push("(" + string_x + ", " + string_y + ", " + string_z + ")");
            return true;
        }
    }
    return false;
}

void Pathfinder::printMaze()
{
    for (int i = 0; i < mazePath.size(); i++)
    {
        cout << mazePath.at(i) << endl;
    }
}

vector<string> Pathfinder::solveMaze()
{
    for (int z = 0; z < Z; z++)
        for (int y = 0; y < Y; y++)
            for (int x = 0; x < X; x++)
            {
                maze[x][y][z].set_visited(false);
            }
 
    mazePath.clear();

    findMazePath(0, 0, 0);

    while (!mazeStack.empty())
    {
        mazePath.push_back(mazeStack.top());
        mazeStack.pop();
    }

    return mazePath;
}

