/*
 * @lc app=leetcode.cn id=740 lang=cpp
 *
 * [740] 删除与获得点数
 */

// @lc code=start
class Solution {
private:
  int rob(vector<int>& nums) {
        if(nums.empty())
        {
            return 0;
        }

        int size = nums.size();
        if(size == 1)
        {
            return nums[0];
        }

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

public:
    int deleteAndEarn(vector<int>& nums) {
        //获取最大值
        int maxVal = 0;
        for (int val : nums) {
            maxVal = max(maxVal, val);
        }
        //创建最大值长度的vector,并记录其每个值的总和
        vector<int> sum(maxVal + 1);
        for (int val : nums) {
            sum[val] += val;
        }
        return rob(sum);
    }
};
// @lc code=end

