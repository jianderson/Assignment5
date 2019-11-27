#include <iostream>
#include <fstream>
#include "TreeNode.h"

using namespace std;

template <class T>
class BST
{
    public:
        TreeNode<T> *root;

        const string endNode = "||";


        BST()
        {
            root = NULL;
        }

        ~BST()
        {

        }

        bool search(int value)
        {

            if(root == NULL)
                return false;

            //if we make it this far we know the tree is not Empty

            else
            {

                TreeNode<T> *current = root;

                while(current->key != value)
                {
                    if(value < current->key)
                        current = current->left;
                    else
                        current = current->right;

                    if(current == NULL)
                        return false;
                }

            }

            return true;

        }


        void insert(int key, T value)
        {
            //check if value exists in tree before proceeding
            //failed search

            TreeNode<T> *node = new TreeNode<T>(key, value); // I AM CONFUSION I DONT UNDERSTAND UGH

            cout<< "This part is ok" << endl;
            if(root == NULL)
                root = node;
            else
            {
                //tree is not empty, find the insertion point

                TreeNode<T> *current = root;
                TreeNode<T> *parent = NULL;
                cout << "make it here" << endl;
                bool istrue = true;
                while(istrue)
                {
                    cout << "make it here" << endl;
                    parent = current;
                    cout << "this" << endl;
                    if(key < current->key)
                    {
                        //go left

                        current = current->left;
cout << "this2" << endl;
                        if(current == NULL)
                        {
                            parent->left = node;
                            break;
                        }
                    }
                    else
                    {
                            //we go right
                            current = current->right;
                            if(current == NULL)
                            {
                                parent->right = node;
                                break;
                            }
                    }


                }
            }

            }



        bool isEmpty()
        {
            if(root == NULL)
            {
                return true;
            }
            else
            {
                return false;
            }
        }


        bool deleteNode(int key)
        {

            if(root == NULL)
                return false;

            TreeNode<T> *parent = root;
            TreeNode<T> *current = root;
            bool isLeft = true;

            //loop to find the variable we need to deleteNode

            while(current->key != key)
            {
                parent = current;
                if(key < current->key)
                {
                    //go isLeft
                    isLeft = true;
                    current = current->left;
                }
                else
                {
                    isLeft = false;
                    current = current->right;
                }

                if(current == NULL) //value doesnt exist
                    return false;
            }

            //if we make it here then we must have found the node to be deleted
//CHECK THIS WITH SANIYA

            if(current->left == NULL && current->right == NULL)
            {
                if(current == root)
                {
                    root = NULL;
                }

                else if(isLeft)
                {
                    parent->left = NULL;
                }
                else
                {
                    parent->right = NULL; // I DONT KNOW WHAT TO PUT HERE
                }

            }
            else if(current->right == NULL)
            {
                if(current == root)
                {
                    root = current->left;
                }

                else if(isLeft)
                {
                    parent->left = current->left;
                }
                else
                {
                    parent->right = current->left;
                }
            }

            else if(current->left == NULL)
            {
                if(current == root)
                {
                    root = current->right;
                }

                else if(isLeft)
                {
                    parent->left = current->right;
                }
                else
                {
                    parent->right = current->right;
                }
            }

            else
            {
                //the node to be deleted has two children

                TreeNode<T> *successor = getSuccessor(current);
                if(current == root)
                {
                    root = successor;
                }

                else if(isLeft)
                {
                    parent->left = successor;
                }
                else
                {
                    parent->right = successor;
                }

                successor->left = current->left;

            }

        }

        TreeNode<T>* getSuccessor(TreeNode<T> *d)
        {
            TreeNode<T> *current = d->right;
            TreeNode<T> *sp = d;
            TreeNode<T> *successor = d;

            while(current != NULL)
            {
                sp = successor;
                successor = current;
                current = current->left;
            }

            //we made it here which means we found our Successor

            if(successor != d->right)
            {
                sp->left = successor->right;
                successor->right = d->right;

            }

            return successor;

        }

        TreeNode<T>* getMin()
        {
            TreeNode<T> *current = root;
            if(root == NULL)
                return NULL;
            while(current->left != NULL)
            {
                current = current->left;
            }

            return current;
        }

        TreeNode<T>* getMax()
        {
            TreeNode<T> *current = root;
            if(root == NULL)
                return NULL;
            while(current->right != NULL)
            {
                current = current->right;
            }

            return current;
        }

        void printTree()
        {
            recPrint(root);
        }

        void recPrint(TreeNode<T> *node)
        {
            if(node == NULL)
                return;
            recPrint(node->left);
            node->value->toString();
            cout << endl;
            recPrint(node->right);
        }

        T printNode(int k)
        {
            if(root == NULL)
                return NULL;
            else
            {
                TreeNode<T> *current = root;

                while(current->key != k)
                {
                    if(k < current->key)
                        current = current->left;
                    else
                        current = current->right;

                    if(current == NULL)
                        return NULL;
                }
                //if we reach this point current = the key you want

                return current-> value;
            }
        }

        void ToFile(string fileName)
        {
            ofstream fileStreamer;

            fileStreamer.open(fileName, ios::out);

            if(!fileStreamer)
                throw runtime_error ("File could not be opened.");

            NodeToFile(root, fileStreamer);
            fileStreamer.close();
        }

        void NodeToFile(TreeNode<T> *node, ofstream& fileStreamer)
        {
            if(node == NULL)
            {
                fileStreamer << endNode << endl;
                return;
            }

            NodeToFile(node->left, fileStreamer);
            fileStreamer<< node->key << endl;
            fileStreamer << *(node->value) << endl;
            NodeToFile(node->right, fileStreamer);

        }



};
