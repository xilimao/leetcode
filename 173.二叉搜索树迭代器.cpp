// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include "commoncppproblem173.h"

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode.cn id=173 lang=cpp
 *
 * [173] 二叉搜索树迭代器
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
class BSTIterator {
public:
    int i;
    vector<int> m_val;

    BSTIterator(TreeNode* root) 
    {
        i = 0;
        makeBST(root);
    }

    //从头一次获取下一个值
    int next() {
        return m_val[i++];
    }
    //判断下一个值是否存在
    bool hasNext() 
    {
        return i < m_val.size();
    }

    //创建一个中序排列二叉树
    void makeBST(TreeNode* root)
    {
        TreeNode* cur = root;
        stack<TreeNode*> tsTree;
        while (cur != nullptr || !tsTree.empty())
        {
            while (cur != nullptr)
            {   
                tsTree.push(cur);
                cur = cur->left;
            }

            cur = tsTree.top();
            tsTree.pop();
            m_val.push_back(cur->val);
            cur = cur->right;
        }
        
    }

};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */
// @lc code=end

