/*
 * @lc app=leetcode.cn id=42 lang=cpp
 *
 * [42] 接雨水
 */

// @lc code=start
class Solution {
public:
//求取每一位左右侧最大值,取最小高度减去本身的高度，就能得到该位能存的高度
int trap(vector<int>& height) {
    int n = height.size();
    if (n == 0) {
        return 0;
    }
    
    //从左边依次获取最大值并填充，得到每一位对应的左侧最大值
    vector<int> leftMax(n);
    leftMax[0] = height[0];
    for (int i = 1; i < n; ++i) {
        leftMax[i] = max(leftMax[i - 1], height[i]);
        // cout<<"LEFT  i["<<i<<":"<<leftMax[i]<<"]"<<endl;
    }
    
    //从右依次获取最大值并填充，得到每一位对应的右侧最大值
    vector<int> rightMax(n);
    rightMax[n - 1] = height[n - 1];
    for (int i = n - 2; i >= 0; --i) {
        rightMax[i] = max(rightMax[i + 1], height[i]);
        // cout<<"RIGHT i["<<i<<":"<<rightMax[i]<<"]"<<endl;
    }

    int ans = 0;
    for (int i = 0; i < n; ++i) {
        //两侧最大的取最小的减去自身高度，才能得到能存的水，不然溜出去了哈哈哈
        ans += min(leftMax[i], rightMax[i]) - height[i];

    }
    return ans;
}
};
// @lc code=end

