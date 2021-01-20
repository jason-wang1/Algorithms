package backtracking;

import java.util.ArrayList;
import java.util.List;

/**
 * https://leetcode-cn.com/problems/power-set-lcci/
 */
public class PowerSet {
    public static void main(String args[]){
        int[] nums = {1,2,3,4};
        List<List<Integer>> subsets = new PowerSet().subsets(nums);
        for (List<Integer> subset : subsets) {
            System.out.println(subset);
        }
    }

    private List<List<Integer>> res;
    private List<Integer> track;

    public List<List<Integer>> subsets(int[] nums) {
        res = new ArrayList<>();
        track = new ArrayList<>();
        dfs(nums, 0, 0);
        return res;
    }

    private void dfs(int[] nums, int depth, int start) {
        if (depth > nums.length)
            return;

        res.add(new ArrayList<>(track));

        for (int i = start; i < nums.length; i++) {
            track.add(nums[i]);
            depth++;
            dfs(nums, depth, i+1);
            // 回溯
            track.remove(track.size()-1);
        }
    }
}
