/*
 * @lc app=leetcode.cn id=1738 lang=cpp
 *
 * [1738] 找出第 K 大的异或坐标值
 */

// @lc code=start
class Solution {
public:
    int kthLargestValue(vector<vector<int>>& mat, int k) {
        int m = mat.size(), n = mat[0].size();
        int sum[m+1][n+1];
        memset(sum, 0, sizeof(sum));
        priority_queue<int, vector<int>, greater<int>> pq;
        for(int i = 1; i <= m; i++) {
            for(int j = 1; j <= n; j++) {
                sum[i][j] = sum[i-1][j] ^ sum[i][j-1] ^ sum[i-1][j-1] ^ mat[i-1][j-1];
                if(pq.size() < k)
                    pq.push(sum[i][j]);
                else {
                    if(sum[i][j] > pq.top()) {
                        pq.pop();
                        pq.push(sum[i][j]);
                    }
                }
            }
        }
        return pq.top();
    }
};

// @lc code=end

