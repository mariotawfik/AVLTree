//
// Created by mario on 13/11/2022.
//

#ifndef UNTITLED_AVLTREE_H
#define UNTITLED_AVLTREE_H


class AVLTree {
private:
    char value; //Character value being stored in the Node
    int height(); //The height of the node (used to compute the balance)
    AVLTree *left, *right, *parent; //Pointers to left and right children AVLTree Nodes and a pointer to the parent node;
    AVLTree* LeftRotate(); //Rotation of the nodes to the left
    AVLTree* RightRotate(); //Rotation of the nodes to the right
    int ComputeUnbalanceLevel(); //The balance leve of the node, it must be between -1 and 1

public:
    AVLTree(); //Sets value to null character which is char(0)
    ~AVLTree(); //deletes the children nodes and the node itself
    AVLTree* Insert(char v); //Creates a new pointer then connects it depending on the value of char. Returns a pointer to the head of the tree.
    AVLTree *Find(char v); //Searches for v and returns the address
    AVLTree *Delete(char v); //Searches for v, returns the address then removes it from the tree structure
    void ToString(); //Displays the tree in a string structure
    bool Verify(); //Verifies that the tree is balanced by checking the balance of the head of the tree
};


#endif //UNTITLED_AVLTREE_H
