#ifndef BINARY_TREE_H
#define BINARY_TREE_H

class TreeNode {
public:
    int val;
    TreeNode* left = nullptr;
    TreeNode* right = nullptr;

    TreeNode() {}
    TreeNode(int val) {
        this->val = val;
    }
};

#endif // BINARY_TREE_H