package bfs;

import structure.BinaryTree;
import structure.BinaryTree.TreeNode;

import java.util.ArrayList;
import java.util.List;

/**
 * https://leetcode-cn.com/problems/cong-shang-dao-xia-da-yin-er-cha-shu-lcof/
 */
public class LevelTraversalTree {
    public static void main(String[] args) {
        Integer[] arr = {3,9,20,null,null,15,7};
        BinaryTree binaryTree = new BinaryTree(arr);
        int[] ints = new LevelTraversalTree().levelOrder(binaryTree.root);
        for (int i : ints) {
            System.out.println(i);
        }
    }

    ArrayList<List<Integer>> lists = null;
    boolean isNew = false;

    public int[] levelOrder(TreeNode root) {
        lists = new ArrayList<>();
        dfs(root, 0);
        ArrayList<Integer> resList = new ArrayList<>();
        for (List<Integer> list : lists) {
            resList.addAll(list);
        }

        int[] res = new int[resList.size()];
        for (int i = 0; i < resList.size(); i++) {
            res[i] = resList.get(i);
        }
        return res;
    }

    private void dfs(TreeNode node, int depth) {
        if (node != null){
            List<Integer> levelVals;
            if (lists.size() <= depth){
                levelVals = new ArrayList<>();
                isNew = true;
            }
            else {
                isNew = false;
                levelVals = lists.get(depth);
            }

            levelVals.add(node.val);
            if (isNew)
                lists.add(levelVals);

            dfs(node.left, depth+1);
            dfs(node.right, depth+1);
        }
    }
}
