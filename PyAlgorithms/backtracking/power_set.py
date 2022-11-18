import copy
class Solution(object):
    def dfs(self, nums, res, path, start):
        print(f"path: {path}; start: {start}")
        res.append(copy.copy(path))
        for i in range(start, len(nums)):
            path.append(nums[i])
            self.dfs(nums, res, path, i+1)
            # 回溯
            path.pop()


    def subsets(self, nums):
        """
        :type nums: List[int]
        :rtype: List[List[int]]
        """
        res = []
        path = []
        self.dfs(nums, res, path, 0)
        return res


if __name__ == '__main__':
    input = [1, 2, 3]
    s = Solution()
    res = s.subsets(input)
    print(res)
