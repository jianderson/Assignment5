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

bool Student::operator=(Student stu)
{
    if(stu.studentID == this -> studentID)
        return true;
    else
        return false;
}

bool Student::operator<(Student stu)
{
    if(stu.studentID > this -> studentID)
        return true;
    else
        return false;
}

bool Student::operator>(Student stu)
{
    if(stu.studentID < this -> studentID)
        return true;
    else
        return false;
}

bool Student::operator!=(Student stu)
{
    if(stu.studentID!= this -> studentID)
        return true;
    else
        return false;
}

void Student::DisplayStudent(Student* s)
{

    cout << "Student ID: " << s->studentID << endl;
    cout << "Student Name: " << s->studentName << endl;
    cout << "Student Grade Level: " << s->gradeLevel << endl;
    cout << "Student Major: " << s->studentMajor << endl;
    cout << "Student GPA: " << s->studentGPA << endl;
    cout << "Student Advisor ID Number: " << s->advisorID << endl;


}
