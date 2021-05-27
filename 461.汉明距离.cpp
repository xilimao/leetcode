/*
 * @lc app=leetcode.cn id=461 lang=cpp
 *
 * [461] 汉明距离
 */

// @lc code=start
class Solution {
public:
    //
    int hammingDistance(int x, int y) {
        //0⊕0=0
        //0⊕1=1
        //1⊕0=1
        //1⊕1=0
        //所以结合题意,异或后求出1的个数即为答案

        //使用内置函数计算二进制表达中1的数量的函数
        return __builtin_popcount(x ^ y);

        //不断移位+添加&值(因为0&1=0 1&1=1,所以一直加就能取到1的个数)
        // int s = x ^ y, ret = 0;
        // while (s) {
        //     ret += s & 1;
        //     s >>= 1;
        // }
        // return ret;

        //Brian Kernighan 算法
        //记 f(x)f(x) 表示 xx 和 x-1x−1 进行与运算所得的结果（即 f(x)=x~\&~(x-1)f(x)=x & (x−1)），那么 f(x)f(x) 恰为 xx 删去其二进制表示中最右侧的 11 的结果。
        //基于该算法，当我们计算出 s = x \oplus ys=x⊕y，只需要不断让 s = f(s)s=f(s)，直到 s=0s=0 即可。这样每循环一次，ss 都会删去其二进制表示中最右侧的 11，最终循环的次数即为 ss 的二进制表示中 11 的数量。
        // int s = x ^ y, ret = 0;
        // while (s) {
        //     s &= s - 1;
        //     ret++;
        // }
        // return ret;
    }
};
// @lc code=end

