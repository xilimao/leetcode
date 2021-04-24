/*
 * @lc app=leetcode.cn id=377 lang=cpp
 *
 * [377] 组合总和 Ⅳ
 */

// @lc code=start
class Solution {
public:
    int combinationSum4(vector<int>& nums, int target) {
        vector<unsigned long long> f(target + 1,0); //不用做取模的操作了
        f[0] = 1;
        for(int i = 1; i <= target; i++){
            for(auto x : nums){
                //c++计算的中间结果会溢出，但因为最终结果是int
                //因此每次计算完都对INT_MAX取模，0LL是将计算结果提升到long long类型
                if(i >= x) f[i] =(0LL + f[i] + f[i - x]) % INT_MAX;
            }
        }
        return f[target];
    }
};

// @lc code=end

