#include <vector>
#include <iostream>
#include "../structure/ListNode.h"
using namespace std;

/**
 * https://leetcode-cn.com/problems/kth-node-from-end-of-list-lcci/
 * 实现一种算法，找出单向链表中倒数第 k 个节点。返回该节点的值。
 * 输入： 1->2->3->4->5 和 k = 2
 * 输出： 4
 */

class Solution {
public:
    int kthToLast(ListNode* head, int k) {
        ListNode *first = head;
        ListNode *last = head;
        for (int i = 0; i < k; ++i) {
            last = last->next;
        }
        while (last){
            last = last->next;
            first = first->next;
        }
        return first->val;
    }
};


int main() {
    Solution s;
    vector<int> v{1, 2, 3, 4, 5};
    ListNode listNode(v);
    cout << s.kthToLast(&listNode, 2) << endl;
}
