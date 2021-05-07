/*
 * @lc app=leetcode.cn id=35 lang=cpp
 *
 * [35] 搜索插入位置
 */

// @lc code=start
class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int left = 0;
        int right = nums.size() - 1;

        while (left <= right)
        {
            int mid = (left + right) / 2;

            if(target > nums[mid])
            {
                left = mid + 1;
            }
            else if(target < nums[mid])
            {
                right = mid - 1;
            }
            else if(target == nums[mid])
            {
                return mid;
            }
        }

        return left;    
    }
};
// @lc code=end

