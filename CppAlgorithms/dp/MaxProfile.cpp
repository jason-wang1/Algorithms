#include <vector>
#include <iostream>
using namespace std;

/**
 * https://leetcode-cn.com/problems/gu-piao-de-zui-da-li-run-lcof/
 *
 * 假设把某股票的价格按照时间先后顺序存储在数组中，请问买卖该股票一次可能获得的最大利润是多少？
 * 输入: [7,1,5,3,6,4]
 * 输出: 5
 * 解释: 在第 2 天（股票价格 = 1）的时候买入，在第 5 天（股票价格 = 6）的时候卖出，最大利润 = 6-1 = 5 。
 * 注意利润不能是 7-1 = 6, 因为卖出价格需要大于买入价格。
 */
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if (prices.size() < 2)
            return 0;
        int min = prices[0];
        int res = 0;
        for (int i = 1; i < prices.size(); ++i) {
            if (prices[i] < min){
                min = prices[i];
                continue;
            } else {
                int value = prices[i] - min;
                if (value > res)
                    res = value;
            }
        }
        return res;
    }
};

int main() {
    vector<int> prices{7, 1, 5, 3, 6, 4};
    Solution s;
    cout << s.maxProfit(prices) << endl;
    return 0;
}