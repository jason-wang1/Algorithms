package list;

import structure.ListNode;

/**
 * https://leetcode-cn.com/problems/rotate-list/)
 */
public class RotateList {
    public static void main(String args[]){
        ListNode first = new ListNode(1);
        ListNode listNode = first;
        for (int i = 2; i < 6; i++) {
            listNode.next = new ListNode(i);
            listNode = listNode.next;
        }

        ListNode result = new RotateList().rotateRight(first, 2);
        while (result != null){
            System.out.println(result.val);
            result = result.next;
        }
    }

    public ListNode rotateRight(ListNode head, int k) {
        if (head == null)
            return null;

        int len = 1;
        ListNode point = head;
        while (point.next != null){
            point = point.next;
            len ++;
        }

        point.next = head;

        int moveNum = len - k % len - 1;
        for (int i = 0; i < moveNum; i++) {
            head = head.next;
        }

        ListNode tail = head;
        head = head.next;
        tail.next = null;
        return head;
    }

    public ListNode rotateRight1(ListNode head, int k) {
        if (head == null)
            return null;

        ListNode right = head;
        ListNode left = head;

        for (int i = 0; i < k; i++) {
            if (right.next != null)
                right = right.next;
            else
                right = head;
        }

        while (right.next != null){
            right = right.next;
            left = left.next;
        }

        right.next = head;
        head = left.next;
        left.next = null;

        return head;
    }
}
