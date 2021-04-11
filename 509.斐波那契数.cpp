/*
 * @lc app=leetcode.cn id=509 lang=cpp
 *
 * [509] 斐波那契数
 *
 * https://leetcode-cn.com/problems/fibonacci-number/description/
 *
 * algorithms
 * Easy (68.22%)
 * Likes:    261
 * Dislikes: 0
 * Total Accepted:    158.9K
 * Total Submissions: 232.9K
 * Testcase Example:  '2'
 *
 * 斐波那契数，通常用 F(n) 表示，形成的序列称为 斐波那契数列 。该数列由 0 和 1 开始，后面的每一项数字都是前面两项数字的和。也就是：
 * 
 * 
 * F(0) = 0，F(1) = 1
 * F(n) = F(n - 1) + F(n - 2)，其中 n > 1
 * 
 * 
 * 给你 n ，请计算 F(n) 。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 输入：2
 * 输出：1
 * 解释：F(2) = F(1) + F(0) = 1 + 0 = 1
 * 
 * 
 * 示例 2：
 * 
 * 
 * 输入：3
 * 输出：2
 * 解释：F(3) = F(2) + F(1) = 1 + 1 = 2
 * 
 * 
 * 示例 3：
 * 
 * 
 * 输入：4
 * 输出：3
 * 解释：F(4) = F(3) + F(2) = 2 + 1 = 3
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 0 
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    // int fib(int n) {

    //     if(n < 0)
    //     {
    //         return 0;
    //     }
    //     vector<int> hh(n + 1, 0);
    //     return ac(hh, n);
    // }

    // int ac(vector<int> &memo, int n)
    // {
    //     if(n == 1 || n == 2)
    //     {
    //         return 1;
    //     }

    //     if(memo[n] != 0)
    //     {
    //         return memo[n];
    //     }

    //     memo[n] = ac(memo, n-1) + ac(memo, n-2);
    //     return memo[n];
    // }

    //自底向上
    // int fib(int n) 
    // {
    //     vector<int> dp(n + 1, 0);

    //     dp[1] = dp[2] = 1;
    //     for (int i = 3; i <= n; i++)
    //     {
    //         dp[i] = dp[i - 1] + dp[i - 2];
    //     }
    //     return dp[n];
    // }

    //
    int fib(int n) {
    if (n == 2 || n == 1) 
        return 1;
    int prev = 1, curr = 1;
    for (int i = 3; i <= n; i++) 
    {
        int sum = prev + curr;
        prev = curr;
        curr = sum;
    }
    return curr;
}

};
// @lc code=end

