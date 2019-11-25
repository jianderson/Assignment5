#include <iostream>
#include "Database.h"

using namespace std;

Database::Database()
{
masterStudent = new BST<Student*>();
masterFaculty = new BST<Faculty*>();
}

void Database::PrintAllStudents()
{
    masterStudent->printTree();
}

void Database::AddNewStudent(Student* s)
{
    masterStudent->insert(s->studentID, s);
}

Student* Database::GetStudentInfo()
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

    Student* stu = new Student(iD, name, grade, major, gpa, advisorID);
    return stu;
}



void Database::PrintAllFaculty()
{
    masterFaculty->printTree();
}
