#include <stddef.h>
#include <vector>
#include <iostream>
#include "../structure/TreeNode.h"
using namespace std;
#define INF 0xfffffff

/**
 * https://leetcode-cn.com/problems/er-cha-sou-suo-shu-de-di-kda-jie-dian-lcof/
 * 给定一棵二叉搜索树，请找出其中第k大的节点。
 * 输入: root = [3,1,4,null,2], k = 1
 *    3
 *   / \
 *  1   4
 *   \
 *    2
 * 输出: 4
 */
class TopkInBinaryTree {
private:
    void dfs(TreeNode* node, vector<int> &v){
        if (node == NULL)
            return;
        dfs(node->left, v);
        v.push_back(node->val);
        dfs(node->right, v);
    }
public:
    int kthLargest(TreeNode* root, int k) {
        vector<int> v;
        dfs(root, v);
        return v[v.size() - k];
    }
};

int main() {
    vector<int> v{3,1,4,INF,2};
    BinaryTree tree(v);
    TopkInBinaryTree s;
    int res = s.kthLargest(tree.root, 2);
    cout << res << endl;
    return 0;
}