#ifndef STUDENT_H_
#define STUDENT_H_

#include "StudentInterface.h"
#include <stdlib.h>
#include <sstream>
#include <iostream>
#include <iomanip>

class Student : public StudentInterface
{
    public:
        Student();
        Student(unsigned long long int new_id);
        ~Student();

        unsigned long long int getID();
        string getName();
        string getGPA();
        void addGPA(double classGrade);
        string toString();

        string getStringID();

        void setID(string new_id);
        void setStringID(string new_id);
        void setName(string new_name);
        void setAddress(string new_address);
        void setPhoneNumber(string new_number);


    private:
        unsigned long long int id;
        double gpa;
        int classesTaken;
        string name;
        string address;
        string phoneNumber;
        string stringID;
};

#endif
