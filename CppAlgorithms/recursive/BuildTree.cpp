// 题目id：剑指 Offer 07
// 题目名称：重建二叉树

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
#include <unordered_map>
#include "../structure/TreeNode.h"

using namespace std;
class BuildTree {
private:
    unordered_map<int, int> index;

    TreeNode* myBuildTree(const vector<int>& preorder, const vector<int>& inorder,
                          int preorder_left, int preorder_right, int inorder_left, int inorder_right) {
        if (preorder_left > preorder_right) return nullptr;
        
        // 前序遍历最左边节点为根节点
        int preorder_root = preorder_left;
        // 根据根节点的值定位到中序遍历中，根节点的索引
        int inorder_root = index[preorder[preorder_root]];
        
        // 建立根节点
        TreeNode *root = new TreeNode(preorder[preorder_root]);
        // 左子树的节点数
        int size_left_subtree = inorder_root - inorder_left;
        // 构造左子树
        root->left = myBuildTree(preorder, inorder, preorder_root + 1, preorder_root + size_left_subtree, inorder_left, inorder_root - 1);
        // 构造右子树
        root->right = myBuildTree(preorder, inorder, preorder_root + size_left_subtree + 1, preorder_right, inorder_root + 1, inorder_right);

        return root;
    }
public:

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int n = inorder.size();
        for (int i = 0; i < n; ++i) {
            index[inorder[i]] = i;
        }
        return myBuildTree(preorder, inorder, 0, n-1, 0, n-1);
    }

};