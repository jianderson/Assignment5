#include <iostream>
#include "Faculty.h"

using namespace std;

Faculty::Faculty()
{
    facultyID = 0;
    facultyName = "";
    facultyStatus = "";
    facultyDepartment = "";
    facultyAdvisees = new DoublyLinkedList<int>();

}

Faculty::Faculty(int id, string name, string status, string department)
{
    facultyID = id;
    facultyName = name;
    facultyStatus = status;
    facultyDepartment = department;
    facultyAdvisees = new DoublyLinkedList<int>();

}

void Faculty::DisplayFaculty(Faculty* f)
{
    cout << "Faculty ID: " << f->facultyID << endl;
    cout << "Faculty Name: " << f->facultyName << endl;
    cout << "Faculty Status: " << f->facultyStatus << endl;
    cout << "Faculty Department: " << f->facultyDepartment << endl;
    cout << "Advisees: ";
    for(int i = 0; i < facultyAdvisees->getSize(); ++i)
    {
        DoublyListNode<int> *curr = facultyAdvisees->front;
        cout << curr->data << endl;
        curr = curr->next;
    }


}
