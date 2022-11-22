// 题目id：面试题 02.02
// 题目名称：返回倒数第 k 个节点
#include "../structure/ListNode.h"

//leetcode submit region begin(Prohibit modification and deletion)
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
#include <stdio.h>

int kthToLast(struct ListNode* head, int k){
    struct ListNode *p = head;
    struct ListNode *right = head;
    int i;
    for (i=0; i<k; i++){
        right = right->next;
    }
    while (right != NULL){
        right = right->next;
        p = p->next;
    }
    return p->val;
}
