/*
 * @lc app=leetcode.cn id=198 lang=cpp
 *
 * [198] 打家劫舍
 */

// @lc code=start
class Solution {
public:
    int rob(vector<int>& nums) {
        //dp[0] = nums[0];
        //dp[1] = max(nums[0], nums[1]);
        //dp[i] = max(nums[i - 2] + nums[i], nums[i - 1]);

        if(nums.empty())
        {
            return 0;
        }

        int size = nums.size();
        if(size == 1)
        {
            return nums[0];
        }

        // vector<int> dp = vector<int> (size, 0);
        // //边界
        // dp[0] = nums[0];
        // dp[1] = max(nums[0], nums[1]);
        // for (int i = 2; i < size; i++)
        // {
        //     dp[i] = max(nums[i - 2] + nums[i], dp[i - 1]);
        // }
        // return dp[size - 1];

        int first = nums[0];
        int second = max(first, nums[1]);
        for (int i = 2; i < size; i++)
        {
            int temp = second;
            second = max(first + nums[i], second);
            first = temp;
        }

        return second;
        
    }
};
// @lc code=end

