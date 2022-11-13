//
// Created by mario on 13/11/2022.
//

#ifndef UNTITLED_AVLTREE_H
#define UNTITLED_AVLTREE_H


class AVLTree {
private:
    char value; //Character value being stored in the Node
    AVLTree *left, *right, *parent; //Pointers to left and right children AVLTree Nodes and a pointer to the parent node;
    void LeftRotate(); //Rotation of the nodes to the left
    void RightRotate(); //Rotation of the nodes to the right
    int ComputeUnbalanceLevel(); //The balance leve of the node, it must be between -1 and 1

public:
    AVLTree(); //Sets value to null character which is char(0)
    ~AVLTree(); //deletes the children nodes and the node itself
    void Insert(char v); //Creates a new pointer then connects it depending on the value of char
    AVLTree *Find(char v); //Searches for v and returns the address
    AVLTree *Delete(char v); //Searches for v, returns the address then removes it from the tree structure
    void ToString(); //Displays the tree in a string structure
    bool Verify(); //
};


#endif //UNTITLED_AVLTREE_H
