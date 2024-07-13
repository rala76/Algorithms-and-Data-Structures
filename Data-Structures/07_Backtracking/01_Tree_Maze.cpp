#include <iostream>
#include <vector>

using std::vector;

class TreeNode {
public:
    int val;
    TreeNode* left = nullptr;
    TreeNode* right = nullptr;

    TreeNode(int val) {
        this->val = val;
    }
};

bool canReachLeaf(TreeNode* root) {
    if (!root || root->val == 0) {
        return false;
    }

    if (!root->left && !root->right) {
        return true;
    }
    if (canReachLeaf(root->left)) {
        return true;
    }
    if (canReachLeaf(root->right)) {
        return true;
    }

    return false;
}

bool leafPath(TreeNode* root, vector<int>* path) {
    if (!root || root->val == 0) {
        return false;
    }
    path->push_back(root->val);

    if (!root->left && !root->right) {
        return true;
    }
    if (canReachLeaf(root->left)) {
        return true;
    }
    if (canReachLeaf(root->right)) {
        return true;
    }
    path->pop_back();

    return false;
}

int main() {
    return 0;
}