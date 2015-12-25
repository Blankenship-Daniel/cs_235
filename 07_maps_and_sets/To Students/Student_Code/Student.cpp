#include "Student.h"

Student::Student()
{
    gpa          = 0;
    classesTaken = 0;
    id           = 0;
    name         = "";
    address      = "";
    phoneNumber  = "";
    stringID     = "";
}

Student::Student(unsigned long long int new_id)
{
    gpa          = 0;
    classesTaken = 0;
    id           = new_id;
    name         = "";
    address      = "";
    phoneNumber  = "";
    stringID     = "";
}

Student::~Student()
{

}

unsigned long long int Student::getID()
{
    return id;
}

string Student::getName()
{
    return name;
}

string Student::getGPA()
{
    if (gpa == 0)
    {
        return "0.00";
    }
    
    stringstream ss;
    ss.precision(2);

    double tempGPA = 0;
    tempGPA = gpa / classesTaken;

    ss << fixed << tempGPA;
   
    return ss.str();
}

string Student::getStringID()
{
    return stringID;
}

void Student::setID(string new_id)
{
    char* pEnd;
    setStringID(new_id);
    id = strtoull(new_id.c_str(), &pEnd, 10);
}

void Student::setStringID(string new_id)
{
    stringID = new_id;
}   

void Student::setName(string new_name)
{
    name = new_name;
}

void Student::setAddress(string new_address)
{
    address = new_address;
}

void Student::setPhoneNumber(string new_number)
{
    phoneNumber = new_number;
}

void Student::addGPA(double classGrade)
{
    gpa += classGrade;
    classesTaken++;
}

string Student::toString()
{
    stringstream ss;
   
    ss << id << endl;
    ss << name << endl;
    ss << address << endl;
    ss << phoneNumber << endl;
    ss << getGPA();

    return ss.str();
}
