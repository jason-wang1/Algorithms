package hashmap;

import java.util.HashMap;

/**
 * https://leetcode-cn.com/problems/number-of-good-pairs/
 */
public class GoodPairs {
    public static void main(String args[]){
        int[] nums = {1,1,1,1};
        int pairs = new GoodPairs().numIdenticalPairs(nums);
        System.out.println(pairs);
    }

    private HashMap<Integer, Integer> dupNums;

    public int numIdenticalPairs(int[] nums) {
        dupNums = new HashMap<>(nums.length);
        for (int num : nums) {
            dupNums.put(num, dupNums.getOrDefault(num, 0) + 1);
        }

        int res = 0;
        for (Integer dupNum : dupNums.values()) {
            res += goodNum(dupNum);
        }
        return res;
    }

    private int goodNum(Integer dupNum) {
        if (dupNum < 2)
            return 0;
        if (dupNum == 2)
            return 1;
        return goodNum(dupNum-1) + (dupNum - 1);
    }
}
