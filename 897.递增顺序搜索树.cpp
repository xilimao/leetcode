/*
 * @lc app=leetcode.cn id=897 lang=cpp
 *
 * [897] 递增顺序搜索树
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

    vector<int> valueList;

    void inorder(TreeNode* root)
    {
        if(root == nullptr)
        {
            return;
        }

        inorder(root->left);
        valueList.push_back(root->val);
        inorder(root->right);
    }

    TreeNode* increasingBST(TreeNode* root) 
    {
        inorder(root);

        TreeNode* dummyNode = new TreeNode(-1);
        TreeNode* currNode  = dummyNode;
        for (int value : valueList)
        {
            currNode->right = new TreeNode(value);
            currNode = currNode->right;
        }

        return dummyNode->right;
    }
};
// @lc code=end

