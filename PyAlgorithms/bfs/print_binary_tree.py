# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None
from dfs.tree import TreeNode
from dfs.tree import BinaryTree


class Solution(object):
    def levelOrder(self, root):
        """
        :type root: TreeNode
        :rtype: List[List[int]]
        """
        res = []
        if root is None:
            return res
        queue = []
        queue.append(root)
        while len(queue) != 0:
            sub_res = []
            length = len(queue)
            for i in range(length):
                node = queue.pop(0)
                sub_res.append(node.val)
                if node.left is not None:
                    queue.append(node.left)
                if node.right is not None:
                    queue.append(node.right)
            res.append(sub_res)
        return res


if __name__ == '__main__':
    l = [3, 9, 20, None, None, 15, 7]
    t = BinaryTree(l)
    s = Solution()
    print(s.levelOrder(t.root))
