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
    //     if (!root)
    //     {
    //         return;
    //     }
        
    //     //如果<l 则其左子树还会<l, 没必要继续遍历
    //     if (root->val > l)
    //     {
    //         dfs(root->left);
    //     }
        
    //     if(root->val >= l && root->val <= h)
    //     {
    //         sum += root->val;
    //     }

    //     //如果>h 则其左子树还会>h，没必要继续遍历
    //     if (root->val < h)
    //     {
    //         dfs(root->right);
    //     }
    // }

    // int rangeSumBST(TreeNode* root, int low, int high) 
    // {
    //     sum = 0;
    //     l = low;
    //     h = high;

    //     dfs(root);

    //     return sum;
    // }


    //使用栈模拟递归过程
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

                if(root->val < low)
                {
                    break;
                }

                root = root->left;
            }

            //取栈中顶元素为当前节点
            root = st.top();
            st.pop();

            //因为中序遍历是递增的，其right会越来越大,索引可以提前判断推出
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

