/*
 * @lc app=leetcode.cn id=90 lang=cpp
 *
 * [90] 子集 II
 */

// @lc code=start
class Solution {
public:

    vector<vector<int>> res;
    vector<int> temp;

    vector<vector<int>> subsetsWithDup(vector<int>& nums) {

        //先排序-方便判断重复元素
        sort(nums.begin(),nums.end());
        //递归处理
        backtrack(nums, temp, 0);
        //返回
        return res;
    }

    void backtrack(vector<int>& nums,vector<int>&path,int start)
    {
        //加入当前传入的组合
        res.push_back(path);
        //遍历nums中的每一个元素
        for(int i=start; i<nums.size(); i++)
        {
            //如果当前的元素与前一个元素相等,则不去获取该元素下的组合(前面的已经处理过了)
            if(i>start && nums[i] == nums[i-1])//剪枝去重
            {
                continue;
            }

            //加入当前选择的元素组合到temp
            temp.push_back(nums[i]);
            //递归继续加入后面的，i+1，标识下一个选择列表的开始位置
            backtrack(nums, path, i+1);
            //结束后,依次将temp清空
            temp.pop_back();
        }
    }

};
// @lc code=end

