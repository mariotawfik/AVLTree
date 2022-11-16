#include <iostream>
#include "AVLTree.h"
using namespace std;

int main() {
    
    srand(time(NULL));
    
    for(int j = 0; j < 10; j++)
    {
        AVLTree* Head = new AVLTree;
    
        for(int i = 0; i < 10; i++)
        {
            int randomNum = 1+rand()%100;
            Head = Head->Insert(randomNum);
        }
    
        cout << Head->Verify() << endl;
    }
    
    return 0;
}
