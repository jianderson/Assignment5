#pragma once

#include "Database.h"
#include <fstream>

using namespace std;

class FileIO
{
public:
    //decalre contants
    static const string studentFileStr;
    static const string facultyFileStr;
//write to the file methods
    static void WriteStudentTree(BST<Student*>* mS, string sFileName = studentFileStr);
    static void WriteFacultyTree(BST<Faculty*>* mF, string fFileName = facultyFileStr);
//read from the file methods
    static BST<Student*>* ReadStudentTree(string sFileName = studentFileStr);
    static BST<Faculty*>* ReadFacultyTree(string fFileName = facultyFileStr);

    static BST<Student*>* FromStudentTree(ifstream& fileInput);

    static void FromStudentTreeNode(BST<Student*>* bst, TreeNode<Student*>* node, ifstream& fileInput);

    static BST<Faculty*>* FromFacultyTree(ifstream& fileInput);

    static void FromFacultyTreeNode(BST<Faculty*>* bst, TreeNode<Faculty*>* node, ifstream& fileInput);
    //
    // static void BackupTrees(BST<Student*>* studentTree, BST<Faculty*>* facultyTree);
//stuff for backups
    static BST<Faculty*>* readFacBackup(int backupNum);
    static BST<Student*>* readStuBackup(int backupNum);
    static void BackupFacultyTree(BST<Faculty*>* facultyTree, int backupFolderNum);
    static void BackupStudentTree(BST<Student*>* studentTree, int backupFolderNum);



};
