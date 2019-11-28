#include <iostream>
#include "Faculty.h"

using namespace std;
//constructor to make a faculty
Faculty::Faculty()
{
    facultyID = 0;
    facultyName = "";
    facultyStatus = "";
    facultyDepartment = "";
    facultyAdvisees = new DoublyLinkedList<int>();

}
//overloaded constructor to make a faculty
Faculty::Faculty(int id, string name, string status, string department)
{
    facultyID = id;
    facultyName = name;
    facultyStatus = status;
    facultyDepartment = department;
    facultyAdvisees = new DoublyLinkedList<int>();

}
//method to display the faculty
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

        cout << curr->data << " ";
        curr = curr->next;
    }

cout << endl;
}

//overloaded = operator

bool Faculty::operator=(Faculty fac)
{
    if(fac.facultyID == this -> facultyID)
        return true;
    else
        return false;
}
//overloaded < operator
bool Faculty::operator<(Faculty fac)
{
    if(fac.facultyID > this -> facultyID)
        return true;
    else
        return false;
}
//overloaded > operator
bool Faculty::operator>(Faculty fac)
{
    if(fac.facultyID < this -> facultyID)
        return true;
    else
        return false;
}
//overloaded != operator
bool Faculty::operator!=(Faculty fac)
{
    if(fac.facultyID!= this -> facultyID)
        return true;
    else
        return false;
}
//overloaded << operator
ostream& operator<<(ostream& fileStreamer, Faculty& fac)
{
    fileStreamer << fac.facultyID << endl;
    fileStreamer << fac.facultyName << endl;
    fileStreamer << fac.facultyStatus << endl;
    fileStreamer << fac.facultyDepartment << endl;
    fileStreamer << *(fac.facultyAdvisees) << endl;

    return fileStreamer;

}

//to string method to print our faculty
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
