package dp;

/**
 * https://leetcode-cn.com/problems/gu-piao-de-zui-da-li-run-lcof/
 */
public class MaxProfile {
    public static void main(String args[]){
        int[] arr = {7,1,5,3,6,4};
        System.out.println(new MaxProfile().maxProfit(arr));
    }

    public int maxProfit(int[] prices) {
        if (prices.length < 2){
            return 0;
        }
        int min = prices[0];
        int res = 0;
        for (int i = 1; i < prices.length; i++) {
            if (prices[i] < min){
                min = prices[i];
            }
            if (prices[i] - min > res){
                res = prices[i] - min;
            }
        }
        return res;
    }
}
