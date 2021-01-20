package list;

import structure.ListNode;

/**
 * https://leetcode-cn.com/problems/kth-node-from-end-of-list-lcci/
 */
public class KthNode {
    public static void main(String[] args) {
        ListNode list = new ListNode(1);
        ListNode root = list;
        for (int i = 2; i < 6; i++) {
            list.next = new ListNode(i);
            list = list.next;
        }

        System.out.println(new KthNode().kthToLast(root, 3));
    }

    public int kthToLast(ListNode head, int k) {
        ListNode right = head;
        ListNode left = head;

        for (int i = 1; i < k; i++) {
            right = right.next;
        }

        while (right.next != null){
            right = right.next;
            left = left.next;
        }

        return left.val;
    }
}
