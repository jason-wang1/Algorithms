// 题目id：61
// 题目名称：旋转链表
#include "../structure/ListNode.h"

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
#include <stdio.h>

struct ListNode* rotateRight(struct ListNode* head, int k){
    if (head == NULL) return NULL;

    int oversize = 0;
    int size = 1;
    struct ListNode* left = head;
    struct ListNode* right = head;
    for (int i = 0; i < k; ++i) {
        if (right->next == NULL){
            oversize = 1;
            break;
        } else {
            right = right->next;
            ++size;
        }
    }

    if (oversize){
        k = k % size;
        right = head;
        for (int i = 0; i < k; ++i) {
            right = right->next;
        }
    }

    while (right->next != NULL){
        right = right->next;
        left = left->next;
    }
    right->next = head;
    head = left->next;
    left->next = NULL;

    return head;
}
