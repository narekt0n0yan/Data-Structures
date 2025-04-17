#include "BinarySearchTree.h"
#include <iostream>
using namespace std;

int main() {
    BinarySearchTree t;

    // Insert nodes
    t.insertNode(10);
    t.insertNode(30);
    t.insertNode(5);
    t.insertNode(15);
    t.insertNode(25);
    t.insertNode(35);
    t.insertNode(80);
    t.insertNode(100);

    // Recursive in-order traversal
    cout << "Recursive In-Order Traversal: ";
    t.Traversal_rec();

    // Iterative in-order traversal
    cout << "Iterative In-Order Traversal: ";
    vector<int> tree = t.Traversal_iter();
    for (int x : tree) {
        cout << x << " ";
    }
    cout << endl;

    // Level-order traversal
    cout << "Level Order Traversal:\n";
    vector<vector<int>> levels = t.levelOrderTraversal();
    for (const auto& level : levels) {
        for (int x : level) {
            cout << x << " ";
        }
        cout << endl;
    }

    return 0;
}
