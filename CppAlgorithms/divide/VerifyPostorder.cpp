// 题目id：剑指 Offer 33
// 题目名称：二叉搜索树的后序遍历序列
#include <stddef.h>
#include <vector>
#include <iostream>
using namespace std;

class VerifyPostorder {
private:
    bool recur(vector<int>& postorder, int i, int j) {
        if (i>=j)
            return true;
        int mid = i;
        while (postorder[mid] < postorder[j])
            mid ++;
        int tmp = mid;
        while (postorder[tmp] > postorder[j])
            tmp ++;
        return tmp == j && recur(postorder, i, mid-1) && recur(postorder, mid, j - 1);
    }

public:
    bool verifyPostorder(vector<int>& postorder) {
        return recur(postorder, 0, postorder.size()-1);
    }
};

int main(){
    vector<int> v{5, 4, 3, 2, 1};
    VerifyPostorder s;
    cout << s.verifyPostorder(v) << endl;
    return 0;
}