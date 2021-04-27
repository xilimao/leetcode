/*
 * @lc app=leetcode.cn id=938 lang=cpp
 *
 * [938] 二叉搜索树的范围和
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
    // int rangeSumBST(TreeNode* root, int low, int high) {
    //     if (!root)
    //     {
    //         return 0;
    //     }
        
    //     if(root->val > high)
    //     {
    //         return   rangeSumBST(root->left, low, high);
    //     }
    //     if(root->val < low)
    //     {
    //         return   rangeSumBST(root->right, low, high);
    //     }

    //     return root->val + rangeSumBST(root->right, low, high) + rangeSumBST(root->left, low, high);
    // }

    // int sum,l,h;

    // void dfs(TreeNode* root)
    // {
    //     dfs(root->left);

    //     if(root->val >= l && root->val <= h)
    //     {
    //         sum += root->val;
    //     }
    //     else
    //     {
    //         return;
    //     }

    //     dfs(root->right);
    // }

    // int rangeSumBST(TreeNode* root, int low, int high) 
    // {
    //     if(!root)
    //     {
    //         return 0;
    //     }

    //     sum = 0;
    //     l = low;
    //     h = high;

    //     dfs(root);

    //     return sum;
    // }

    // int s, l, h;
    // int rangeSumBST(TreeNode* root, int low, int high) {
    //     s = 0; l = low; h = high;
    //     dfs(root);
    //     return s;
    // }

    // void dfs(TreeNode* root){
    //     if (root){
    //         dfs(root->left);
    //         if (root->val >= l && root->val <= h)s += root->val;
    //         else if (root->val > h)return;
    //         dfs(root->right);
    //     }
    // }

    int rangeSumBST(TreeNode* root, int low, int high) 
    {
        int ans = 0;
        stack<TreeNode*> st;
        while (root || !st.empty())
        {
            //先将左节点加入到栈中
            while (root)
            {
                st.push(root);
                root = root->left;
            }

            //取栈中顶元素为当前节点
            root = st.top();
            st.pop();

            //如果当前结点的值大于High说明不在范围之内
            if (root->val > high)
            {
                break;
            }
            if(root->val >= low)
            {
                ans += root->val;
            }

            //遍历右结点
            root = root->right;
        }
        return ans;
    }

};
// @lc code=end

