# https://leetcode-cn.com/problems/number-of-good-pairs/
class Solution(object):
    def numIdenticalPairs1(self, nums):
        """
        时间超过84%
        :type nums: List[int]
        :rtype: int
        """
        d = {}
        res = 0
        for e in nums:
            e_num = d.get(e, 0)
            d[e] = d.get(e, 0) + 1
            res += e_num
        return res

    def numIdenticalPairs2(self, nums):
        """
        时间超过96%
        优化：不需要e_num做中间变量；当d[e] = 0时，res不需要计算
        :type nums: List[int]
        :rtype: int
        """
        d = {}
        res = 0
        for e in nums:
            if e not in d.keys():
                d[e] = 1
            else:
                res += d[e]
                d[e] += 1
        return res


if __name__ == '__main__':
    nums = [1, 2, 3, 1, 1, 3]
    s = Solution()
    print(s.numIdenticalPairs2(nums))
