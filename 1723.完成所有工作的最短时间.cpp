/*
 * @lc app=leetcode.cn id=1723 lang=cpp
 *
 * [1723] 完成所有工作的最短时间
 */

// @lc code=start
class Solution {
//DP状态数组，其中一维表示不同终点可能的状态，二维表示终点；
int f[1 << 13][13];
public:
    int minimumTimeRequired(vector<int>& jobs, int k) {
        int n = jobs.size();
        //初始化，求最短时间，初始化为正无穷
        memset(f, 0x3f, sizeof f);

        //初始化1个工人的情况
        //枚举所有工作分配情况
        //第一个人可以对每项工作选择做或者不做，如果做的话那么第一个人初始化要加上相应的时间；
        for (int i = 0; i < 1 << n; i ++) {
            f[i][1] = 0;
            for (int j = 0; j < n; j ++)
                if(i >> j & 1) f[i][1] += jobs[j];
        }

        //dp开始
        for (int i = 0; i < 1 << n; i ++)   //枚举所有工作分配情况
            for (int j = 1; j <= k; j ++)    //枚举所有工人个数情况
                for (int p = i; p ; p = p - 1 & i)  //枚举状态压缩子集
                    for (int q = 0; q < j; q ++)    //工人子集枚举
                        f[i][j] = min(f[i][j], max(f[p][q], f[i ^ p][j - q]));

        return f[(1 << n) - 1][k];
    }
};
// @lc code=end

