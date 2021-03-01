class Solution(object):
    def search(self, nums, target):
        """
        :type nums: List[int]
        :type target: int
        :rtype: int
        """
        left = 0
        right = len(nums) - 1
        while right >= left:
            mid = int(left + (right - left) / 2)
            if nums[mid] > target:
                right = mid - 1
                continue
            elif nums[mid] < target:
                left = mid + 1
            else:
                return mid
        return -1


if __name__ == '__main__':
    nums = [-1, 0, 3, 5, 9, 12]
    target = 13
    s = Solution()
    print(s.search(nums, target))
