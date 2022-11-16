package binarysearch;

import java.util.Arrays;

/**
 * https://leetcode.cn/problems/how-many-numbers-are-smaller-than-the-current-number/
 *
 * 给你一个数组nums，对于其中每个元素nums[i]，请你统计数组中比它小的所有数字的数目。
 * 换而言之，对于每个nums[i]你必须计算出有效的j的数量，其中 j 满足j != i 且 nums[j] < nums[i]。
 * 以数组形式返回答案。
 *
 * 示例：
 * 输入：nums = [8,1,2,2,3]
 * 输出：[4,0,1,1,3]
 * 解释：
 * 对于 nums[0]=8 存在四个比它小的数字：（1，2，2 和 3）。
 * 对于 nums[1]=1 不存在比它小的数字。
 * 对于 nums[2]=2 存在一个比它小的数字：（1）。
 * 对于 nums[3]=2 存在一个比它小的数字：（1）。
 * 对于 nums[4]=3 存在三个比它小的数字：（1，2 和 2）。
 *
 */
public class SmallerNum {
    public static void main(String[] args) {
        int[] nums = {8,1,2,2,3};
        int[] ints = new SmallerNum().smallerNumbersThanCurrent(nums);
        for (int smallerNum : ints) {
            System.out.println(smallerNum);
        }
    }

    public int[] smallerNumbersThanCurrent(int[] nums) {
        int[] numSorted = Arrays.copyOf(nums, nums.length);
        Arrays.sort(numSorted);
        int[] res = new int[nums.length];
        for (int i = 0; i < nums.length; i++) {
            int smallNum = binarySearch(nums[i], numSorted);
            res[i] = smallNum;
        }

        return res;
    }

    private int binarySearch(int target, int[] numSorted) {
        int left = 0;
        int right = numSorted.length - 1;
        int mid = left + (right-left)/2;

        while (left <= right){
            mid = left + (right-left)/2;
            if (numSorted[mid] > target){
                right = mid-1;
            } else if (numSorted[mid] < target){
                left = mid+1;
            } else {
                if (numSorted[left] == target){
                    mid = left;
                    break;
                } else {
                    right = mid;
                }
            }
        }

        while (mid > 0 && numSorted[mid-1] == numSorted[mid])
            mid--;

        return mid;
    }
}
