#include <stddef.h>
#include <vector>
#include <iostream>
#include "../structure/TreeNode.h"
using namespace std;
#define INF 0xfffffff
/**
 * https://leetcode-cn.com/problems/er-cha-shu-de-shen-du-lcof/
 *
 * 输入一棵二叉树的根节点，求该树的深度。从根节点到叶节点依次经过的节点（含根、叶节点）形成树的一条路径，最长路径的长度为树的深度。
 * 例如：
 * 给定二叉树 [3,9,20,null,null,15,7]，
 *     3
 *    / \
 *   9  20
 *     /  \
 *    15   7
 *
 * 返回它的最大深度 3 。
 */
class DepthOfBinaryTree {
private:
    void dfs(int depth, int& res, TreeNode* node) {
        if (node == NULL)
            return;
        ++depth;
        if (res < depth)
            ++res;
        dfs(depth, res, node->left);
        dfs(depth, res, node->right);
    }

public:
    int maxDepth(TreeNode* root) {
        if (root == NULL)
            return 0;
        int res = 0;
        dfs(0, res, root);
        return res;
    }
};

int main(){
    vector<int> v{3,9,20,INF,INF,15,7};
    BinaryTree tree(v);
    DepthOfBinaryTree s;
    int res = s.maxDepth(tree.root);
    cout << res << endl;
    return 0;
}