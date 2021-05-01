/*
 * @lc app=leetcode.cn id=137 lang=cpp
 *
 * [137] 只出现一次的数字 II
 */

// @lc code=start
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        unordered_map<int, int> um;
        for (auto x : nums)
        {
            um[x]++;
        }

        for (auto x : um)
        {
            if (x.second == 1)
            {
                return x.first;
            }
            
        }

        return -1;
        
        
    }
};
// @lc code=end

