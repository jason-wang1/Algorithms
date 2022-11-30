// 题目id：121
// 题目名称：买卖股票的最佳时机
#include <vector>
#include <iostream>

using namespace std;

class BestTime {
public:
    int maxProfit(vector<int>& prices) {
        if (prices.empty()) return 0;
        int res = 0;
        int min = prices[0];
        for (int price : prices){
            if (price < min) min = price;
            else {
                if (price - min > res) res = price - min;
            }
        }
        return res;
    }
};


int main(){
    vector<int> nums{7,1,5,3,6,4};
    BestTime s;
    cout << s.maxProfit(nums) << endl;
    return 0;
}