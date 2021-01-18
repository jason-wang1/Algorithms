package dp;

/**
 * 给定一个整数数组，找出总和最大的连续数列，并返回总和
 *
 * 示例：
 * 输入： [-2,1,-3,4,-1,2,1,-5,4]
 * 输出： 6
 * 解释： 连续子数组 [4,-1,2,1] 的和最大，为 6。
 */
public class ContinuousSequence {
    public static void main(String args[]){
        int[] arr = {-2,1,-3,4,-1,2,1,-5,4};
        System.out.println(maxSubArray(arr));
    }

    public static int maxSubArray(int[] nums) {
        int res = nums[0];
        int[] dp = new int[nums.length];
        dp[0] = nums[0];
        for (int i = 1; i < nums.length; i++) {
            dp[i] = dp[i-1]<=0 ? nums[i] : dp[i-1]+nums[i];
            if (dp[i] > res)
                res = dp[i];
        }
        return res;
    }
}
