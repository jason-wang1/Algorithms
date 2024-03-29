package dfs;
import structure.BinaryTree;
import structure.BinaryTree.TreeNode;

/**
 * https://leetcode-cn.com/problems/er-cha-shu-de-shen-du-lcof/
 *
 * 输入一棵二叉树的根节点，求该树的深度。从根节点到叶节点依次经过的节点（含根、叶节点）形成树的一条路径，最长路径的长度为树的深度。
 * 给定二叉树 [3,9,20,null,null,15,7]，
 *     3
 *    / \
 *   9  20
 *     /  \
 *    15   7
 * 返回它的最大深度 3
 */
public class DepthOfBinaryTree {
    public static void main(String args[]){
        Integer[] arrs = {8, 5, 12, 3, 10, 11, 15};
        BinaryTree binaryTree = new BinaryTree(arrs);
        System.out.println("最大深度为："+maxDepth(binaryTree.root));
    }

    static int resDepth = 0;

    public static int maxDepth(TreeNode root) {
        search(root, 0);
        return resDepth;
    }

    /**
     * 中左右遍历（递归）
     */
    public static void search(TreeNode root, int depth){
        if (root != null){
            depth ++;
            if (depth > resDepth)
                resDepth = depth;
            System.out.println(root.val+" 入栈，深度为："+depth);
            search(root.left, depth);
            search(root.right, depth);
            System.out.println(root.val+" 出栈");
        }
    }
}