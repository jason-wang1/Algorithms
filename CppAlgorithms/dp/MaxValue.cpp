#include <vector>
#include <iostream>
using namespace std;

/**
 * https://leetcode-cn.com/problems/li-wu-de-zui-da-jie-zhi-lcof/
 *
 * 在一个 m*n 的棋盘的每一格都放有一个礼物，每个礼物都有一定的价值（价值大于 0）。
 * 你可以从棋盘的左上角开始拿格子里的礼物，并每次向右或者向下移动一格、直到到达棋盘的右下角。给定一个棋盘及其上面的礼物的价值，请计算你最多能拿到多少价值的礼物？
 *
 * 输入:
 * [
 *   [1,3,1],
 *   [1,5,1],
 *   [4,2,1]
 * ]
 * 输出: 12
 * 解释: 路径 1→3→5→2→1 可以拿到最多价值的礼物
 */
class MaxValue {
public:
    int maxValue(vector<vector<int>>& grid) {
        int rowNum = grid.size();
        int colNum = grid[0].size();

        int dp[rowNum][colNum];
        dp[0][0] = grid[0][0];

        for (int i = 1; i < rowNum; ++i) {
            dp[i][0] = grid[i][0] + dp[i-1][0];
        }
        for (int i = 1; i < colNum; ++i) {
            dp[0][i] = grid[0][i] + dp[0][i-1];
        }
        for (int i = 1; i < rowNum; ++i) {
            for (int j = 1; j < colNum; ++j) {
                dp[i][j] = grid[i][j] + max(dp[i-1][j], dp[i][j-1]);
            }
        }
        return dp[rowNum-1][colNum-1];
    }
};

int main() {
    MaxValue m;
    vector<vector<int>> v{
        {1,3,1},
        {1,5,1},
        {4,2,1}
    };
    int res = m.maxValue(v);
    cout << res << endl;
}
