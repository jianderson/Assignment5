#include<iostream>
#include "GenQueue.h"
using namespace std;
template <class T>
class TreeNode
{
public:
    //declararions for the elemets of the nodes
    int key;
    T value;
    TreeNode *left;
    TreeNode *right;
//constructor
    TreeNode()
    {
        left = NULL;
        right = NULL;

    }
//overloaded constructor
    TreeNode(int k, T v)
    {
        key = k;
        value = v;
        left = NULL;
        right = NULL;
    }
//destructor
    ~TreeNode()
    {
        //on our own
    }
};
