#include <stack>
#include <iostream>
using namespace std;

/**
 * https://leetcode-cn.com/problems/yong-liang-ge-zhan-shi-xian-dui-lie-lcof/
 *
 * 用两个栈实现一个队列。队列的声明如下，请实现它的两个函数 appendTail 和 deleteHead ，
 * 分别完成在队列尾部插入整数和在队列头部删除整数的功能。(若队列中没有元素，deleteHead操作返回 -1 )
 */
class CQueue {
private:
    stack<int> *stack1;
    stack<int> *stack2;

public:
    CQueue() {
        stack1 = new stack<int>;
        stack2 = new stack<int>;
    }

    void appendTail(int value) {
        while (!stack2->empty()){
            stack1->push(stack2->top());
            stack2->pop();
        }
        stack1->push(value);
    }

    int deleteHead() {
        while (!stack1->empty()){
            stack2->push(stack1->top());
            stack1->pop();
        }
        if (stack2->empty())
            return -1;
        else{
            int res = stack2->top();
            stack2->pop();
            return res;
        }
    }
};

int main() {
    CQueue c;
    c.appendTail(3);
    c.appendTail(5);
    cout << c.deleteHead() << "; ";
    c.appendTail(8);
    cout << c.deleteHead() << "; ";
    cout << c.deleteHead() << "; ";
    cout << c.deleteHead() << "; " << endl;


    return 0;
}