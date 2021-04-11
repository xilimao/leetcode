/*
 * @lc app=leetcode.cn id=264 lang=cpp
 *
 * [264] 丑数 II
 *
 * https://leetcode-cn.com/problems/ugly-number-ii/description/
 *
 * algorithms
 * Medium (56.34%)
 * Likes:    594
 * Dislikes: 0
 * Total Accepted:    67.7K
 * Total Submissions: 120.2K
 * Testcase Example:  '10'
 *
 * 给你一个整数 n ，请你找出并返回第 n 个 丑数 。
 * 
 * 丑数 就是只包含质因数 2、3 和/或 5 的正整数。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 输入：n = 10
 * 输出：12
 * 解释：[1, 2, 3, 4, 5, 6, 8, 9, 10, 12] 是由前 10 个丑数组成的序列。
 * 
 * 
 * 示例 2：
 * 
 * 
 * 输入：n = 1
 * 输出：1
 * 解释：1 通常被视为丑数。
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 1 
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    int nthUglyNumber(int n) {
        vector<int> vUgly;
        for(long long i = 1; i < INT_MAX; i *= 2)
        {
            for(long long j = i; j < INT_MAX; j *= 3)
            {
                for(long long k = j; k < INT_MAX; k *= 5)
                {
                    vUgly.push_back(k);
                }
            }
        }

        sort(vUgly.begin(), vUgly.end());

        return vUgly[n - 1];
    }
};
// @lc code=end

