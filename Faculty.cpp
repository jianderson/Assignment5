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
    DoublyListNode<int> *curr = facultyAdvisees->front;
    for(int i = 0; i < facultyAdvisees->getSize(); ++i)
    {

        cout << curr->data << endl;
        curr = curr->next;
    }


}



bool Faculty::operator=(Faculty fac)
{
    if(fac.facultyID == this -> facultyID)
        return true;
    else
        return false;
}

bool Faculty::operator<(Faculty fac)
{
    if(fac.facultyID > this -> facultyID)
        return true;
    else
        return false;
}

bool Faculty::operator>(Faculty fac)
{
    if(fac.facultyID < this -> facultyID)
        return true;
    else
        return false;
}

bool Faculty::operator!=(Faculty fac)
{
    if(fac.facultyID!= this -> facultyID)
        return true;
    else
        return false;
}

ostream& operator<<(ostream& fileStreamer, Faculty& fac)
{
    fileStreamer << fac.facultyID << endl;
    fileStreamer << fac.facultyName << endl;
    fileStreamer << fac.facultyStatus << endl;
    fileStreamer << fac.facultyDepartment << endl;
    fileStreamer << *(fac.facultyAdvisees) << endl;


}


void Faculty::toString()
{
    cout << "Faculty ID: " << facultyID << endl;
    cout << "Faculty Name: " << facultyName << endl;
    cout << "Faculty Status: " << facultyStatus << endl;
    cout << "Faculty Department: " << facultyDepartment << endl;
    cout << "Advisees: ";
    DoublyListNode<int> *curr = facultyAdvisees->front;
    for(int i = 0; i < facultyAdvisees->getSize(); ++i)
    {

        cout << curr->data << " ";
        curr = curr->next;
    }
    cout << endl;


}
