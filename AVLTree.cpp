//
// Created by mario on 13/11/2022.
//

#include "AVLTree.h"
#include <iostream>
using namespace std;

AVLTree::AVLTree()
{
    value = 0;
    right = nullptr;
    left = nullptr;
    parent = nullptr;
}

AVLTree::~AVLTree()
{
    delete right;
    delete left;
    delete this;
}

AVLTree* AVLTree::Insert(int v)
{
    AVLTree* currentNode = this; //The current node being checked
        if (currentNode->value == 0)
        {
            currentNode->value = v;
        }

        if (v < currentNode->value)
        {
            if (currentNode->left == nullptr)
            {
                left = new AVLTree;
                left->value = v;
                left->parent = currentNode;
            } else {
                currentNode->left->Insert(v);
            }
        }

        if (v > currentNode->value)
        {
            if (currentNode->right == nullptr)
            {
                right = new AVLTree;
                right->value = v;
                right->parent = currentNode;
            } else {
                currentNode->right->Insert(v);
            }
        }

        if(v != currentNode->value)
        {
            while(currentNode != nullptr)
            {
                int currentBalance = currentNode->ComputeUnbalanceLevel();
                if(currentBalance == -2 && currentNode->left->ComputeUnbalanceLevel() == -1)
                {
                    currentNode = currentNode->RightRotate();
                }
                if(currentBalance == 2 && currentNode->right->ComputeUnbalanceLevel() == 1)
                {
                    currentNode = currentNode->LeftRotate();
                }
                if(currentBalance == 2 && currentNode->right->ComputeUnbalanceLevel() == -1)
                {
                    currentNode = currentNode->right->RightRotate();
                    currentNode = currentNode->LeftRotate();
                }
                if(currentBalance == -2 && currentNode->left->ComputeUnbalanceLevel() == 1)
                {
                    currentNode = currentNode->left->LeftRotate();
                    currentNode = currentNode->RightRotate();
                }
                currentNode = currentNode->parent;

            }
        }
    currentNode = this;
    while(currentNode->parent != nullptr)
    {
        currentNode = currentNode->parent;
    }
    return currentNode;
}

AVLTree* AVLTree::Find(int v)
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
    return nullptr;
}

AVLTree* AVLTree::Delete(int v)
{
    AVLTree* toBeDeleted = Find(v);
    if(toBeDeleted->left == nullptr && toBeDeleted->right != nullptr)
    {
        if(toBeDeleted == toBeDeleted->parent->right)
        {
            toBeDeleted->right->parent = toBeDeleted->parent;
            toBeDeleted->parent->right = toBeDeleted->right;
            toBeDeleted->right = nullptr;
        }
        if(toBeDeleted == toBeDeleted->parent->left)
        {
            toBeDeleted->right->parent = toBeDeleted->parent;
            toBeDeleted->parent->left = toBeDeleted->right;
            toBeDeleted->right = nullptr;
        }
    }
    if(toBeDeleted->right == nullptr && toBeDeleted->left != nullptr)
    {
        if(toBeDeleted == toBeDeleted->parent->right)
        {
            toBeDeleted->left->parent = toBeDeleted->parent;
            toBeDeleted->parent->right = toBeDeleted->left;
            toBeDeleted->left = nullptr;
        }
        if(toBeDeleted == toBeDeleted->parent->left)
        {
            toBeDeleted->left->parent = toBeDeleted->parent;
            toBeDeleted->parent->left = toBeDeleted->left;
            toBeDeleted->left = nullptr;
        }
    }
    if(toBeDeleted->right == nullptr && toBeDeleted->left == nullptr)
    {
        if(toBeDeleted == toBeDeleted->parent->right)
        {
            toBeDeleted->parent->right = nullptr;
        }
        if(toBeDeleted == toBeDeleted->parent->left)
        {
            toBeDeleted->parent->left = nullptr;
        }
    }else{
        AVLTree* currentNode = toBeDeleted->left->right;
        while(currentNode != nullptr)
        {
            currentNode = currentNode->right;
        }
        AVLTree* tempNode = currentNode->parent;
        currentNode->parent = toBeDeleted->parent;
        currentNode->right = toBeDeleted->right;
        if(currentNode -> left != nullptr)
        {
            tempNode->right = currentNode->left;
        }
        currentNode->left = toBeDeleted->left;

    }
    
    
    AVLTree* currentNode = toBeDeleted->parent; //The current node being balance checked
    while(currentNode != nullptr)
    {
        int currentBalance = currentNode->ComputeUnbalanceLevel();
        if(currentBalance == -2 && currentNode->left->ComputeUnbalanceLevel() == -1)
        {
            currentNode = currentNode->RightRotate();
        }
        if(currentBalance == 2 && currentNode->right->ComputeUnbalanceLevel() == 1)
        {
            currentNode = currentNode->LeftRotate();
        }
        if(currentBalance == 2 && currentNode->right->ComputeUnbalanceLevel() == -1)
        {
            currentNode = currentNode->right->RightRotate();
            currentNode = currentNode->LeftRotate();
        }
        if(currentBalance == -2 && currentNode->left->ComputeUnbalanceLevel() == 1)
        {
            currentNode = currentNode->left->LeftRotate();
            currentNode = currentNode->RightRotate();
        }
        currentNode = currentNode->parent;
    }
    
    toBeDeleted->parent = nullptr;
    return toBeDeleted;
} //Incomplete

int AVLTree::ComputeUnbalanceLevel()
{
    return ((this->right->height())-(this->left->height()));
}

AVLTree* AVLTree::RightRotate()
{
    AVLTree* nodeRotated = this;
    AVLTree* leftNode = this->left;
    AVLTree* rightSubtreeHead = this->left->right;

    if(nodeRotated->parent != nullptr)
    {
        if(nodeRotated == nodeRotated->parent->left){
            nodeRotated->parent->left = leftNode;
            leftNode->parent = nodeRotated->parent;
        }else{
            nodeRotated->parent->right = leftNode;
            leftNode->parent = nodeRotated->parent;
        }
    }else{
        leftNode->parent = nullptr;
    }
    nodeRotated->parent = leftNode;
    leftNode->right = nodeRotated;
    nodeRotated->left = rightSubtreeHead;
    if(rightSubtreeHead != nullptr){
        rightSubtreeHead->parent = nodeRotated;
    }
    return leftNode;
}

AVLTree* AVLTree::LeftRotate()
{
    AVLTree* nodeRotated = this;
    AVLTree* rightNode = this->right;
    AVLTree* leftSubtreeHead = this->right->left;

    if(nodeRotated->parent != nullptr)
    {
        if(nodeRotated == nodeRotated->parent->left){
            nodeRotated->parent->left = rightNode;
            rightNode->parent = nodeRotated->parent;
        }else{
                nodeRotated->parent->right = rightNode;
                rightNode->parent = nodeRotated->parent;
        }
    }else{
        rightNode->parent = nullptr;
    }
    nodeRotated->parent = rightNode;
    rightNode->left = nodeRotated;
    nodeRotated->right = leftSubtreeHead;
    if(leftSubtreeHead != nullptr){
        leftSubtreeHead->parent = nodeRotated;
    }
    return rightNode;
}

void AVLTree::ToString()
{
    if(parent == nullptr){
        cout << value << ", Address: " << this << endl;
    }else{
        if(this == parent->left){
            cout << "L: " << value << ", Address: " << this << " ,Parent Value: " << parent->value <<  endl;
        }else{
            if(this == parent->right){
                cout << "R: " << value << ", Address: " << this << " ,Parent Value: " << parent->value << endl;
            }
        }
    }
    
    if(left != nullptr){
        left->ToString();
    }
    if(right != nullptr){
        right->ToString();
    }
}

bool AVLTree::Verify()
{
    if(-1 <= this->ComputeUnbalanceLevel() <= 1)
    {
        return true;
    }else{
        return false;
    }
}

int AVLTree::height()
{
    if(this != nullptr)
    {
        int leftHeight = this->left->height(), rightHeight = this->right->height();
        if(leftHeight > rightHeight){
            return (leftHeight+1);
        }else{
            return (rightHeight+1);
        }
    }else{
        return 0;
    }
}
