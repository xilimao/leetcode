/*
 * @lc app=leetcode.cn id=1006 lang=cpp
 *
 * [1006] 笨阶乘
 */

// @lc code=start
class Solution {
public:

    //愚人节快乐！！
     int clumsy(int N) {
        if (N == 1) {
            return 1;
        } else if (N == 2) {
            return 2;
        } else if (N == 3) {
            return 6;
        } else if (N == 4) {
            return 7;
        }

        if (N % 4 == 0) {
            return N + 1;
        } else if (N % 4 <= 2) {
            return N + 2;
        } else {
            return N - 1;
        }
    }

    //我是笨蛋
    // int clumsy(int N) {

    //     //通过栈来进行运算符处理
    //     stack<int> stk;
    //     //加入首数字
    //     stk.push(N);
    //     //得到下一个数字
    //     N--;

    //     int index = 0;
    //     while (N > 0)
    //     {
    //         //*/+-,共四个运算符,通过取余判断当前要进行的运算
    //         //乘除直接算,+-要入栈
    //         int cur = index % 4;
    //         switch (cur)
    //         {
    //         case 0:
    //             stk.top() *= N;
    //             break;
    //         case 1:
    //             stk.top() /= N;
    //             break;
    //         case 2:
    //             stk.push(N);
    //             break;
    //         default:
    //             stk.push(-N);
    //             break;
    //         }
    //         index ++;
    //         N--;
    //     }
        
    //     //遍历栈加和运算
    //     int retSum = 0;
    //     while (!stk.empty())
    //     {
    //         retSum += stk.top();
    //         stk.pop();
    //     }
        
    //     return retSum;
    // }
};
// @lc code=end

