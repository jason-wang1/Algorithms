package binarysearch;

public class RotatedSortedArray {
    public static void main(String args[]){
        int[] nums = {4,5,6,7,8,1,2,3};
        int res = new RotatedSortedArray().search(nums, 8);
        System.out.println(res);
    }

    public int search(int[] nums, int target) {
        int left = 0;
        int right = nums.length-1;
        int mid;

        while (left <= right){
            mid = left + (right-left)/2;
            if (target == nums[mid]){
                return mid;
            } else if (target == nums[left]){
                return left;
            } else if (target == nums[right]){
                return right;
            } else if (nums[mid] < nums[right]){
                if (target > nums[mid] && target < nums[right]){
                    left = mid+1;
                } else {
                    right = mid-1;
                }
            } else {
                if (target > nums[left] && target < nums[mid]){
                    right = mid-1;
                } else {
                    left = mid+1;
                }
            }
        }
        return -1;
    }
}
