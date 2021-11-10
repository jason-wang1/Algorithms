from tree import TreeNode
from tree import BinaryTree


class Solution(object):
    """
    给定一棵二叉搜索树，请找出其中第k大的节点。
        输入: root = [3,1,4,null,2], k = 1
           3
          / \
         1   4
          \
           2
        输出: 4
    """

    def __init__(self):
        self.count = 0
        self.res = 0

    def kthLargest(self, root, k):
        """
        时间复杂度O(k)，不会全部遍历整棵树
        :type root: TreeNode
        :type k: int
        :rtype: int
        """
        self.dfs(root, k)
        return self.res

    def dfs(self, node, k):
        if node is not None and self.count < k:
            self.dfs(node.right, k)
            self.count += 1
            if self.count == k:
                self.res = node.val
                return
            self.dfs(node.left, k)


if __name__ == '__main__':
    l = [3, 1, 4, None, 2]
    tree = BinaryTree(l)
    r = tree.root
    s = Solution()
    print(s.kthLargest(r, 2))
