#include <unordered_map>
#include <iostream>
using namespace std;
/**
 * https://leetcode-cn.com/problems/fibonacci-number/
 *
 * 斐波那契数，通常用 F(n) 表示，形成的序列称为 斐波那契数列
 * 该数列由 0 和 1 开始，后面的每一项数字都是前面两项数字的和。也就是：
 * F(0) = 0，F(1) = 1
 * F(n) = F(n - 1) + F(n - 2)，其中 n > 1
 *
 * 给一个 n ，请计算 F(n)
 */
class Fibonacci {
private:
    unordered_map <int, int> map;
public:
    int fib(int n) {
        if (n == 0 | n == 1)
            return n;
        if (map.find(n) == map.end()){
            int res = fib(n-1) + fib(n-2);
            pair<int, int> kv(n, res);
            map.insert(kv);
            return res;
        } else{
            return map[n];
        }
    }
};

int main(){
    Fibonacci s;
    int res = s.fib(6);
    std::cout << res << std::endl;
}