class Solution(object):
    def maxSubArray(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        dp = []
        res = nums[0]
        dp.append(nums[0])  # 这里不能使用 dp[0] = nums[0]，会导致 list assignment index out of range
        for i in range(1, len(nums)):
            if dp[i - 1] <= 0:
                dp.append(nums[i])
            else:
                dp.append(nums[i] + dp[i - 1])

            if dp[i] > res:
                res = dp[i]

        return res


if __name__ == '__main__':
    nums = [-2, 1, -3, 4, -1, 2, 1, -5, 4]
    s = Solution()
    print(s.maxSubArray(nums))
