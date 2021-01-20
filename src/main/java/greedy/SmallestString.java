package greedy;

/**
 * https://leetcode-cn.com/problems/smallest-string-with-a-given-numeric-value/
 */
public class SmallestString {
    public static void main(String args[]){
        System.out.println(new SmallestString().getSmallestString(5, 73));
    }

    public String getSmallestString(int n, int k) {
        char[] res = new char[n];
        for (int i = n-1; i >= 0; i--) {
            char s;
            if ((k-i) <= 26){
                s = (char) (96+k-i);
                k -= (k-i);
            } else {
                s = 'z';
                k -= 26;
            }
            res[i] = s;
        }

        return String.valueOf(res);
    }
}
