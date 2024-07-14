#ifndef DEPTH_FIRST_SEARCH_H
#define DEPTH_FIRST_SEARCH_H
#include "01_Binary_Tree.h"
#include <iostream>

void print(int val) {
    printf("%d, ", val);
}

void inorder(TreeNode* root) {
    if (!root) {
        return;
    }

    inorder(root->left);
    print(root->val);
    inorder(root->right);
}

void preorder(TreeNode* root) {
    if (!root) {
        return;
    }

    print(root->val);
    preorder(root->left);
    preorder(root->right);
}

void postorder(TreeNode* root) {
    if (!root) {
        return;
    }

    postorder(root->left);
    postorder(root->right);
    print(root->val);
}

#endif // DEPTH_FIRST_SEARCH_H