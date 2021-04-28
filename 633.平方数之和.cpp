/*
 * @lc app=leetcode.cn id=633 lang=cpp
 *
 * [633] 平方数之和
 */

// @lc code=start
class Solution {
public:

    //遍历法
    // bool judgeSquareSum(int c) {
    //     for (long a = 0; a * a <= c; a++)
    //     {
    //         double b = sqrt(c - a*a);
    //         //(int) b 是把这个 double 类型转成了 int 型.在强制转换的过程中，会丢失 double 类型的小数部分。所以这一步强制转换相当于向下取整。
    //         //那么 b == (int) b 是把一个 double 和一个 int 进行比较。这一步会把 int 先转成 double，然后两个 double 类型的数字进行比较。
    //         if (b == (int)b)
    //         {
    //             return true;
    //         }
    //     }

    //     return false;   
    // }

    //双指针
    bool judgeSquareSum(int c) {
        long left = 0;
        long right = (int)sqrt(c);

        while (left <= right)
        {
            // cout<<"left = "<<left<<" right = "<<right<<endl;
            long sum = left*left + right*right;
            // cout<<"sum = "<<sum<<endl;
            if (sum == c)
            {
                return true;
            }
            else if(sum > c)
            {
                right --;
            }
            else
            {
                left ++;
            }
        }
        return false;  
    }

};
// @lc code=end

