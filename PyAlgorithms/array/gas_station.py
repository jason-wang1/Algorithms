# https://leetcode-cn.com/problems/gas-station/
class Solution(object):
    def canCompleteCircuit1(self, gas, cost):
        """
        根据Java版本原始求解方法，时间复杂度O(n^2)
        :type gas: List[int]
        :type cost: List[int]
        :rtype: int
        """
        gas = [a - b for a, b in zip(gas, cost)]

        for start in range(len(gas)):
            remain = 0
            for i in range(start, len(gas)):
                remain += gas[i]
                if remain < 0:
                    break

            if remain < 0:
                continue

            for i in range(0, start):
                remain += gas[i]
                if remain < 0:
                    break

            if remain >= 0:
                return start

        return -1

    def canCompleteCircuit(self, gas, cost):
        """
        优化后解法，时间复杂度为O(n)
        :type gas: List[int]
        :type cost: List[int]
        :rtype: int
        """
        # 优化，如果总和小于0，则一定不会有解
        if sum(cost) > sum(gas):
            return -1

        # 优化，减少时间复杂度为O(n)
        summed = res = 0
        for i in range(len(gas)):
            summed += gas[i] - cost[i]
            if summed < 0:
                summed = 0
                res = i + 1

        return res


if __name__ == '__main__':
    gas = [1, 2, 3, 4, 5]
    cost = [3, 4, 5, 1, 2]
    s = Solution()
    print(s.canCompleteCircuit(gas=gas, cost=cost))
