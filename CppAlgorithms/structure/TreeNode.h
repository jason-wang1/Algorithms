#include <stddef.h>
#include <vector>
#include <deque>
#include <iostream>
using namespace std;
#define INF 0xfffffff

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(const int x) : val(x), left(NULL), right(NULL) {}
};


class BinaryTree {
public:

    TreeNode *root;

    BinaryTree(vector<int> &vec){
        TreeNode *p = new TreeNode(vec[0]);
        root = p;
        deque<TreeNode *> queue;
        int i = 0;
        while (p != nullptr){
            if (2*i+1 < vec.size() && vec[2 * i + 1] != INF){
                p->left = new TreeNode(vec[2 * i + 1]);
                queue.push_back(p->left);
            }
            if (2*i+2 < vec.size() && vec[2 * i + 2] != INF){
                p->right = new TreeNode(vec[2 * i + 2]);
                queue.push_back(p->right);
            }
            p = queue[0];
            queue.pop_front();
            ++i;
        }
    }
};
