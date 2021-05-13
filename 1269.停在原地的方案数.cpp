/*
 * @lc app=leetcode.cn id=1269 lang=cpp
 *
 * [1269] 停在原地的方案数
 */

// @lc code=start
class Solution {
public:
    const int MODULO = 1000000007;

    int numWays(int steps, int arrLen) {
        int maxColumn = min(arrLen - 1, steps);
        vector<int> dp(maxColumn + 1);
        dp[0] = 1;
        for (int i = 1; i <= steps; i++) {
            vector<int> dpNext(maxColumn + 1);
            for (int j = 0; j <= maxColumn; j++) {
                dpNext[j] = dp[j];
                if (j - 1 >= 0) {
                    dpNext[j] = (dpNext[j] + dp[j - 1]) % MODULO;
                }
                if (j + 1 <= maxColumn) {
                    dpNext[j] = (dpNext[j] + dp[j + 1]) % MODULO;
                }
            }
            dp = dpNext;
        }
        return dp[0];
    }
};

// @lc code=end

