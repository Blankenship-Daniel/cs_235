#ifndef GPA_H_
#define GPA_H_

#include "GPAInterface.h"
#include "Student.h"
#include <fstream>
#include <cctype>
#include <vector>
#include <iostream>
#include <stdlib.h>
#include <algorithm>

class GPA : public GPAInterface
{
    public:
        GPA();
        ~GPA();
        
        map<unsigned long long int, StudentInterface*> getMap();
        set<StudentInterface*, Comparator> getSet();
        bool importStudents(string mapFileName, string setFileName);
        bool importGrades(string fileName);
        string querySet(string fileName);
        string queryMap(string fileName);
        void clear();

        void setMap(map<unsigned long long int, StudentInterface*> newMap);

        struct find_by_id
        {
            find_by_id(unsigned long long int id) : id(id) {}
            bool operator()(StudentInterface* student)
            {
                return student->getID() == id;
            }
            private:
                unsigned long long int id;
        };

    private:
        map<unsigned long long int, StudentInterface*> student_info_map;
        set<StudentInterface*, Comparator> student_info_set;

        // private functions
        bool isValidID(string id);
        bool isValidName(string name);
        bool isValidAddress(string address);
        bool isValidPhoneNumber(string number);
        bool isValidClassName(string className);
        bool isValidLetterGrade(string letterGrade);
        bool processStudentFile(string fileName);
        bool processGradesFile(string fileName);
        void importGradesToMap(string fileName);
        void importGradesToSet(string fileName);
        double convertLetterGradeToGPA(string letterGrade);
        unsigned long long int convert(string str);
};

#endif
