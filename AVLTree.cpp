//
// Created by mario on 13/11/2022.
//

#include "AVLTree.h"

AVLTree::AVLTree()
{
    value = char(0);
    right = nullptr;
    left = nullptr;
}

AVLTree::~AVLTree()
{
    delete right;
    delete left;
    delete this;
}

void AVLTree::Insert(char v)
{
    AVLTree* currentNode = this; //The current node being checked
    bool inserted = false; //Checks whether the value has been inserted or not in order to exit the loop
    while(inserted == false)
    {
        if (v < currentNode->value)
        {
            if (currentNode->left == nullptr)
            {
                left = new AVLTree;
                left->value = v;
                inserted = true;
            } else {
                currentNode = currentNode->left;
            }
        }

        if (v > currentNode->value)
        {
            if (currentNode->right == nullptr)
            {
                right = new AVLTree;
                right->value = v;
                inserted = true;
            } else {
                currentNode = currentNode->right;
            }
        }

        if (v == currentNode->value)
        {
            inserted = true;
        }
    }
} //Incomplete

AVLTree* AVLTree::Find(char v)
{
    AVLTree* currentNode = this; //The current node being checked

    if(v == currentNode->value)
    {
        return currentNode;
    }

    if(v > currentNode->value)
    {
        if (currentNode->right == nullptr)
        {
            return nullptr;
        } else {
            currentNode = currentNode->right;
            currentNode->Find(v);
        }
    }

    if(v < currentNode->value)
    {
        if (currentNode->left == nullptr)
        {
            return nullptr;
        } else {
            currentNode = currentNode->left;
            currentNode->Find(v);
        }
    }
}

AVLTree* AVLTree::Delete(char v)
{
    
} //Incomplete

int AVLTree::ComputeUnbalanceLevel()
{

}

