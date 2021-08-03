#include <vector>
#include <unordered_map>
#include <iostream>
using namespace std;

/**
 * https://leetcode-cn.com/problems/contiguous-sequence-lcci/
 *
 * 给定一个整数数组，找出总和最大的连续数列，并返回总和
 *
 * 示例：
 * 输入： [-2,1,-3,4,-1,2,1,-5,4]
 * 输出： 6
 * 解释： 连续子数组 [4,-1,2,1] 的和最大，为 6。
 */
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        vector<int> dp;
        dp.push_back(nums[0]);
        int res = nums[0];
        for (int i = 1; i < nums.size(); ++i) {
            if (dp[i-1] <= 0)
                dp.push_back(nums[i]);
            else
                dp.push_back(nums[i] + dp[i-1]);

            if (dp[i] > res)
                res = dp[i];
        }
        return res;
    }
};

int main(){
    vector<int> nums{-2,1,-3,4,-1,2,1,-5,4};
    Solution s;
    cout << s.maxSubArray(nums) << endl;
    return 0;
}