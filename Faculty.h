#include <iostream>
#include "Student.h"
// #include "DoublyLinkedList.h"

using namespace std;

class Faculty
{
private:
    int facultyID;
    string facultyName;
    string facultyStatus;
    string facultyDepartment;
    DoublyLinkedList<int> *facultyAdvisees = new DoublyLinkedList<int>();
    //THIS NEEDS TO BE A LIST WE MIGHT HAVE TO USE OUR LINKED LIST CLASSES
public:
    Faculty();
    Faculty(int id, string name, string status, string department);

};
