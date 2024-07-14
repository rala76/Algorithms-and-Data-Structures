#include "01_Binary_Tree.h"
#include "02_Binary_Search_Tree.h"
#include "03_BST_Insert_and_Remove.h"
#include "04_Depth_First_Search.h"
#include "05_Breadth_First_Search.h"
#include <iostream>

int main() {
    // Binary Search Tree (BST)
    TreeNode* root = new TreeNode(4);

    // Insert Nodes
    insert(root, 3);
    insert(root, 6);
    insert(root, 2);
    insert(root, 5);
    insert(root, 7);

    // Search for a given target in the BST
    int target = 6;
    bool res = search(root, target);
    
    if (res) {
        printf("Found node with value %d\n", target);
    } else {
        printf("Did not find node with value %d\n", target);
    }

    // Depth First Search (DFS) - inorder, preorder, postorder
    inorder(root);
    printf("\n");

    preorder(root);
    printf("\n");

    postorder(root);
    printf("\n");

    // Breadth First Search (BFS)
    bfs(root);

    return 0;
}