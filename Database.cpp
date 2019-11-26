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
    int idAdvisor = s->advisorID;

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

    while(!masterFaculty->search(advisorID))
    {
        cout << "That advisor does not exist!" << endl;
        cout << "Please enter a different advisor ID: " << endl;
        cin >> advisorID;
    }


//ADD STUDENT TO ADVISORS ADVISEE LIST

    Student* stu = new Student(iD, name, grade, major, gpa, advisorID);
    return stu;
}

Student* Database::FindStudentByID(int studentID)
{
    return masterStudent->printNode(studentID);
}


Student* Database::DeleteStudent(int studentID)
{
    bool didItDelete = false;
    Student* deletedStudent = masterStudent->printNode(studentID);
    didItDelete = masterStudent->deleteNode(studentID);
    if(didItDelete)
    {
        cout << "Deleted Successfully" << endl;
        return deletedStudent;
    }
    else
    {
        cout << "failed delete" << endl;
        return NULL;
    }

}

Faculty* Database::FindFacultyByID(int facultyID)
{
    return masterFaculty->printNode(facultyID);
}





Faculty* Database::GetStudentAdvisorInfo(int studentID)
{
    Student* s = FindStudentByID(studentID);

    int advisorid = s->advisorID;

    return FindFacultyByID(advisorid);
}


void Database::PrintAllFaculty()
{
    masterFaculty->printTree();
}

void Database::AddNewFaculty(Faculty* f)
{
    masterFaculty->insert(f->facultyID, f);
}

Faculty* Database::DeleteFaculty(int facultyID)
{
    bool didItDelete = false;
    Faculty* deletedFaculty = masterFaculty->printNode(facultyID);
    didItDelete = masterFaculty->deleteNode(facultyID);
    if(didItDelete)
    {
        cout << "Deleted Successfully" << endl;
        return deletedFaculty;
    }
    else
    {
        cout << "failed delete" << endl;
        return NULL;
    }
}

void Database::ChangeStudentFacultyID(int stuID, int facID)
{
    Student* oldStudent = DeleteStudent(stuID);
    oldStudent -> advisorID = facID;
    AddNewStudent(oldStudent);
}

Faculty* Database::GetFacultyInfo()
{
    int iD;
    string name;
    string status;
    string department;
    cout << "What is the Faculty's ID Number: " << endl;
    cin >> iD;
    cout << "What is the Faculty's name: " << endl;
    cin >> name;
    cout << "What is the Faculty's status: " << endl;
    cin >> status;
    cout << "What is the Faculty's department: " << endl;
    cin >> department;



    Faculty* fac = new Faculty(iD, name, status, department);
    return fac;

}
