#include "BinarySearchTree.h"
#include <iostream>
#include <vector>
#include <stack>
#include "TreeNode.h"

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
