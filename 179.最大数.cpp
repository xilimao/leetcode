/*
 * @lc app=leetcode.cn id=179 lang=cpp
 *
 * [179] 最大数
 */

// @lc code=start
class Solution {
public:
    string largestNumber(vector<int>& nums) {

        //将nums 进行lambda 匿名函数 排序
        //将数字转为字符串，比较两个数分别在前相加的大小,大的放在前面
        sort(nums.begin(), nums.end(), [](int x, int y){
            string a = to_string(x);
            string b = to_string(y);
            
            return a + b > b + a;
        });

        string retAns = "";
        for (int i : nums)
        {
            retAns += to_string(i);
        }

        //条件操作符 (条件) ? 条件为真返回的值 : 条件为假返回的值
        return (retAns[0] == '0') ? "0" : retAns;
    }
};
// @lc code=end

