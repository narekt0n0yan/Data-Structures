#include "BinarySearchTree.h"
#include <iostream>
#include <vector>
#include <stack>
#include "TreeNode.h"
#include <queue>

using namespace std;

void BinarySearchTree::Traversal_rec(TreeNode* root) {

        if (nullptr == root) return;
        Traversal_rec(root->left);
        cout << root->val << " " ;
        Traversal_rec(root->right);
    }


vector<int> BinarySearchTree::Traversal_iter(TreeNode* root) {
            TreeNode* curr = root;
            vector<int> res;
            std::stack<TreeNode*> s;

            while(curr != NULL || !s.empty()){
                while(curr != NULL){
                    s.push(curr);
                    curr = curr->left;
                }
                curr = s.top();
                s.pop();
                res.push_back(curr->val);
                curr = curr->right;
            }
            return res;

    }


TreeNode* BinarySearchTree::insertNode(TreeNode* root, int value) {
            if (nullptr == root) { 
                return root = new  TreeNode(value);
            }
            if (value < root->val) {
                root->left = insertNode(root->left, value);
            } else if (value > root->val) {
                root->right = insertNode(root->right, value);
            }
            return root;
        }
vector<vector<int>> BinarySearchTree::levelOrderTraversal(TreeNode* root) {
    vector<vector<int>> result;
    if (!root) return result;

    queue<TreeNode*> q;
    q.push(root);

    while (!q.empty()){
        int levelSize = q.size();
        vector<int> currentLevel;

        for( int i = 0; i < levelSize; ++i){
            TreeNode* current = q.front();
            q.pop();
            currentLevel.push_back(current->val);

            if (current->left) q.push(current->left);
            if (current->right) q.push(current->right);

        }
        result.push_back(currentLevel);

    }
    return result;
}

BinarySearchTree::BinarySearchTree() : root(nullptr) {}

void BinarySearchTree::insertNode(const int val){
        root = insertNode(root, val);
    }

void BinarySearchTree::Traversal_rec() {
        Traversal_rec(root);
    }

vector<int> BinarySearchTree::Traversal_iter() {
        return Traversal_iter(root);
    }

vector<vector<int>> BinarySearchTree::levelOrderTraversal(){
    return levelOrderTraversal(root);
}


    



    
