#include <vector>
#include <iostream>
using namespace std;

/**
 * https://leetcode-cn.com/problems/pascals-triangle/
 *
 * 给定一个非负整数 numRows，生成杨辉三角的前 numRows 行。
 *
 * 示例：
 * 输入: 5
 * 输出:
 * [
 *      [1],
 *     [1,1],
 *    [1,2,1],
 *   [1,3,3,1],
 *  [1,4,6,4,1]
 * ]
 */
class PascalTriangle {
private:
    vector<vector<int>> *res;

    void recursive(int numRows, vector<int> *before){
        --numRows;
        if (numRows == 0){
            return;
        }
        vector<int> *later = new vector<int>;
        for (int i = 0; i < before->size()+1; ++i) {
            int left;
            int right;
            if (i == 0)
                left = 0;
            else
                left = (*before)[i-1];
            if (i == before->size())
                right = 0;
            else
                right = (*before)[i];
            later->push_back(left + right);
        }
        res->push_back(*later);
        recursive(numRows, later);
    }

public:
    vector<vector<int>> generate(int numRows) {
        res = new vector<vector<int>>;
        if (numRows == 0){
            return *res;
        }
        auto *first = new vector<int>{1};
        res->push_back(*first);
        recursive(numRows, first);
        return *res;
    }
};

int main(){
    PascalTriangle s{};
    vector<vector<int>> res = s.generate(6);
    for(vector<int> v: res){
        for (int e: v){
            cout << e << " ";
        }
        cout << endl;
    }
}