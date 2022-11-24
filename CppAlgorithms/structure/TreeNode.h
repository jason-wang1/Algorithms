#include <stddef.h>
#include <vector>
#include <deque>
#include <iostream>
using namespace std;
#define INF 0xfffffff

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

class BinaryTree1 {
public:

    Node *root;

    BinaryTree1(vector<int> *vec){
        Node *p = new Node((*vec)[0]);
        root = p;
        deque<Node *> queue;
        int i = 0;
        while (p != NULL){
            if (2*i+1 < vec->size() && (*vec)[2 * i + 1] != INF){
                p->left = new Node((*vec)[2 * i + 1]);
                queue.push_back(p->left);
            }
            if (2*i+2 < vec->size() && (*vec)[2 * i + 2] != INF){
                p->right = new Node((*vec)[2 * i + 2]);
                queue.push_back(p->right);
            }
            p = queue.front();
            queue.pop_front();
            ++i;
        }
    }
};

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
