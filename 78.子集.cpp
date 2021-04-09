/*
 * @lc app=leetcode.cn id=78 lang=cpp
 *
 * [78] 子集
 */

// @lc code=start
class Solution {
public:

    vector<vector<int>>res;
    vector<int> temp;

    vector<vector<int>> subsets(vector<int>& nums) {

        backtrack(nums, temp, 0);      
        return res;
    }

    //nums为题目中的给的数组
    //path为路径结果，要把每一条 path 加入结果集
    void backtrack(vector<int>nums,vector<int>&path,int start)
    {
        res.push_back(path);
        for(int i=start;i<nums.size();i++)
        {
            path.push_back(nums[i]);//做出选择
            backtrack(nums,path,i+1);//递归进入下一层，注意i+1，标识下一个选择列表的开始位置，最重要的一步
            path.pop_back();//撤销选择
        }
    }

};
// @lc code=end

