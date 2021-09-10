#include "../structure/ListNode.h"
using namespace std;

/**
 * https://leetcode-cn.com/problems/rotate-list/
 * 给你一个链表的头节点 head ，旋转链表，将链表每个节点向右移动 k 个位置。
 *
 * 输入：head = [1,2,3,4,5], k = 2
 * 输出：[4,5,1,2,3]
 *
 * 输入：head = [0,1,2], k = 4
 * 输出：[2,0,1]
 */
class RotateList {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if (head == NULL)
            return NULL;
        ListNode* right = head;
        ListNode* left = head;
        int size = 0;
        for (int i = 0; i < k; ++i) {
            ++size;
            if (right->next == NULL){
                int moveNum = k % size;
                right = head;
                for (int j = 0; j < moveNum; ++j) {
                    right = right->next;
                }
                break;
            }
            else
                right = right->next;
        }
        while (right->next != NULL){
            left = left->next;
            right = right->next;
        }
        right->next = head;
        head = left->next;
        left->next = NULL;
        return head;
    }
};

int main() {
    RotateList s;
    vector<int> v{0,1,2};
    ListNode listNode(v);
    s.rotateRight(&listNode, 4)->print();
}