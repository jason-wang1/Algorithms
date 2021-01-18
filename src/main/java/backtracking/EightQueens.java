package backtracking;

import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;

/**
 * https://leetcode-cn.com/problems/eight-queens-lcci/
 *
 * 设计一种算法，打印 N 皇后在 N × N 棋盘上的各种摆法，其中每个皇后都不同行、不同列，也不在对角线上。
 * 这里的“对角线”指的是所有的对角线，不只是平分整个棋盘的那两条对角线。
 *
 *  输入：4
 *  输出：[[".Q..","...Q","Q...","..Q."],["..Q.","Q...","...Q",".Q.."]]
 *  解释: 4 皇后问题存在如下两个不同的解法。
 * [
 *  [".Q..",  // 解法 1
 *   "...Q",
 *   "Q...",
 *   "..Q."],
 *
 *  ["..Q.",  // 解法 2
 *   "Q...",
 *   "...Q",
 *   ".Q.."]
 * ]
 *
 */
public class EightQueens {
    public static void main(String args[]){
        List<List<String>> res = new EightQueens().solveNQueens(4);
        for (List<String> list : res) {
            for (String str : list) {
                System.out.println(str);
            }
            System.out.println("=============");
        }
    }

    private List<List<String>> res = new ArrayList<>();
    private int[] queues;
    private boolean[] col;
    private boolean[] diag1;
    private boolean[] diag2;


    public List<List<String>> solveNQueens(int n) {
        col = new boolean[n];
        diag1 = new boolean[n+n];
        diag2 = new boolean[n+n];
        queues = new int[n];
        dfs(n, 0);
        return res;
    }

    private void dfs(int n, int rowNum) {
        if (rowNum == n) {
            generateBoard(queues, n);
            return;
        }
        for (int j = 0; j < n; j++) {
            if (!col[j] && !diag1[rowNum-j+n] && !diag2[rowNum+j]){
                queues[rowNum] = j;
                col[j] = true;
                diag1[rowNum-j+n] = true;
                diag2[rowNum+j] = true;
                dfs(n, rowNum+1);

                // 回溯
                col[j] = false;
                diag1[rowNum-j+n] = false;
                diag2[rowNum+j] = false;
            }
        }
    }

    private void generateBoard(int[] queues, int n) {
        List<String> track = new ArrayList<>();

        for (int i = 0; i < n; i++) {
            char[] row = new char[n];
            Arrays.fill(row, '.');
            row[queues[i]] = 'Q';
            track.add(new String(row));
        }

        res.add(track);
    }
}
