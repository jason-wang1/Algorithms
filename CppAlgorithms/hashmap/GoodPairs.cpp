#include <vector>
#include <unordered_map>
#include <iostream>
using namespace std;

/**
 * https://leetcode-cn.com/problems/number-of-good-pairs/
 *
 * 给你一个整数数组 nums 。
 * 如果一组数字 (i,j) 满足 nums[i] == nums[j] 且 i < j ，就可以认为这是一组 好数对 。
 * 返回好数对的数目。
 *
 * 输入：nums = [1,2,3,1,1,3]
 * 输出：4
 * 解释：有 4 组好数对，分别是 (0,3), (0,4), (3,4), (2,5) ，下标从 0 开始
 */
class Solution {
public:
    int numIdenticalPairs(vector<int>& nums) {
        unordered_map<int, int> num_cnt_map;
        int res = 0;
        for (int num: nums){
            res += num_cnt_map[num];
            ++num_cnt_map[num];
        }
        return res;
    }
};

int main() {
    vector<int> nums{1, 2, 3, 1, 1, 3};
    Solution s;
    cout << s.numIdenticalPairs(nums) << endl;
    return 0;
}