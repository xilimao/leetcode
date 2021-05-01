/*
 * @lc app=leetcode.cn id=80 lang=cpp
 *
 * [80] 删除有序数组中的重复项 II
 */

// @lc code=start
class Solution {
public:
    int work(vector<int>& nums, int k) 
    {
        int len = 0;
        for(auto num : nums)
        {
            if(len < k || nums[len-k] != num)
            {
                nums[len++] = num;
            }
        }
        return len;
    }
    int removeDuplicates(vector<int>& nums) {
        return work(nums, 2);
    }
};
// @lc code=end

