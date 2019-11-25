#include <iostream>
#include "Student.h"

using namespace std;

class Faculty
{
private:
    int facultyID;
    string facultyName;
    string facultyStatus;
    string facultyDepartment;
    //int[] *facultyAdvisees;
    //THIS NEEDS TO BE A LIST WE MIGHT HAVE TO USE OUR LINKED LIST CLASSES
public:
    Faculty();
    Faculty(int id, string name, string status, string department);
    BST<Faculty> *masterFaculty = new BST<Faculty>();
    void PrintAllFaculty();

};
