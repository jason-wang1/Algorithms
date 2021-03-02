import copy


class Solution(object):
    """
    https://leetcode-cn.com/problems/permutations/
    """
    def permute(self, nums):
        """
        :type nums: List[int]
        :rtype: List[List[int]]
        """
        def backtrack(nums, res, path):
            if len(path) == len(nums):
                res.append(copy.copy(path))
                return

            for item in nums:
                if item not in path:
                    path.append(item)
                    # 深度优先搜索
                    backtrack(nums, res, path)
                    # 回溯
                    path.pop()

        res = []
        path = []
        backtrack(nums, res, path)
        return res


if __name__ == '__main__':
    nums = [1, 2, 3]
    s = Solution()
    res = s.permute(nums)
    print(res)
