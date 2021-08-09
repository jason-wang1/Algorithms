#include <vector>
#include <unordered_set>
#include <iostream>
using namespace std;

/**
 * https://leetcode-cn.com/problems/permutations/
 *
 * 给定一个 没有重复 数字的序列，返回其所有可能的全排列。
 * 输入: [1,2,3]
 * 输出:
 * [
 *   [1,2,3],
 *   [1,3,2],
 *   [2,1,3],
 *   [2,3,1],
 *   [3,1,2],
 *   [3,2,1]
 * ]
 *
 */
class Solution {
private:
    vector<vector<int>> *res;
    unordered_set<int> used;
    vector<int> *path;

    void backtracking(vector<int>& nums, int depth){
        if (depth < nums.size()){
            // 对于当前节点，遍历可走路径
            for (int num: nums){
                if (used.find(num) == used.end()){
                    path->push_back(num);
                    used.insert(num);

                    // 递归深度搜索
                    backtracking(nums, depth+1);

                    // 回溯
                    path->pop_back();
                    used.erase(num);
                }
            }
        } else {
            auto *p = new vector<int>(*path);
            res->push_back(*p);
        }
    }

public:
    vector<vector<int>> permute(vector<int>& nums) {
        res = new vector<vector<int>>;
        used.clear();
        path = new vector<int>;
        backtracking(nums, 0);
        return *res;
    }
};

int main() {
    Solution s;
    vector<int> input{1, 2, 3};
    const vector<vector<int>> &res = s.permute(input);
    for (vector<int> v: res){
        for (int e: v){
            cout << e << " ";
        }
        cout << endl;
    }
    return 0;
}
