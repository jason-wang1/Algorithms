package stack;

import java.util.Stack;

/**
 * https://leetcode-cn.com/problems/yong-liang-ge-zhan-shi-xian-dui-lie-lcof/
 *
 * 用两个栈实现一个队列。队列的声明如下，请实现它的两个函数 appendTail 和 deleteHead ，
 * 分别完成在队列尾部插入整数和在队列头部删除整数的功能。(若队列中没有元素，deleteHead 操作返回 -1 )
 */
public class QueueWithStack {
    public static void main(String args[]){
        CQueue obj = new CQueue();
        obj.appendTail(3);
        obj.appendTail(5);
        int param_2 = obj.deleteHead();
        System.out.println(param_2);
        obj.appendTail(7);
        param_2 = obj.deleteHead();
        System.out.println(param_2);
    }

    static class CQueue {
        Stack<Integer> stack1 = null;
        Stack<Integer> stack2 = null;

        public CQueue() {
            stack1 = new Stack<Integer>();
            stack2 = new Stack<Integer>();
        }

        public void appendTail(int value) {
            stack1.push(value);
        }

        public int deleteHead() {
            if (stack2.empty()){
                while (!stack1.empty()){
                    stack2.push(stack1.pop());
                }
            }
            try {
                return stack2.pop();
            } catch (Exception e) {
                return -1;
            }
        }
    }
}
