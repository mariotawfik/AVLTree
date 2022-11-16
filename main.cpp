#include <iostream>
#include "AVLTree.h"
using namespace std;

int main() {
    AVLTree* Head = new AVLTree;
    
    Head = Head->Insert(20);
    Head = Head->Insert(10);
    Head = Head->Insert(30);
    Head = Head->Insert(60);
    cout << Head->Verify();
    
    return 0;
}
