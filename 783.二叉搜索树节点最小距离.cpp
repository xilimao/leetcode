/*
 * @lc app=leetcode.cn id=783 lang=cpp
 *
 * [783] 二叉搜索树节点最小距离
 */

// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:

    int retAns = 0;

    int minDiffInBST(TreeNode* root) {
        int pre = -1;
        int retAns = INT_MAX;

        dfs(root, pre, retAns);
        return retAns;

    }

    void dfs(TreeNode* root, int& pre, int& ans)
    {
        if(!root)
        {
            return;
        }

        //遍历左子树
        dfs(root->left, pre, ans);

        //如果前序为-1，那么说明是第一个元素
        if(pre == -1)
        {
            pre = root->val;
        }
        else
        {
            //取当前答案与 当前差值的最小值
            ans = min(ans, root->val - pre);
            //赋值当前节点
            pre = root->val;
        }

        //遍历右侧数
        dfs(root->right, pre, ans);
    }

};
// @lc code=end

