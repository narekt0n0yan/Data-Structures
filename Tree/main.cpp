#include "TreeNode.h"
#include "BinarySearchTree.h"
#include <iostream>
using namespace std;


int main(){
    BinarySearchTree t;
    t.insertNode(10);
    t.insertNode(30);
    t.insertNode(5);
    t.insertNode(15);
    t.insertNode(25);
    t.insertNode(35);
    t.insertNode(80);
    t.insertNode(100);

    t.Traversal_rec();
    vector<int> tree = t.Traversal_iter(); 
    cout <<  '\n' << endl;
    for (int x :tree) {
        cout << x << " ";
    }

    
    return 0;
}