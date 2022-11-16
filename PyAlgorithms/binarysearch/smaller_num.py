class Solution(object):
    def smallerNumbersThanCurrent(self, nums):
        """
        使用hash表查找
        :type nums: List[int]
        :rtype: List[int]
        """
        sorted_nums = sorted(nums)
        d = {}
        for i in range(len(sorted_nums)):
            if i != 0 and sorted_nums[i] == sorted_nums[i-1]:
                continue
            d[sorted_nums[i]] = i
        res = []
        for i in range(len(nums)):
            res.append(d[nums[i]])
        return res


if __name__ == '__main__':
    nums = [8, 1, 2, 2, 3]
    s = Solution()
    print(s.smallerNumbersThanCurrent(nums))
