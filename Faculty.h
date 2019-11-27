#include <iostream>
#include "Student.h"
// #include "DoublyLinkedList.h"

using namespace std;

class Faculty
{
public:

    string facultyName;
    string facultyStatus;
    string facultyDepartment;

    int facultyID;
    DoublyLinkedList<int> *facultyAdvisees;
    //THIS NEEDS TO BE A LIST WE MIGHT HAVE TO USE OUR LINKED LIST CLASSES

    Faculty();
    Faculty(int id, string name, string status, string department);

    void DisplayFaculty(Faculty* f);

    bool operator=(Faculty fac);
    bool operator>(Faculty fac);
    bool operator<(Faculty fac);
    bool operator!=(Faculty fac);
    friend ostream& operator<<(ostream& fileStreamer, Faculty& fac);

    void toString();
};
