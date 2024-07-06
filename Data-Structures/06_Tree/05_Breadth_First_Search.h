#ifndef BREADTH_FIRST_SEARCH_H
#define BREADTH_FIRST_SEARCH_H
#include "01_Binary_Tree.h"
#include <iostream>
#include <queue>

using std::queue;

void bfs(TreeNode* root) {
    queue<TreeNode*> queue;
    
    if (root) {
        queue.push(root);
    }

    int level = 0;
    while (queue.size() > 0) {
        printf("level: %d\n", level);

        int length = queue.size();
        for (int i = 0; i < length; i++) {
            TreeNode* curr = queue.front();
            queue.pop();
            printf("%d ", curr->val);

            if (curr->left) {
                queue.push(curr->left);
            }
            if (curr->right) {
                queue.push(curr->right);
            }
        }

        level++;
        printf("\n");
    }
}

#endif // BREADTH_FIRST_SEARCH_H