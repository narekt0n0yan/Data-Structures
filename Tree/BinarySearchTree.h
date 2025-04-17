#include "TreeNode.h"
#include <vector>

using namespace std;


class BinarySearchTree { 
    private:

    TreeNode* root;

    void Traversal_rec(TreeNode* root);
    vector<int> Traversal_iter(TreeNode* root);
    TreeNode* insertNode(TreeNode* root,int value);
    vector<vector<int>> levelOrderTraversal(TreeNode* root);


    public:

    BinarySearchTree();

    void insertNode(const int val);
    
    void Traversal_rec();
    
    vector<int> Traversal_iter();

    vector<vector<int>> levelOrderTraversal();

};  
