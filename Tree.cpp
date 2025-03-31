#include <iostream>
#include <vector>
#include <stack>
using namespace std;

class TreeNode {
    public:
        int val;
        TreeNode* left;
        TreeNode* right;
        TreeNode() : val(0), left(nullptr), right(nullptr) {}
        TreeNode(int x) : val(x), left(nullptr), right(nullptr) {} // initialisation list
        TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}        
};

class BinarySerchTree {   
    private:

    TreeNode* root;

    void Traversal_rec(TreeNode* root) {

        if (nullptr == root) return;
        Traversal_rec(root->left);
        cout << root->val << " " ;
        Traversal_rec(root->right);
    }


    vector<int> Traversal_iter(TreeNode* root) {
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
        

    TreeNode* insertNode(TreeNode* root, int value) {
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

    public:

        BinarySerchTree() : root(nullptr) {}

        void insertNode(const int val){
            root = insertNode(root, val);
        }
        void Traversal_rec() {
            Traversal_rec(root);
        }
        vector<int> Traversal_iter() {
            return Traversal_iter(root);
        }
        
};
int main(){
    BinarySerchTree t;
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