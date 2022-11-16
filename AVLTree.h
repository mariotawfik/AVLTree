//
// Created by mario on 13/11/2022.
//

#ifndef UNTITLED_AVLTREE_H
#define UNTITLED_AVLTREE_H


class AVLTree {
private:
    int value; //Character value being stored in the Node
    int height(); //The height of the node (used to compute the balance)
    AVLTree *left, *right, *parent; //Pointers to left and right children AVLTree Nodes and a pointer to the parent node;
    AVLTree* LeftRotate(); //Rotation of the nodes to the left
    AVLTree* RightRotate(); //Rotation of the nodes to the right
    int ComputeUnbalanceLevel(); //The balance level of the node, it must be between -1 and 1

public:
    AVLTree(); //Sets value to null character which is char(0)
    ~AVLTree(); //deletes the children nodes and the node itself
    AVLTree* Insert(int v); //Creates a new pointer then organizes the tree. Returns a pointer to the head of the tree.
    AVLTree *Find(int v); //Searches for v and returns the address
    AVLTree *Delete(int v); //Searches for v, returns the address then removes it from the tree structure and organizes it
    void ToString(); //Displays the node in a string structure
    bool Verify(); //Verifies that the tree is balanced by checking the balance of the head of the tree
};


#endif //UNTITLED_AVLTREE_H
