#include <iostream>
#include "Student.h"

using namespace std;

Student::Student()
{
    studentID = 0;
    studentName = "";
    gradeLevel = "";
    studentMajor = "";
    studentGPA = 0.0;
    advisorID = 0;
}

Student::Student(int id, string name, string grade, string major, double gpa, int advisor)
{
    studentID = id;
    studentName = name;
    gradeLevel = grade;
    studentMajor = major;
    studentGPA = gpa;
    advisorID = advisor;
}
