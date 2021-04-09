/*
 * @lc app=leetcode.cn id=153 lang=cpp
 *
 * [153] 寻找旋转排序数组中的最小值
 */

// @lc code=start
class Solution {
public:
    int findMin(vector<int>& nums) {
        
        //取最左、右索引
        int left = 0;        
        int right = nums.size() - 1;

        while (left < right)
        {
            //取中间索引-防止数据一处
            int mid = left + (right - left) / 2;
            if(nums[mid] < nums[right])
            {
                //如果中间值小于最右侧值,说明最小值在左侧。
                right = mid;
            }
            else
            {
                //如果中间值小于最左侧值,说明最小值在右侧
                //此处最左侧往右移一位(已最左侧索引做返回)
                left = mid + 1;
            }
        }

        return nums[left];
    }
};
// @lc code=end

