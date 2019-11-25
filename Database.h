#include <iostream>
#include "Faculty.h"

using namespace std;

class Database
{
public:
    BST<Student*> *masterStudent;
    BST<Faculty*> *masterFaculty;

    Database();

    void PrintAllStudents();
    void AddNewStudent(Student* s);
    Student* GetStudentInfo();

    
    void PrintAllFaculty();

};
