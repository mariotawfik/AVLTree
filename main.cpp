#include <iostream>
#include "AVLTree.h"
using namespace std;

int main() {

    AVLTree* Head = new AVLTree;
    Head = Head->Insert('a');
    Head = Head->Insert('b');
    Head = Head->Insert('d');
    Head = Head->Insert('c');
    Head = Head->Insert('f');
    Head = Head->Insert('e');
    Head = Head->Insert('k');
    Head = Head->Insert('j');

    return 0;
}
