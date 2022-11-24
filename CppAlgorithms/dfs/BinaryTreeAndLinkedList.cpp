// 题目id：剑指 Offer 36
// 题目名称：二叉搜索树与双向链表

/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;

    Node() {}

    Node(int _val) {
        val = _val;
        left = NULL;
        right = NULL;
    }

    Node(int _val, Node* _left, Node* _right) {
        val = _val;
        left = _left;
        right = _right;
    }
};
*/

#include "../structure/TreeNode.h"
class BinaryTreeAndLinkedList {
public:
    Node* head;
    Node* pre;
    void dfs(Node *pNode) {
        if (pNode != nullptr){
            dfs(pNode->left);
            if (pre == nullptr) head = pNode;
            else pre->right = pNode;
            pNode->left = pre;
            pre = pNode;
            dfs(pNode->right);
        }
    }

    Node* treeToDoublyList(Node* root) {
        if (root == nullptr) return nullptr;
        dfs(root);
        head->left = pre;
        pre->right = head;
        return head;
    }
};

int main() {
    vector<int> v{4,2,5,1,3};
    BinaryTree1 tree(&v);
    BinaryTreeAndLinkedList s;
    Node* res = s.treeToDoublyList(tree.root);
    cout << res << endl;
    return 0;
}