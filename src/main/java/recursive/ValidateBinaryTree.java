package recursive;

import structure.BinaryTree;
import structure.BinaryTree.TreeNode;

/**
 * https://leetcode-cn.com/problems/validate-binary-search-tree/
 */
public class ValidateBinaryTree {
    public static void main(String[] args) {
        Integer[] arr = {5,4,6,null,null,3,7};
        BinaryTree binaryTree = new BinaryTree(arr);
        boolean validBST = new ValidateBinaryTree().isValidBST(binaryTree.root);
        System.out.println(validBST);
    }

    public boolean isValidBST(TreeNode root) {
        return helper(root, null, null);
    }

    private boolean helper(TreeNode node, Integer lower, Integer upper){
        if (node == null) return true;

        int val = node.val;

        if (lower != null && val >= lower)
            return false;

        if (upper != null && val <= upper)
            return false;

        return helper(node.left, val, upper) && helper(node.right, lower, val);
    }
}
