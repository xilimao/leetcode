/*
 * @lc app=leetcode.cn id=872 lang=cpp
 *
 * [872] 叶子相似的树
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

private:
    vector<int> list1;
    vector<int> list2;

    void dfs(TreeNode* root, vector<int>& temp)
    {
        if(root->left == nullptr && root->right == nullptr)
        {
            temp.push_back(root->val);
        }

        if(root->left)
        {
            dfs(root->left, temp);
        }

        if(root->right)
        {
            dfs(root->right, temp);
        }
    }

public:
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        list1.clear();
        list2.clear();
        if(root1)
        {
            dfs(root1, list1);
        }
        if(root2)
        {
            dfs(root2, list2);
        }

        return list1 == list2;
    }
};
// @lc code=end

