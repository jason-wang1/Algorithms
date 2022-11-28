// 题目id：1046
// 题目名称：最后一块石头的重量

#include <vector>
#include <queue>
#include <iostream>
using namespace std;

class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int> q(stones.begin(), stones.end());
        while (q.size() > 1){
            int a = q.top();
            q.pop();
            int b = q.top();
            q.pop();
            if (a > b){
                q.push(a-b);
            } else if (a < b){
                q.push(b-a);
            }
        }
        if (q.empty()) return 0;
        else return q.top();
    }

};

int main() {
    Solution s;
    vector<int> v{2,7,4,1,8,1};
    cout << s.lastStoneWeight(v) << endl;
}