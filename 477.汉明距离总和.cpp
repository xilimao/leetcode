/*
 * @lc app=leetcode.cn id=477 lang=cpp
 *
 * [477] 汉明距离总和
 */

// @lc code=start
class Solution {
public:
    // 在计算汉明距离时，我们考虑的是同一比特位上的值是否不同，而不同比特位之间是互不影响的。

    // 对于数组 nums 中的某个元素 val，若其二进制的第 i 位为 1，我们只需统计 nums 中有多少元素的第 i 位为 0，
    // 即计算出了 val 与其他元素在第 i 位上的汉明距离之和。

    // 具体地，若长度为 n 的数组 nums 的所有元素二进制的第 i 位共有 c 个 1，n−c 个 0，
    // 则些元素在二进制的第 i 位上的汉明距离之和为 c⋅(n−c)

    int totalHammingDistance(vector<int>& nums) {
        int ans = 0;
        int n = nums.size();

        //遍历每一位上 1的个数 0的个数 因为数据大小要求10^9 < 2^30 所以循环30次
        for (int i = 0; i < 30; i++)
        {
            int c = 0;
            for (int val :nums)
            {   
                //计算该 val 在第i位 中1的个数 因为 0&1=0 1&1=1
                c += (val >> i)&1;
            }
            //计算第i位 汉明距离总和 并累加
            ans += c * (n - c);
            
        }

        return ans;
        
    }
};
// @lc code=end

