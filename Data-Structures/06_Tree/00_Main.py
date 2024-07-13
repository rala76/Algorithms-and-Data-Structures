from collections import deque

class TreeNode:
    def __init__(self, val = None):
        self.val = val
        self.left = None
        self.right = None

def search(root, target):
    if not root:
        return False
    
    if target > root.val:
        return search(root.right, target)
    elif target < root.val:
        return search(root.left, target)
    else:
        return True

# Insert a new node and return the root of the tree
def insert(root, val):
    if not root:
        return TreeNode(val)
    
    if val > root.val:
        root.right = insert(root.right, val)
    elif val < root.val:
        root.left = insert(root.left, val)
    
    return root

# Return the minimum value node of the BST
def minValueNode(root):
    curr = root
    while curr and curr.left:
        curr = curr.left
    return curr

# Remove a node and return the root of the tree
def remove(root, val):
    if not root:
        return None
    
    # Search for node
    if val > root.val:
        root.right = remove(root.right, val)
    elif val < root.val:
        root.left = remove(root.left, val)
    # Removal process
    else:
        # Case 1
        if not root.left:
            return root.right
        elif not root.right:
            return root.left
        # Case 2
        else:
            minNode = minValueNode(root.right)
            root.val = minNode
            root.right = remove(root.right, minNode.val)
    
    return root

# Depth-First Search (DFS) - inorder, preorder, postorder
def inorder(root):
    if not root:
        return
    
    inorder(root.left)
    print(root.val)
    inorder(root.right)

def preorder(root):
    if not root:
        return
    
    print(root.val)
    preorder(root.left)
    preorder(root.right)

def postorder(root):
    if not root:
        return
    
    postorder(root.left)
    postorder(root.right)
    print(root.val)

# Breadth-First Search (BFS)
def bfs(root):
    queue = deque()

    if root:
        queue.append(root)
    
    level = 0
    while len(queue) > 0:
        print("level:", level)

        for i in range(len(queue)):
            curr = queue.popleft()
            print(curr.val)

            if curr.left:
                queue.append(curr.left)
            if curr.right:
                queue.append(curr.right)
        
        level += 1

def main():
    # Binary Search Tree (BST)
    root = TreeNode(4)

    # Insert nodes
    insert(root, 3)
    insert(root, 6)
    insert(root, 2)
    insert(root, 5)
    insert(root, 7)

    # Search for a given target in the BST
    target = 6
    res = search(root, target)
    if res:
        print("Found node with value ", target)
    else:
        print("Did not find node with value ", target)
    print("")
    
    # Depth First Search (DFS) - inorder, preorder, postorder
    print("inorder:")
    inorder(root)
    print("")

    print("preorder:")
    preorder(root)
    print("")

    print("postorder:")
    postorder(root)
    print("")

    # Breadth First Search (BFS)
    print("bfs:")
    bfs(root)

if __name__ == "__main__":
    main()