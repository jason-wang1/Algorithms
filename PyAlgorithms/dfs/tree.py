from collections import deque


class TreeNode(object):
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None


class BinaryTree(object):
    def __init__(self, l):
        p = TreeNode(l[0])
        self.root = p
        q = deque()
        i = 0
        while p is not None:
            if 2*i+1 < len(l) and l[2*i+1] is not None:
                p.left = TreeNode(l[2*i+1])
                q.append(p.left)
            if 2*i+2 < len(l) and l[2*i+2] is not None:
                p.right = TreeNode(l[2*i+2])
                q.append(p.right)
            p = q.popleft() if len(q) > 0 else None
            i += 1
