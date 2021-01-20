package array;

/**
 * https://leetcode-cn.com/problems/er-wei-shu-zu-zhong-de-cha-zhao-lcof/
 */
public class MatrixSearch {
    public static void main(String args[]){
        int[][] matrix = {  {1,   4,  7, 11, 15},
                {2,   5,  8, 12, 19},
                {3,   6,  9, 16, 22},
                {10, 13, 14, 17, 24},
                {18, 21, 23, 26, 30}};
        int[][] matrix2 = {{}};

        System.out.println(new MatrixSearch().findNumberIn2DArray(matrix2, 5));
    }
    public boolean findNumberIn2DArray(int[][] matrix, int target) {
        if (matrix.length == 0 || matrix[0].length == 0)
            return false;

        int i = 0;
        int j = matrix[0].length - 1;
        while (i < matrix.length && j >= 0){
            if (matrix[i][j] > target){
                j--;
            } else if (matrix[i][j] < target){
                i++;
            } else {
                return true;
            }
        }
        return false;
    }
}
