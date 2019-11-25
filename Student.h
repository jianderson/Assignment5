#include <iostream>
#include "BST.h"

using namespace std;

class Student
{

private:

    string studentName;
    string gradeLevel;
    string studentMajor;
    double studentGPA;
    int advisorID;

public:
    int studentID;
    Student();
    Student(int id, string name, string grade, string major, double gpa, int advisor);
    BST<Student> *masterStudent = new BST<Student>();
    void PrintAllStudents();
    void AddNewStudent(Student s);
    Student GetStudentInfo();

};
