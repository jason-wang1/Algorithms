#include <vector>
#include <iostream>
using namespace std;
/**
 * https://leetcode-cn.com/problems/gas-station/
 * 在一条环路上有N个加油站，其中第i个加油站有汽油gas[i]升。
 * 你有一辆油箱容量无限的的汽车，从第 i 个加油站开往第 i+1个加油站需要消耗汽油cost[i]升。你从其中的一个加油站出发，开始时油箱为空。
 * 如果你可以绕环路行驶一周，则返回出发时加油站的编号，否则返回 -1。
 *
 * 输入:
 * gas  = [1,2,3,4,5]
 * cost = [3,4,5,1,2]
 * 输出: 3
 */
class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        for (int i = 0; i < gas.size(); ++i) {
            gas[i] -= cost[i];
        }
        for (int i = 0; i < gas.size(); ++i) {
            int remain = 0;
            for (int j = i; j < gas.size(); ++j) {
                remain += gas[j];
                if (remain < 0)
                    break;
            }

            if (remain < 0)
                continue;

            for (int j = 0; j < i; ++j) {
                remain += gas[j];
                if (remain < 0)
                    break;
            }

            if (remain < 0)
                continue;
            else
                return i;
        }
        return -1;
    }
};

int main() {
    vector<int> gas{1, 2, 3, 4, 5};
    vector<int> cost{3, 4, 5, 1, 2};
    Solution s;
    cout << s.canCompleteCircuit(gas, cost) << endl;
    return 0;
}