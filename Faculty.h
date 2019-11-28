#include <iostream>
#include "Student.h"
// #include "DoublyLinkedList.h"

using namespace std;

class Faculty
{
public:
//faculty declarations
    string facultyName;
    string facultyStatus;
    string facultyDepartment;

    int facultyID;
//doubly linked list
    DoublyLinkedList<int> *facultyAdvisees;

//constructor and overloaded constructor
    Faculty();
    Faculty(int id, string name, string status, string department);
//display all info about faculty
    void DisplayFaculty(Faculty* f);
//overloaded operators
    bool operator=(Faculty fac);
    bool operator>(Faculty fac);
    bool operator<(Faculty fac);
    bool operator!=(Faculty fac);
    friend ostream& operator<<(ostream& fileStreamer, Faculty& fac);
//to string method
    void toString();
};
