
#ifndef TREE_H
#define TREE_H

class TreeNode {
    public:

    int val;
    TreeNode* left;
    TreeNode* right;

    TreeNode();
    TreeNode(int x);
    TreeNode(int x, TreeNode* left, TreeNode* right);
};

#endif // TREE_H

