/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
#include "../structure/ListNode.h"

// 剑指 Offer 25. 合并两个排序的链表
// https://leetcode.cn/problems/he-bing-liang-ge-pai-xu-de-lian-biao-lcof/
class MergeTwoLists {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        if (l1 == nullptr)
            return l2;
        if (l2 == nullptr)
            return l1;
        if (l1->val < l2->val){
            l1->next = mergeTwoLists(l1->next, l2);
            return l1;
        } else {
            l2->next = mergeTwoLists(l2->next, l1);
            return l2;
        }
    }
};

int main() {
    MergeTwoLists s;
    vector<int> v1{2};
    ListNode l1(v1);
    vector<int> v2{1};
    ListNode l2(v2);
    ListNode* res = s.mergeTwoLists(&l1, &l2);
    res->print();
}
