/*
 * @lc app=leetcode.cn id=213 lang=cpp
 *
 * [213] 打家劫舍 II
 */

// @lc code=start
class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if (n == 0) return 0;
        if (n == 1) return nums[0];
        int f[110][2];
        memset(f, 0, sizeof f);

        // 第一间「必然不选」的情况
        for (int i = 1; i < n - 1; i++) {
            f[i][0] = max(f[i - 1][0], f[i - 1][1]);
            f[i][1] = f[i - 1][0] + nums[i];
        }
        int a = max(f[n - 2][1], f[n - 2][0] + nums[n - 1]);
        
        // 第一间「允许选」的情况
        f[0][0] = 0; f[0][1] = nums[0];
        for (int i = 1; i < n - 1; i++) {
            f[i][0] = max(f[i - 1][0], f[i - 1][1]);
            f[i][1] = f[i - 1][0] + nums[i];
        }
        int b = max(f[n - 2][0], f[n - 2][1]);
        
        return max(a, b);
    }
};




// @lc code=end

