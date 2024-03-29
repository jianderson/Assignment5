#include <iostream>
#include "Student.h"

using namespace std;
//student constructor
Student::Student()
{
    studentID = 0;
    studentName = "";
    gradeLevel = "";
    studentMajor = "";
    studentGPA = 0.0;
    advisorID = 0;
}
//overloaded student constructor
Student::Student(int id, string name, string grade, string major, double gpa, int advisor)
{
    studentID = id;
    studentName = name;
    gradeLevel = grade;
    studentMajor = major;
    studentGPA = gpa;
    advisorID = advisor;
}
//overloaded equals operator
bool Student::operator=(Student stu)
{
    if(stu.studentID == this -> studentID)
        return true;
    else
        return false;
}
//overloaded < operator
bool Student::operator<(Student stu)
{
    if(stu.studentID > this -> studentID)
        return true;
    else
        return false;
}
//overloaded > operator
bool Student::operator>(Student stu)
{
    if(stu.studentID < this -> studentID)
        return true;
    else
        return false;
}
//overloaded != operator
bool Student::operator!=(Student stu)
{
    if(stu.studentID!= this -> studentID)
        return true;
    else
        return false;
}


//method to display the facts of the student
void Student::DisplayStudent(Student* s)
{

    cout << "Student ID: " << s->studentID << endl;
    cout << "Student Name: " << s->studentName << endl;
    cout << "Student Grade Level: " << s->gradeLevel << endl;
    cout << "Student Major: " << s->studentMajor << endl;
    cout << "Student GPA: " << s->studentGPA << endl;
    cout << "Student Advisor ID Number: " << s->advisorID << endl;


}


//method to overload << operator
ostream& operator<<(ostream& fileStreamer, Student& stu)
{
    fileStreamer << stu.studentID << endl;
    fileStreamer << stu.studentName << endl;
    fileStreamer << stu.gradeLevel << endl;
    fileStreamer << stu.studentMajor << endl;
    fileStreamer << stu.studentGPA << endl;
    fileStreamer << stu.advisorID << endl;

    return fileStreamer;

}
//tostring method
void Student::toString()
{
    cout << "Student ID: " << studentID << endl;
    cout << "Student Name: " << studentName << endl;
    cout << "Student Grade Level: " << gradeLevel << endl;
    cout << "Student Major: " << studentMajor << endl;
    cout << "Student GPA: " << studentGPA << endl;
    cout << "Student Advisor ID Number: " << advisorID << endl;
}
