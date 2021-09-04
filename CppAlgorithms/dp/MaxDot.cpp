#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

/**
 * https://leetcode-cn.com/problems/max-dot-product-of-two-subsequences/
 *
 * 给你两个数组 nums1 和 nums2 。
 * 请你返回 nums1 和 nums2 中两个长度相同的 非空 子序列的最大点积。
 * 数组的非空子序列是通过删除原数组中某些元素（可能一个也不删除）后剩余数字组成的序列，但不能改变数字间相对顺序。
 * 比方说，[2,3,5] 是 [1,2,3,4,5] 的一个子序列而 [1,5,3] 不是。
 *
 * 示例 1：:
 * 输入：nums1 = [2,1,-2,5], nums2 = [3,0,-6]
 * 输出：18
 * 解释：从 nums1 中得到子序列 [2,-2] ，从 nums2 中得到子序列 [3,-6] 。
 * 它们的点积为 (2*3 + (-2)*(-6)) = 18 。
 *
 * 示例 2：
 * 输入：nums1 = [3,-2], nums2 = [2,-6,7]
 * 输出：21
 * 解释：从 nums1 中得到子序列 [3] ，从 nums2 中得到子序列 [7] 。
 * 它们的点积为 (3*7) = 21 。
 */
class MaxDot {
public:
    int maxDotProduct(vector<int>& nums1, vector<int>& nums2) {
        int dp[nums1.size()][nums2.size()];
        dp[0][0] = nums1[0] * nums2[0];
        for (int i = 1; i < nums1.size(); ++i) {
            dp[i][0] = max(dp[i-1][0], nums1[i] * nums2[0]);
        }
        for (int j = 1; j < nums2.size(); ++j) {
            dp[0][j] = max(dp[0][j-1], nums1[0] * nums2[j]);
        }
        for (int i = 1; i < nums1.size(); ++i) {
            for (int j = 1; j < nums2.size(); ++j) {
                int mul = nums1[i] * nums2[j];
                int max1 = max(dp[i-1][j], dp[i][j-1]);
                int max2 = (dp[i-1][j-1] > 0) ? mul + dp[i-1][j-1] : mul;
                dp[i][j] = max(max1, max2);
            }
        }
        return dp[nums1.size()-1][nums2.size()-1];
    }
};

int main(){
    MaxDot s;
    vector<int> num1{2,1,-2,5};
    vector<int> num2{3,0,-6};
    int res = s.maxDotProduct(num1, num2);
    cout << res << endl;
    return 0;
}