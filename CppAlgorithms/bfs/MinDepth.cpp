// 题目id：111
// 题目名称：二叉树的最小深度
#include "../structure/TreeNode.h"
#include <queue>
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

class Solution {
public:
    int minDepth(TreeNode* root) {
        if (root == nullptr) return 0;
        queue<TreeNode*> q;
        int depth = 0;
        bool loop = true;
        q.push(root);
        while (!q.empty() && loop){
            depth ++;
            unsigned int size = q.size();
            for (int i = 0; i < size; ++i) {
                TreeNode* node = q.front();
                if (node->left == nullptr && node->right == nullptr){
                    loop = false;
                    break;
                }
                if (node->left != nullptr)
                    q.push(node->left);
                if (node->right != nullptr)
                    q.push(node->right);

                q.pop();
            }
        }
        return depth;
    }
};
