package backtracking;

import java.util.ArrayList;
import java.util.LinkedList;
import java.util.List;

/**
 * https://leetcode-cn.com/problems/palindrome-partitioning/
 */
public class PalindromePartition {
    public static void main(String[] args) {
        String str = "aabac";
        List<List<String>> partition = new PalindromePartition().partition(str);
        for (List<String> strings : partition) {
            System.out.println(strings);
        }
    }

    List<List<String>> res;
    LinkedList<String> list;

    public List<List<String>> partition(String s) {
        res = new LinkedList<>();
        list = new LinkedList<>();
        bt(s);
        return res;
    }

    private void bt(String s) {
        if (s.length() == 0){
            res.add(new ArrayList<>(list));
            return;
        }

        for (int i = 0; i < s.length(); i++) {
            String subStr = s.substring(0, i+1);
            if (!isPalindrome(subStr))
                continue;

            list.addLast(subStr);
            bt(s.substring(i+1));
            list.removeLast();
        }
    }

    private boolean isPalindrome(String s){
        for (int i = 0; i < s.length()/2; i++) {
            if (s.charAt(i) != s.charAt(s.length()-1-i))
                return false;
        }
        return true;
    }
}
