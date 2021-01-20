package dfs;

import structure.Node;

/**
 * https://leetcode-cn.com/problems/er-cha-sou-suo-shu-yu-shuang-xiang-lian-biao-lcof/
 */
public class BinaryTreeAndLinkedList {
    public static void main(String args[]){

    }

    private Node head;
    private Node pre;

    public Node treeToDoublyList(Node root) {
        if(root == null) return null;
        dfs(root);
        head.left = pre;
        pre.right = head;
        return head;
    }

    private void dfs(Node node) {
        if (node != null){
            dfs(node.left);
            if (pre != null) pre.right = node;
            else head = node;
            node.left = pre;
            pre = node;
            dfs(node.right);
        }
    }
}
