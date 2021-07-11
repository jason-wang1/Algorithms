#include <iostream>
#include <vector>
using std::vector;

/**
 * https://leetcode-cn.com/problems/binary-search/
 *
 * 给定一个 n 个元素有序的（升序）整型数组nums 和一个目标值target，
 * 写一个函数搜索nums中的 target，如果目标值存在返回下标，否则返回 -1
 *
 * 示例：
 * 输入: nums = [-1,0,3,5,9,12], target = 9
 * 输出: 4
 * 解释: 9 出现在 nums 中并且下标为 4
 */

int binary_sort(vector<int>& nums, int target) {
    auto left = nums.begin();
    auto right = nums.end();
    while (left <= right){
        auto mid = left + (right - left) / 2;
        if (*mid < target)
            left = mid + 1;
        else if (*mid > target)
            right = mid -1;
        else
            return mid - nums.begin();
    }
    return -1;
}

int main() {
    vector<int> nums = {-1, 0, 3, 5, 9, 12};
    int target = 9;
    int res = binary_sort(nums, target);
    std::cout << res << std::endl;
}