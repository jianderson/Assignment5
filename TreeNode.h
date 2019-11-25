#include<iostream>
#include "GenQueue.h"
using namespace std;
template <class T>
class TreeNode
{
public:
    int key;
    T value;
    TreeNode *left;
    TreeNode *right;

    TreeNode()
    {
        left = NULL;
        right = NULL;

    }

    TreeNode(int k, T v)
    {
        key = k;
        value = v;
        left = NULL;
        right = NULL;
    }

    ~TreeNode()
    {
        //on our own
    }
};
