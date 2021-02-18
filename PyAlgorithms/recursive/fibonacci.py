# https://leetcode-cn.com/problems/fibonacci-number/
class Solution(object):
    # 递归，时间复杂度为O(n^2)
    def fib1(self, n):
        """
        :type n: int
        :rtype: int
        """
        if n == 0 or n == 1:
            return n

        return self.fib1(n - 1) + self.fib1(n - 2)

    d = {}

    # 递归，但使用哈希表缓存已经计算过的值，时间复杂度为O(n)
    def fib(self, n):
        """
        :type n: int
        :rtype: int
        """
        if n == 0 or n == 1:
            return n

        if n in self.d:
            return self.d[n]
        else:
            res = self.fib(n - 1) + self.fib(n - 2)
            self.d[n] = res
            return res


if __name__ == '__main__':
    s = Solution()
    print(s.fib(4))
