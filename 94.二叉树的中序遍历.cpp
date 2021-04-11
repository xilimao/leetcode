/*
 * @lc app=leetcode.cn id=94 lang=cpp
 *
 * [94] 二叉树的中序遍历
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

    //递归
    // vector<int> vRet;

    // vector<int> inorderTraversal(TreeNode* root) {
    //     if(!root)
    //     {
    //         return vRet;
    //     }

    //     inorderTraversal(root->left);
    //     中序
    //     vRet.push_back(root->val);
    //     inorderTraversal(root->right);        

    //     return vRet;
    // }

    vector<int> inorderTraversal(TreeNode* root) {

        //定义要返回的vector以及栈
        vector<int> vRet;
        stack<TreeNode*> sNode;

        //当节点不为空或者栈不为空的时候循环进行
        while (root != nullptr || !sNode.empty())
        {
            //当节点不为空时
            while (root != nullptr)
            {
                //把当前节点加入栈中
                sNode.push(root);
                //遍历左节点直到做节点为null
                root = root->left;
            }

            //将当前节点至为栈顶的节点
            root = sNode.top();
            //pop掉栈顶节点
            sNode.pop();
            //将栈顶节点数值加入容器
            vRet.push_back(root->val);
            //开始遍历右节点
            root = root->right;
        }
        
        return vRet;
    }

};
// @lc code=end

