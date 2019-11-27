#include <iostream>
#include "BST.h"

using namespace std;

class Student
{


public:

        string studentName;
        string gradeLevel;
        string studentMajor;
        double studentGPA;
    int advisorID;
    int studentID;
    Student();
    Student(int id, string name, string grade, string major, double gpa, int advisor);
    void DisplayStudent(Student* s);

    bool operator=(Student stu);
    bool operator>(Student stu);
    bool operator<(Student stu);
    bool operator!=(Student stu);

    friend ostream& operator<<(ostream& fileStreamer, Student& stu);

    void toString();

};
