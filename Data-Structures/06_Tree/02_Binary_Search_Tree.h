#ifndef BINARY_SEARCH_TREE_H
#define BINARY_SEARCH_TREE_H
#include "01_Binary_Tree.h"

bool search(TreeNode* root, int target) {
    if (!root) {    
        return false;
    }

    if (target > root->val) {
        return search(root->right, target);
    } else if (target < root->val) {
        return search(root->left, target);
    } else {
        return true;
    }
}

#endif // BINARY_SEARCH_TREE_H