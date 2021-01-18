package recursive;

import java.util.ArrayList;
import java.util.List;

/**
 * 给定一个非负整数 numRows，生成杨辉三角的前 numRows 行。
 *
 * 示例：
 * 输入: 5
 * 输出:
 * [
 *      [1],
 *     [1,1],
 *    [1,2,1],
 *   [1,3,3,1],
 *  [1,4,6,4,1]
 * ]
 */
public class PascalTriangle {
    public static void main(String args[]){
        List<List<Integer>> triangle = generate(5);
        for (List<Integer> line : triangle) {
            System.out.println(line);
        }
    }

    public static List<List<Integer>> generate(int numRows) {
        List<List<Integer>> res = new ArrayList<List<Integer>>(numRows);
        for (int i = 0; i < numRows; i++) {
            List<Integer> list = new ArrayList<Integer>(i + 1);
            for (int j = 0; j <= i; j++) {
                Integer val = calc(i, j);
                list.add(val);
            }
            res.add(list);
        }
        return res;
    }

    /**
     * 递归计算帕斯卡三角的第(i, j)个数值，如同计算斐波拉契数列第n个值一样，这里会涉及到重复计算
     */
    private static Integer calc(int i, int j) {
        if (j == 0 || i == j)
            return 1;
        return calc(i-1, j-1) + calc(i-1, j);
    }
}
