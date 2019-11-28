#include "FileIO.h"

using namespace std;

const string FileIO::facultyFileStr = "FacultyTable.txt";
const string FileIO::studentFileStr = "StudentTable.txt";
//write to the file
void FileIO::WriteStudentTree(BST<Student*>* mS, string sFileName)
{
    mS->ToFile(sFileName);
}
//write to the file
void FileIO::WriteFacultyTree(BST<Faculty*>* mF, string fFileName)
{
    mF->ToFile(fFileName);
}
//read from the file and assign it to a tree
BST<Student*>* FileIO::ReadStudentTree(string sFileName)
{
    ifstream fileStreamer;
    fileStreamer.open(sFileName);

    BST<Student*>* studentTree;

    if(fileStreamer.is_open() == false)
    {
        return new BST<Student*>();
    }

    studentTree = FromStudentTree(fileStreamer);
    fileStreamer.close();
    return studentTree;

}
//read from file and assign it to a tree
BST<Faculty*>* FileIO::ReadFacultyTree(string fFileName)
{
    ifstream fileStreamer;
    fileStreamer.open(fFileName);

    BST<Faculty*>* facultyTree;

    if(fileStreamer.is_open() == false)
    {
        return new BST<Faculty*>();
    }

    facultyTree = FromFacultyTree(fileStreamer);
    fileStreamer.close();
    return facultyTree;

}

//will help get information from the file
BST<Student*>* FileIO::FromStudentTree(ifstream& fileInput)
{
    BST<Student*>* newTree = new BST<Student*>();

    string line;

    getline(fileInput, line);

    FromStudentTreeNode(newTree, newTree->root, fileInput);

    return newTree;
}
//will help get info from the file for the tree
void FileIO::FromStudentTreeNode(BST<Student*>* bst, TreeNode<Student*>* node, ifstream& fileInput)
{
    const string endNode = "||";

    int key;
    int id;
    string name;
    string grade;
    string major;
    double gpa;
    int advisorid;

    string response = "null";

    getline(fileInput, response);
    while(response == "")
    {
        getline(fileInput, response);

        if(fileInput.eof() == true)
        {
            return;
        }
    }
//getting the responses
    if(response == endNode)
        return;

    key = stoi(response);
    getline(fileInput, response);
    if(response == endNode)
        return;

    id = stoi(response);
    getline(fileInput, response);
    if(response == endNode)
        return;

    name = response;
    getline(fileInput, response);
    if(response == endNode)
        return;

    grade = response;
    getline(fileInput, response);
    if(response == endNode)
        return;

    major = response;
    getline(fileInput, response);
    if(response == endNode)
        return;

    gpa = stod(response);
    getline(fileInput, response);
    if(response == endNode)
        return;

    advisorid = stoi(response);
//creating object
    Student* stu = new Student(id, name, grade, major, gpa, advisorid);

    node = new TreeNode<Student*>(id, stu);

    bst->insert(id, stu);
//do this for left and right
    FromStudentTreeNode(bst, node->left, fileInput);
    FromStudentTreeNode(bst, node->right, fileInput);


}



//get info from file and put in tree
BST<Faculty*>* FileIO::FromFacultyTree(ifstream& fileInput)
{
    BST<Faculty*>* newTree = new BST<Faculty*>();

    string line;

    getline(fileInput, line);

    FromFacultyTreeNode(newTree, newTree->root, fileInput);

    return newTree;
}



//get info and form ndoes for tree from file

void FileIO::FromFacultyTreeNode(BST<Faculty*>* bst, TreeNode<Faculty*>* node, ifstream& fileInput)
{


    // facultyID = 0;
    // facultyName = "";
    // facultyStatus = "";
    // facultyDepartment = "";
    // facultyAdvisees = new DoublyLinkedList<int>();
    const string endNode = "||";

    int key;
    int id;
    string name;
    string status;
    string department;

    string response = "null";
//get lines and assign them
    getline(fileInput, response);
    while(response == "")
    {
        getline(fileInput, response);

        if(fileInput.eof() == true)
        {
            return;
        }
    }

    if(response == endNode)
        return;

    key = stoi(response);
    getline(fileInput, response);
    if(response == endNode)
        return;

    id = stoi(response);
    getline(fileInput, response);
    if(response == endNode)
        return;

    name = response;
    getline(fileInput, response);
    if(response == endNode)
        return;

    status = response;
    getline(fileInput, response);
    if(response == endNode)
        return;

    department = response;
    // getline(fileInput, response);
    // if(response == endNode)
    //     return;


//make node
    Faculty* newFaculty = new Faculty(id, name, status, department);

    node = new TreeNode<Faculty*>(id, newFaculty);


//for the linked list
do
{
    int thisid = 0;
    getline(fileInput, response);
    if(response == endNode)
        return;
//THIS IS THE PART THAT I THINK IS CAUSING THE ERROR

    try
    {
        thisid = stoi(response);
    }
    catch(invalid_argument e)
    {
        break;
    }
    newFaculty->facultyAdvisees->insertBack(thisid);
} while(response != "");
//insert it
bst->insert(id, newFaculty);

FromFacultyTreeNode(bst, node->left, fileInput);
FromFacultyTreeNode(bst, node->right, fileInput);

}



//backup the tree into a file
void FileIO::BackupStudentTree(BST<Student*>* studentTree, int backupFolderNum)
{
    string studentBackupStr = "StuBackUpNum" + to_string(backupFolderNum);



    WriteStudentTree(studentTree, studentBackupStr);
}
//backup tree into a file
void FileIO::BackupFacultyTree(BST<Faculty*>* facultyTree, int backupFolderNum)
{
    string facultyBackupStr = "FacBackUpNum" + to_string(backupFolderNum);

    WriteFacultyTree(facultyTree, facultyBackupStr);
}
//read from the file into the tree
BST<Student*>* FileIO::readStuBackup(int backupNum)
{
    string studentBackUp = "StuBackUpNum" + to_string(backupNum);

    BST<Student*>* studentTreeBack = new BST<Student*>;

    studentTreeBack = ReadStudentTree(studentBackUp);

    return studentTreeBack;
}
//read from the file into a tree
BST<Faculty*>* FileIO::readFacBackup(int backupNum)
{
    string facultyBackUp = "FacBackUpNum" + to_string(backupNum);

    BST<Faculty*>* facultyTreeBack = new BST<Faculty*>;

    facultyTreeBack = ReadFacultyTree(facultyBackUp);

    return facultyTreeBack;
}
