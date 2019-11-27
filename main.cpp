#include <iostream>
#include "FileIO.h"

using namespace std;

int main()
{
Database db = Database();
bool keepRunning = true;

while(keepRunning)
{
    int userChoice = 0;
    cout << endl;
    cout << endl;
    cout << "DATABASE" << endl;
    cout << endl;
    cout << endl;
    cout << "What you you like to do: " << endl;
    cout << endl;
    cout << "1. Print all students and their information (sorted by ascending id #)" << endl;
    cout << "2. Print all faculty and their information (sorted by ascending id #)" << endl;
    cout << "3. Find and display student information given the students id" << endl;
    cout << "4. Find and display faculty information given the faculty id" << endl;
    cout << "5. Given a student’s id, print the name and info of their faculty advisor" << endl;
    cout << "6. Given a faculty id, print ALL the names and info of his/her advisees." << endl;
    cout << "7. Add a new student" << endl;
    cout << "8. Delete a student given the id" << endl;
    cout << "9. Add a new faculty member" << endl;
    cout << "10. Delete a faculty member given the id" << endl;
    cout << "11. Change a student’s advisor given the student id and the new faculty id." << endl;
    cout << "12. Remove an advisee from a faculty member given the ids" << endl;
    cout << "13. Rollback" << endl;
    cout << "14. Exit" << endl;

    cin >> userChoice;

    if(userChoice == 1)
    {
        db.masterStudent->printTree();
    }

    else if(userChoice == 2)
    {
        db.masterFaculty->printTree();
    }

    else if(userChoice == 3)
    {
        cout << "Okay, enter the ID number of the student you are looking for: " << endl;
        int idNum;
        cin >> idNum;
        Student* ourStu = db.FindStudentByID(idNum);
        ourStu->DisplayStudent(ourStu);


    }

    else if(userChoice == 4)
    {
        cout << "Okay, enter the ID number of the faculty you are looking for: " << endl;
        int idNum;
        cin >> idNum;
        Faculty* ourFac = db.FindFacultyByID(idNum);
        ourFac->DisplayFaculty(ourFac);

    }

    else if(userChoice == 5)
    {
        int stuID;
        cout << "Enter the student ID number: " << endl;
        cin >> stuID;
        db.GetStudentAdvisorInfo(stuID);

    }

    else if(userChoice == 6)
    {
        cout << "What is the Faculty ID: " << endl;
        int facID;
        cin >> facID;

        while(!db.masterFaculty -> search(facID))
        {
            cout << "This is an invalid Advisor ID Number. " << endl;
            cout << "Enter a valid Advisor ID Number: " << endl;
            cin >> facID;
        }

        Faculty* outF = db.masterFaculty->printNode(facID);
        DoublyListNode<int>* curr = outF->facultyAdvisees->front;
        for(int i = 0; i < outF->facultyAdvisees->getSize(); ++i)
        {
            int stuId = curr->data;
            Student* outS = db.masterStudent->printNode(stuId);
            outS->DisplayStudent(outS);
            curr = curr->next;

        }

    }

    else if(userChoice == 7)
    {

        Student* myStu = db.GetStudentInfo();
        //myStu->advisorID = db.masterFaculty->root->value->facultyID;
        db.AddNewStudent(myStu);



    }

    else if(userChoice == 8)
    {
        int stuID = 0;

        cout << "Enter the ID of the student you wish to delete: " << endl;
        cin >> stuID;
        db.DeleteStudent(stuID);
//HAVE TO DELETE STUDENT FROM ADVISEES LIST

    }

    else if(userChoice == 9)
    {
        Faculty* fac = db.GetFacultyInfo();
        db.AddNewFaculty(fac);


    }

    else if(userChoice == 10)
    {
        int facID = 0;

        cout << "Enter the ID of the faculty you wish to delete: " << endl;
        cin >> facID;
        db.DeleteFaculty(facID);
//HAVE TO ASSIGN ADVISEES TO SOMEONE ELSE
    }

    else if(userChoice == 11)
    {
        int stuID;
        int facID;
        cout << "Enter the Student ID: " << endl;
        cin >> stuID;
        cout << "Enter the new Advisor ID: " << endl;
        cin >> facID;
        while(!db.masterStudent -> search(stuID))
        {
            cout << "This is an invalid Student ID Number. " << endl;
            cout << "Enter a valid Student ID Number: " << endl;
            cin >> stuID;
        }
        while(!db.masterFaculty -> search(facID))
        {
            cout << "This is an invalid Advisor ID Number. " << endl;
            cout << "Enter a valid Advisor ID Number: " << endl;
            cin >> facID;
        }
        db.ChangeStudentFacultyID(stuID, facID);

    }

    else if(userChoice == 12)
    {
        //Remove an advisee from a faculty member given the ids

        int stuID;
        int facID;
        cout << "Enter the Student ID: " << endl;
        cin >> stuID;
        cout << "Enter the new Advisor ID: " << endl;
        cin >> facID;
        while(!db.masterStudent -> search(stuID))
        {
            cout << "This is an invalid Student ID Number. " << endl;
            cout << "Enter a valid Student ID Number: " << endl;
            cin >> stuID;
        }
        while(!db.masterFaculty -> search(facID))
        {
            cout << "This is an invalid Advisor ID Number. " << endl;
            cout << "Enter a valid Advisor ID Number: " << endl;
            cin >> facID;
        }

        Faculty* ourF = db.masterFaculty->printNode(facID);
        ourF->facultyAdvisees->deletePos(ourF->facultyAdvisees->find(stuID));
        Student* stuNode = db.masterStudent->printNode(stuID);
        Faculty* fRoot = db.masterFaculty->root->value;
        stuNode->advisorID = fRoot->facultyID;

        fRoot->facultyAdvisees->insertBack(stuNode->studentID);




    }

    else if(userChoice == 13)
    {

    }

    else if (userChoice == 14)
    {
        keepRunning = false;
    }

    else
    {
        cout << "That was not a valid option!" << endl;
        cout << "Goodbye!" << endl;
        keepRunning = false;
    }

}

//delete db;

}
