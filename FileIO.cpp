#include "FileIO.h"

using namespace std;

const string FileIO::facultyFileStr = "FacultyTable.txt";
const string FileIO::studentFileStr = "StudentTable.txt";

void FileIO::WriteStudentTree(BST<Student*>* mS, string sFileName)
{
    mS->ToFile(sFileName);
}

void FileIO::WriteFacultyTree(BST<Faculty*>* mF, string fFileName)
{
    mF->ToFile(fFileName);
}

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


BST<Student*>* FileIO::FromStudentTree(ifstream& fileInput)
{
    BST<Student*>* newTree = new BST<Student*>();

    string line;

    getline(fileInput, line);

    FromStudentTreeNode(newTree, newTree->root, fileInput);

    return newTree;
}

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

    Student* stu = new Student(id, name, grade, major, gpa, advisorid);

    node = new TreeNode<Student*>(id, stu);

    bst->insert(id, stu);

    FromStudentTreeNode(bst, node->left, fileInput);
    FromStudentTreeNode(bst, node->right, fileInput);


}




BST<Faculty*>* FileIO::FromFacultyTree(ifstream& fileInput)
{
    BST<Faculty*>* newTree = new BST<Faculty*>();

    string line;

    getline(fileInput, line);

    FromFacultyTreeNode(newTree, newTree->root, fileInput);

    return newTree;
}





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



    Faculty* newFaculty = new Faculty(id, name, status, department);

    node = new TreeNode<Faculty*>(id, newFaculty);



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

bst->insert(id, newFaculty);

FromFacultyTreeNode(bst, node->left, fileInput);
FromFacultyTreeNode(bst, node->right, fileInput);

}




void FileIO::BackupStudentTree(BST<Student*>* studentTree, int backupFolderNum)
{
    string studentBackupStr = "StuBackUpNum" + backupFolderNum;

    WriteStudentTree(studentTree, studentBackupStr);
}

void FileIO::BackupFacultyTree(BST<Faculty*>* facultyTree, int backupFolderNum)
{
    string facultyBackupStr = "FacBackUpNum" + backupFolderNum;

    WriteFacultyTree(facultyTree, facultyBackupStr);
}

BST<Student*>* FileIO::readStuBackup(int backupNum)
{
    string studentBackUp = "StuBackUpNum" + backupNum;

    BST<Student*>* studentTreeBack = new BST<Student*>;

    studentTreeBack = ReadStudentTree(studentBackUp);

    return studentTreeBack;
}

BST<Faculty*>* FileIO::readFacBackup(int backupNum)
{
    string facultyBackUp = "FacBackUpNum" + backupNum;

    BST<Faculty*>* facultyTreeBack = new BST<Faculty*>;

    facultyTreeBack = ReadFacultyTree(facultyBackUp);

    return facultyTreeBack;
}
