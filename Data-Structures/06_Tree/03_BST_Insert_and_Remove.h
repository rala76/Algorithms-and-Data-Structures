#ifndef BST_INSERT_REMOVE_H
#define BST_INSERT_REMOVE_H
#include "01_Binary_Tree.h"

// Insert a new node and return the root of the tree.
TreeNode* insert(TreeNode* root, int val) {
    if (!root) {
        return new TreeNode(val);
    }

    if (val > root->val) {
        root->right = insert(root->right, val);
    } else if (val < root->val) {
        root->left = insert(root->left, val);
    }

    return root;
}

// Return the minimum value node of the BST.
TreeNode* minValueNode(TreeNode* root) {
    TreeNode* curr = root;

    while (curr && curr->left) {
        curr = curr->left;
    }
    
    return curr;
}

// Remove a node and return the root of the tree.
TreeNode* remove(TreeNode* root, int val) {
    if (!root) {
        return nullptr;
    }

    // Search for node
    if (val > root->val) {
        root->right = remove(root->right, val);
    } else if (val < root->val) {
        root->left = remove(root->left, val);
    // Removal process
    } else {
        // Case 1
        if (!root->left) {
            return root->right;
        } else if (!root->right) {
            return root->left;
        // Case 2
        } else {
            TreeNode* minNode = minValueNode(root->right);
            root->val = minNode->val;
            root->right = remove(root->right, minNode->val);
        }
    }

    return root;
}

#endif // BST_INSERT_REMOVE_H