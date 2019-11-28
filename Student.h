#include <iostream>
#include "BST.h"

using namespace std;

class Student
{


public:
//declarations
        string studentName;
        string gradeLevel;
        string studentMajor;
        double studentGPA;
    int advisorID;
    int studentID;
//constructor and overloaded constructor
    Student();
    Student(int id, string name, string grade, string major, double gpa, int advisor);
//method to sidplay
    void DisplayStudent(Student* s);
//overloaded operators
    bool operator=(Student stu);
    bool operator>(Student stu);
    bool operator<(Student stu);
    bool operator!=(Student stu);

    friend ostream& operator<<(ostream& fileStreamer, Student& stu);
//to string method
    void toString();

};
