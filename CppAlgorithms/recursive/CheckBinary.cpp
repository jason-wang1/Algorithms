#include <stddef.h>
#include <cmath>
#include <vector>
#include <iostream>
#include "../structure/TreeNode.h"
using namespace std;
#define INF 0xfffffff

/**
 * https://leetcode-cn.com/problems/check-balance-lcci/
 *
 * 实现一个函数，检查二叉树是否平衡。在这个问题中，平衡树的定义如下：任意一个节点，其两棵子树的高度差不超过 1。
 * 给定二叉树 [3,9,20,null,null,15,7]
 *     3
 *    / \
 *   9  20
 *     /  \
 *    15   7
 * 返回 true 。
 */
class CheckBinary {
private:
    int depth(TreeNode *node) {
        if (node == NULL)
            return 0;
        return max(depth(node->left), depth(node->right)) + 1;
    }

public:
    bool isBalanced(TreeNode* root) {
        if (root == NULL){
            return true;
        }
        int left = depth(root->left);
        int right = depth(root->right);
        if (abs(left - right) > 1){
            return false;
        }
        return isBalanced(root->left) & isBalanced(root->right);
    }
};

int main(){
    CheckBinary s;
    vector<int> v {3,9,20,INF,INF,15,7};
    BinaryTree tree(v);
    bool res = s.isBalanced(tree.root);
    cout << res << endl;
}