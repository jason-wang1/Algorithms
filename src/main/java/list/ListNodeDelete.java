package list;

import structure.ListNode;

/**
 * https://leetcode-cn.com/problems/shan-chu-lian-biao-de-jie-dian-lcof/
 */
public class ListNodeDelete {
    public static void main(String[] args) {
        int[] arr = {4,5,1,9};
        ListNode listNode = new ListNode(arr);
        listNode = new ListNodeDelete().deleteNode(listNode, 4);
        listNode.print();
    }

    public ListNode deleteNode(ListNode head, int val) {
        if (head == null) return null;

        ListNode left = head;
        ListNode right = head.next;

        if (left.val == val){
            return right;
        }

        while (right != null){
            if (right.val == val){
                left.next = right.next;
                return head;
            } else {
                left = left.next;
                right = right.next;
            }
        }

        return head;
    }
}
