#include <iostream>
#include "FileIO.h"
#include <string>


using namespace std;
//constructor that calls the file in methods
Database::Database()
{
masterStudent = FileIO::ReadStudentTree();
masterFaculty = FileIO::ReadFacultyTree();
}
//destructor that calls the write to file methods
Database::~Database()
{
FileIO::WriteStudentTree(masterStudent);
FileIO::WriteFacultyTree(masterFaculty);
}
//method to print the student tree
void Database::PrintAllStudents()
{
    masterStudent->printTree();
}
//method to add a new student to the student class and to assign the advisor
void Database::AddNewStudent(Student* s)
{

    masterStudent->insert(s->studentID, s);
    int idAdvisor = s->advisorID;
    Faculty* advisor = masterFaculty->printNode(idAdvisor);
    advisor->facultyAdvisees->insertBack(s->studentID);

}
//get student info method with will be used to grab the data from the user
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
    //must be used becuase the name might be 2 words
        cin.ignore();
        getline(cin, name);

    //cin >> name;
    cout << "What is the Student's grade level: " << endl;
    getline(cin, grade);
    //cin >> grade;
    cout << "What is the Student's major: " << endl;

    //cin.ignore();
    getline(cin, major);
    //cin >> major;
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
//find the student
Student* Database::FindStudentByID(int studentID)
{
    return masterStudent->printNode(studentID);
}

//delete the student
Student* Database::DeleteStudent(int studentID)
{
    bool didItDelete = false;
    Student* deletedStudent = masterStudent->printNode(studentID);
    int advisorid = deletedStudent->advisorID;

    Faculty* advisor = masterFaculty->printNode(advisorid);
    advisor->facultyAdvisees->remove(studentID);
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
//find the faculty by id
Faculty* Database::FindFacultyByID(int facultyID)
{
    return masterFaculty->printNode(facultyID);
}

//get the advisor info
Faculty* Database::GetStudentAdvisorInfo(int studentID)
{
    Student* s = FindStudentByID(studentID);

    int advisorid = s->advisorID;

    return FindFacultyByID(advisorid);
}

//print the entire faculty tree
void Database::PrintAllFaculty()
{
    masterFaculty->printTree();
}
//add a new faculty
void Database::AddNewFaculty(Faculty* f)
{
    masterFaculty->insert(f->facultyID, f);
}
//delete the faculty
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
//change the students advisor
void Database::ChangeStudentFacultyID(int stuID, int facID)
{
    Student* oldStudent = masterStudent->printNode(stuID);
    int oldAdvisor = oldStudent -> advisorID;
    Faculty* oldf = masterFaculty->printNode(oldAdvisor);

    int deletedId = oldf->facultyAdvisees->remove(stuID)->data;
    //cout << "Deleted ID: " << deletedId << endl;
    //oldf->facultyAdvisees->deletePos(position);



    oldStudent -> advisorID = facID;

    Faculty* newFaculty = masterFaculty->printNode(facID);
    newFaculty->facultyAdvisees->insertBack(stuID);

    cout << "Advisor Changed" << endl;

}
//get all the information to make a faculty object
Faculty* Database::GetFacultyInfo()
{
    bool allcorrect = true;
    int iD = 0;
    string name;
    string status;
    string department;
    cout << "What is the Faculty's ID Number: " << endl;
    try{
    cin >> iD;
    }
    catch(runtime_error e)
    {
        cout << "That was not a number! Try again!" << endl;
        try
        {
        cin >> iD;
        }
        catch(runtime_error e2)
        {
            allcorrect = false;
        }
    }

    cout << "What is the Faculty's name: " << endl;

    cin.ignore();
    getline(cin, name);
    // cin >> name;
    cout << "What is the Faculty's status: " << endl;
    // cin.ignore();
    getline(cin, status);
    // cin >> status;
    cout << "What is the Faculty's department: " << endl;
    // cin.ignore();
    getline(cin, department);
    // cin >> department;


    // if(allcorrect)
    // {
    Faculty* fac = new Faculty(iD, name, status, department);

    return fac;
    // }
    // else
    // {
    //     return NULL;
    // }
}
