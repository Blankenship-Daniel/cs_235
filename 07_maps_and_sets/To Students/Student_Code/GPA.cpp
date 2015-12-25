#include "GPA.h"

/******************************************
 * PUBLIC FUNCTIONS
 *****************************************/

// constructor
GPA::GPA()
{

}

// destructor
GPA::~GPA()
{
    clear();
}

// returns the student info map
map<unsigned long long int, StudentInterface*> GPA::getMap()
{
    return student_info_map;
}

// returns the student info set
set<StudentInterface*, Comparator> GPA::getSet()
{
    return student_info_set;
}

// imports a list of students to the student info map and set 
bool GPA::importStudents(string mapFileName, string setFileName)
{
    ifstream myMapFile(mapFileName.c_str());
    ifstream mySetFile(setFileName.c_str());

    if (myMapFile.is_open())
    {
        bool valid_map_file = processStudentFile(mapFileName);
        bool valid_set_file = processStudentFile(setFileName);
        
        if (!valid_map_file || !valid_set_file)
        {
            return false;
        }
        else
        {
            string str;
            vector<string> students;

            while(getline(myMapFile, str))
            {
                students.push_back(str);
            }
            while(!students.empty())
            {
                Student* s = new Student();
                unsigned long long int id;
                
                s->setID(students.at(0));
                id = s->getID();
                s->setName(students.at(1));
                s->setAddress(students.at(2));
                s->setPhoneNumber(students.at(3));

                students.erase(students.begin());
                students.erase(students.begin());
                students.erase(students.begin());
                students.erase(students.begin());

                student_info_map.insert(pair<unsigned long long int, StudentInterface*>(id, s));   
            }
        }
    }
    else
    {
        return false;
    }

    if (mySetFile.is_open())
    {
        bool valid_set_file = processStudentFile(setFileName);
        bool valid_map_file = processStudentFile(mapFileName);

        if (!valid_set_file || !valid_map_file)
        {
            return false;
        }
        else
        {
            string str;
            vector<string> students;

            while(getline(mySetFile, str))
            {
                students.push_back(str);
            }
            while(!students.empty())
            {
                Student* s = new Student();
                
                s->setID(students.at(0));
                s->setName(students.at(1));
                s->setAddress(students.at(2));
                s->setPhoneNumber(students.at(3));
                
                students.erase(students.begin());
                students.erase(students.begin());
                students.erase(students.begin());
                students.erase(students.begin());

                student_info_set.insert(s);
            }
        }
    }
    else 
    {
        return false;
    }
    return true;
}

// imports the grades in and figures the students GPAs
bool GPA::importGrades(string fileName)
{
    ifstream gradesFile(fileName.c_str());
    
    if (gradesFile.is_open())
    {
        bool valid_file = processGradesFile(fileName);
        if (!valid_file)
            return false;
        else
        {
            importGradesToMap(fileName);
            importGradesToSet(fileName);
        }
    }
    else
    {
        return false;
    }
    return true;
}

string GPA::querySet(string fileName)
{
    string str;
    stringstream ss;
    set<StudentInterface*, Comparator>::iterator result;
    ifstream queryFile(fileName.c_str());

    if(queryFile.is_open())
    {
        while (getline(queryFile, str))
        {
            if (!isValidID(str))
            {
                return "";
            }
            else
            {
                unsigned long long int id = convert(str);
                result = find_if(student_info_set.begin(),
                                 student_info_set.end(),
                                 find_by_id(id));
                
                if (result != student_info_set.end())
                {
                    ss << (*result)->getID() << " " << (*result)->getGPA() << " " << (*result)->getName() << endl;
                }
            }
        }
    }
    else
    {
        return "";
    }
    return ss.str();
}

string GPA::queryMap(string fileName)
{
    string str;
    stringstream ss;
    map<unsigned long long int, StudentInterface*>::iterator result;
    ifstream queryFile(fileName.c_str());

    if(queryFile.is_open())
    {
        while (getline(queryFile, str))
        {
            if (!isValidID(str))
            {
                return "";
            }
            else
            {
                unsigned long long int id = convert(str);
                result = student_info_map.find(id);
                
                if (result != student_info_map.end())
                {
                    ss << result->second->getID() << " " << result->second->getGPA() << " " << result->second->getName() << endl;
                }
            }
        }
    }
    else
    {
        return "";
    }
    return ss.str();
}

// clear the contents of the map and set
void GPA::clear()
{
    for (map<unsigned long long int, StudentInterface*>::iterator it = student_info_map.begin();
         it != student_info_map.end(); ++it)
    {
        delete it->second;
    }
    student_info_map.clear();

    for (set<StudentInterface*, Comparator>::iterator it = student_info_set.begin();
         it != student_info_set.end(); ++it)
    {
        delete *it;
    }
    student_info_set.clear();
}

void GPA::setMap(map<unsigned long long int, StudentInterface*> newMap)
{
    student_info_map = newMap;
}

/******************************************
 * PRIVATE FUNCTIONS
 *****************************************/

// checks string to see if valid id
bool GPA::isValidID(string id)
{
    for (int i = 0; i < id.length(); i++)
    {
        if (!isdigit(id[i]) || id[i] == '-')
            return false;
    }
    if (id == "")
        return false;

    return true;
}

// checks string to see if valid name
bool GPA::isValidName(string name)
{
    for (int i = 0; i < name.length(); i++)
    {
        if (isdigit(name[i]))
            return false;
    }
    if (name == "")
        return false;

    return true;
}

// checks string to see if valid address
bool GPA::isValidAddress(string address)
{
    if (isValidID(address) || isValidName(address) || isValidPhoneNumber(address) || address == "")
        return false;

    return true;
}

// checks string to see if valid phone number
bool GPA::isValidPhoneNumber(string number)
{
    if (isValidID(number) || number == "")
        return false;

    for (int i = 0; i < number.length(); i++)
    {
        if (isalpha(number[i]))
            return false;
    }
    return true;
}

// checks string to see if valid class name
bool GPA::isValidClassName(string className)
{
    return (isValidAddress(className) || isValidID(className));
}

// checks string to see if valid letter grade
bool GPA::isValidLetterGrade(string letterGrade)
{
    return isValidName(letterGrade);
}

// checks student file to see if the info is valid
bool GPA::processStudentFile(string fileName)
{
    ifstream file(fileName.c_str());

    string str;
    int count = 1;

    while(getline(file, str))
    {
        if (count == 1)
        {
            bool valid_id = isValidID(str);
            if (!valid_id)
                return false;
            else
                count++;
        }
        else if (count == 2)
        {
            bool valid_name = isValidName(str);
            if (!valid_name)
                return false;
            else
                count++;
        }
        else if (count == 3)
        {
            bool valid_address = isValidAddress(str);
            if (!valid_address)
                return false;
            else count++;
        }
        else if (count == 4)
        {
            bool valid_phone_number = isValidPhoneNumber(str);
            if (!valid_phone_number)
                return false;
            else
                count = 1;
        }
    }
    if (count != 1)
        return false;

    return true;
}

// checks the grades file to see if the info is valid
bool GPA::processGradesFile(string fileName)
{
    ifstream file(fileName.c_str());

    string str;
    int count = 1;

    while(getline(file, str))
    {
        if (count == 1)
        {
            bool valid_id = isValidID(str);
            if (!valid_id)
                return false;
            else
                count++;
        }
        else if (count == 2)
        {
            bool valid_class = isValidClassName(str);
            if (!valid_class)
                return false;
            else
                count++;
        }
        else if (count == 3)
        {
            bool valid_grade = isValidLetterGrade(str);
            if (!valid_grade)
                return false;
            else 
                count = 1;
        }
    }
    if (count != 1)
        return false;

    return true;
}

unsigned long long int GPA::convert(string str)
{
    char *pEnd;
    unsigned long long int temp = strtoull(str.c_str(), &pEnd, 10);
    return temp;
}

void GPA::importGradesToMap(string fileName)
{
    ifstream file(fileName.c_str());
    StudentInterface* foundStudent = NULL;

    while (!file.eof())
    {
        string idStr;
        getline(file, idStr);
	    string classStr;
	    getline(file, classStr);
	    string grade;
	    getline(file, grade);
       
        if (isValidID(idStr))
        {
            unsigned long long int id = convert(idStr);
            for (map<unsigned long long int, StudentInterface*>::iterator it = student_info_map.begin(); it != student_info_map.end(); ++it)
            {
                if (it->second->getID() == id)
                {
                    foundStudent = it->second;
                    break;
                }
            }
        }
        if (isValidLetterGrade(grade) && foundStudent != NULL)
        {
            double gpa = convertLetterGradeToGPA(grade);
            foundStudent->addGPA(gpa);
        }
        foundStudent = NULL;
    }
}

void GPA::importGradesToSet(string fileName)
{
    ifstream file(fileName.c_str());
    
    string str;
    StudentInterface* foundStudent = NULL;

    while (getline(file, str))
    { 
       if (isValidID(str))
       {
            unsigned long long int id = convert(str); 
            for (set<StudentInterface*, Comparator>::iterator it = student_info_set.begin(); it != student_info_set.end(); ++it)
            {
                if ((*it)->getID() == id)
                {
                    foundStudent = (*it);
                    break;
                }
            }
       }
       else if (isValidLetterGrade(str) && foundStudent != NULL)
       {
            double gpa = convertLetterGradeToGPA(str);
            foundStudent->addGPA(gpa);
            foundStudent = NULL;
       }
    }
}

double GPA::convertLetterGradeToGPA(string letterGrade)
{
    double gpa = 0;

    if (letterGrade == "A") 
        gpa = 4.0;
    else if (letterGrade == "A-")
        gpa = 3.7;
    else if (letterGrade == "B+")
        gpa = 3.4;
    else if (letterGrade == "B")
        gpa = 3.0;
    else if (letterGrade == "B-")
        gpa = 2.7;
    else if (letterGrade == "C+")
        gpa = 2.4;
    else if (letterGrade == "C")
        gpa = 2.0;
    else if (letterGrade == "C-")
        gpa = 1.7;
    else if (letterGrade == "D+")
        gpa = 1.4;
    else if (letterGrade == "D")
        gpa = 1.0;
    else if (letterGrade == "D-")
        gpa = 0.7;
    else if (letterGrade == "E")
        gpa = 0.0;

    return gpa;
}

