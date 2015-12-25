#ifndef MAZELOCATION_H
#define MAZELOCATION_H

using namespace std;
#include <string>

class MazeLocation
{
    private:
        bool visited;
        string val;

    public:
        MazeLocation()
        {
            visited = false;
            val     = '1';
        }

        MazeLocation(bool visited, string val)
        {
            this->visited = visited;
            this->val     = val;
        }
        
        void set_visited(bool visited)
        {
            this->visited = visited;
        }

        bool get_visited()
        {
            return this->visited;
        }

        void set_val(int val)
        {
            this->val = val;
        }

        string get_val()
        {
            return this->val;
        }
};

#endif
