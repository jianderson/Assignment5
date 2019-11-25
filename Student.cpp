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

void PrintAllStudents()
{
    masterStudent->printTree();
}

void AddNewStudent(Student s)
{
    masterStudent->insert(s.studentID, s);
}

Student GetStudentInfo()
{
    int iD;
    string name;
    string grade;
    string major;
    double gpa;
    int advisorID;
    cout << "What is the Student's ID Number: " << endl;
    cin >> iD;
    cout << "What is the Student's name: " << endl;
    cin >> name;
    cout << "What is the Student's grade level: " << endl;
    cin >> grade;
    cout << "What is the Student's major: " << endl;
    cin >> major;
    cout << "What is the Student's GPA: " << endl;
    cin >> gpa;
    cout << "What is the Student's Advisor's ID Number: " << endl;
    cin >> advisorID;

    Student stu = Student(iD, name, grade, major, gpa, advisorID);
    return stu;
}
