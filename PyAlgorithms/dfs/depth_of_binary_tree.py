# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None
from tree import TreeNode
from tree import BinaryTree


class Solution(object):
    def __init__(self):
        self.max_depth = 0

    def maxDepth(self, root):
        """
        :type root: TreeNode
        :rtype: int
        """
        self.max_depth = 0
        self.dfs(root, 1)
        return self.max_depth

    def dfs(self, node, depth):
        if node is not None:
            self.dfs(node.left, depth + 1)
            if depth > self.max_depth:
                self.max_depth = depth
            self.dfs(node.right, depth + 1)


if __name__ == '__main__':
    l = [3, 9, 20, None, None, 15, 7]
    t = BinaryTree(l)
    s = Solution()
    print(s.maxDepth(t.root))
