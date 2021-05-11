/*
 * @lc app=leetcode.cn id=1734 lang=cpp
 *
 * [1734] 解码异或后的排列
 */

// @lc code=start
class Solution {
public:

// 为了表达的方便，可以这么定义：将A XOR B（A和B进行异或运算）简写为AB。
// 思路步骤：
// 既然我们知道了perm = [A, B, C, D, E]，那么encoded = [AB, BC, CD, DE]；
// 根据perm，我们可以得到ABCDE,根据encoded的BC和DE，我们可以得到BCDE；
// 将ABCDE和BCDE进行异或运算，得到A，即perm的第一个元素。这时候，今天的题目转换成上面的第一题。
//整数数组 perm,它是前 n 个正整数的排列，说明 perm=[1,2,3,4,5,6,7,8,9,n] 进行了随机排列

    vector<int> decode(vector<int>& encoded) {
        //编码后的长度
        int n = encoded.size();
        //初始化编码前的数组
        vector<int> perm(n + 1);
        //初始化 perm 中所有数值的异或值
        int ABCDE = 0;
        for (int i = 1; i <= n+1; i++)
        {
            ABCDE ^= i;
        }
        
        //为了得到perm的第一个数值，需要初始化一个“BCDE” 
        int BCDE = 0;
        for (int i = 1; i < n; i += 2)
        {
            // “BCDE”的求值，就是encoded中从1开始，步长为2地取值进行异或的结果 
            BCDE ^= encoded[i];
        }

        //初始数组的第一个值  ABCDE ^ BCDE = A
        perm[0] = ABCDE ^ BCDE;

        //模拟法求出
        for (int i = 1; i < n + 1; i++)
        {
            //encpded[0] = perm[0] ^ perm[1]
            //encode[i-1] = perm[i-1] ^ perm[i]
            //so perm[i] = perm[i - 1] ^ encoded[i - 1]
            perm[i] = perm[i - 1] ^ encoded[i - 1];
        }
        
        return perm;
    }
};
// @lc code=end

