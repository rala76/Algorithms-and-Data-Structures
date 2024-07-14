class TreeNode:
    def __init__(self, val = None):
        self.val = val
        self.left = None
        self.right = None

def canReachLeaf(root):
    if not root or root.val == 0:
        return False
    
    # Leaf node
    if not root.left and not root.right:
        return True
    # Traverse the left subtree
    if canReachLeaf(root.left):
        return True
    # Traverse the right subtree
    if canReachLeaf(root.right):
        return True
    
    return False

def leafPath(root, path):
    if not root or root.val == 0:
        return False
    path.append(root.val)

    # Leaf node
    if not root.left and not root.right:
        return True
    # Traverse the left subtree
    if leafPath(root.left, path):
        return True
    # Traverse the right subtree
    if leafPath(root.right, path):
        return True
    path.pop()

    return False

def main():
    root = TreeNode(4)
    path = []

    canReachLeaf(root)
    leafPath(root, path)

if __name__ == "__main__":
    main()