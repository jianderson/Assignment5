#include <iostream>
#include "Faculty.h"

using namespace std;

class Database
{
public:
    //both the main student and faculty trees
    BST<Student*> *masterStudent;
    BST<Faculty*> *masterFaculty;
//database constructor and desctructor
    Database();
    ~Database();
//methods
    void PrintAllStudents();
    void AddNewStudent(Student* s);
    Student* GetStudentInfo();
    Faculty* GetFacultyInfo();
    Student* FindStudentByID(int studentID);
    Student* DeleteStudent(int studentID);
//more methods
    Faculty* GetStudentAdvisorInfo(int studentID);
    void AddNewFaculty(Faculty* f);
    Faculty* DeleteFaculty(int facultyID);
    void PrintAllFaculty();
    Faculty* FindFacultyByID(int facultyID);
    void ChangeStudentFacultyID(int stuID, int facID);

};
