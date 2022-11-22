package list;

// 题目id：876
// 题目名称：链表的中间结点
import structure.ListNode;


/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode() {}
 *     ListNode(int val) { this.val = val; }
 *     ListNode(int val, ListNode next) { this.val = val; this.next = next; }
 * }
 */
class MiddleNode {
    public static void main(String[] args) {
        int[] arr = {1, 2, 3, 4, 5};
        ListNode head = new ListNode(arr);
        ListNode listNode = new MiddleNode().middleNode(head);
        listNode.print();
    }
    public ListNode middleNode(ListNode head) {
        ListNode mid = head;
        ListNode right = head;
        while (right != null && right.next != null){
            right = right.next.next;
            mid = mid.next;
        }
        return mid;
    }
}

