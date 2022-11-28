package priorityqueue;

import java.util.PriorityQueue;
import java.util.Vector;

public class FindKthLargest {

    //  使用堆排序
    // 	执行耗时:57 ms,击败了18.30% 的Java用户
    //	内存消耗:51.5 MB,击败了7.58% 的Java用户
    public int findKthLargest(int[] nums, int k) {
        PriorityQueue<Integer> q = new PriorityQueue<>(k, (o1, o2) -> o2 - o1); //大顶堆;
        for (int i = 0; i < nums.length; i++) {
            q.add(nums[i]);
        }
        for (int i = 1; i < k; i++) {
            q.poll();
        }
        return q.peek();
    }

    public static void main(String[] args) {
        Vector<Integer> v = new Vector<>(3); //初始化
        v.add(3);
        v.add(5);
        v.add(7);
        v.add(2);
        v.add(9);
        v.add(1, 8);
        for (int i = 0; i < v.size(); i++) {
            System.out.println(v.get(i));
        }
    }
}
