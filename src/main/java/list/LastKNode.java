package list;

import structure.ListNode;

/**
 * https://leetcode-cn.com/problems/lian-biao-zhong-dao-shu-di-kge-jie-dian-lcof/
 */
public class LastKNode {
    public static void main(String[] args) {
        int[] arr = {1, 2, 3, 4, 5};
        ListNode head = new ListNode(arr);
        ListNode listNode = new LastKNode().getKthFromEnd(head, 2);
        listNode.print();
    }

    public ListNode getKthFromEnd(ListNode head, int k) {
        ListNode right = head;
        ListNode left = head;
        for (int i = 0; i < k; i++) {
            right = right.next;
        }

        while (right != null){
            right = right.next;
            left = left.next;
        }

        return left;
    }
}
