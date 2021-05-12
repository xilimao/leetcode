/*
 * @lc app=leetcode.cn id=1310 lang=cpp
 *
 * [1310] 子数组异或查询
 */

// @lc code=start
class Solution {
public:
    // vector<int> xorQueries(vector<int>& arr, vector<vector<int>>& queries) {
    //     vector<int> ans(0, arr.size());

    //     for (int j = 0; j < queries.size(); j++)
    //     {
    //         int temp = 0;
    //         if(queries[j][0] == queries[j][1])
    //         {
    //            temp = arr[queries[j][0]];     
    //         }
    //         else
    //         {
    //             for (int i = queries[j][0]; i <= queries[j][1]; i++)
    //             {
    //                 temp ^= arr[i];
    //             }
    //         }
    //         ans.push_back(temp);
    //     }
        
    //     return ans;
    // }


    /*
    为什么可以使用前缀数组？
        首先，定义前缀数组。pre_xor[i]表示 arr数组中，前i个数的异或值
        即pre\_xor[i]= arr[0] \oplus arr[1] \oplus \cdots \oplus arr[i-1]pre_xor[i]=arr[0]⊕arr[1]⊕⋯⊕arr[i−1]

        其次，我们来观察一下这个数组的特性。取两个数 L,R (L \le R)L,R(L≤R)，然后有
        { 
        pre_xor[L]=arr[0]⊕arr[1]⊕⋯⊕arr[L−1]
        pre_xor[R]=arr[0]⊕⋯⊕arr[L−1]⊕arr[L]⊕⋯⊕arr[R−1]
        }

        pre_xor[L]⊕pre_xor[R]
            =(arr[0]⊕⋯⊕arr[L−1])⊕(arr[0]⊕⋯⊕arr[R−1])
            =(arr[0]⊕arr[0])⊕⋯⊕(arr[L−1]⊕arr[L−1])⊕arr[L]⊕⋯⊕arr[R−1]
            =arr[L]⊕⋯⊕arr[R−1]
​	

        最后，基于以上的性质，我们只需要带入L,R+1L,R+1，即可得到
        pre_xor[L]⊕pre_xor[R+1]=arr[L]⊕⋯⊕arr[R]
    */

    vector<int> xorQueries(vector<int>& arr, vector<vector<int>>& queries) {
        //源数组的长度
        int n = arr.size();
        //预设前缀-异或
        vector<int> preXor(n + 1, 0);
        //得到前缀异或
        for (int i = 1; i < n + 1; i++)
        {
            preXor[i] = preXor[i - 1] ^ arr[i - 1];
        }

        //初始化答案数组
        vector<int> lrXor;
        for (auto &querie : queries)
        {
            //获取左右边界值
            int l = querie[0], r = querie[1];
            //arr[L]⊕⋯⊕arr[R] = pre_xor[L]⊕pre_xor[R+1]
            lrXor.push_back(preXor[r + 1] ^ preXor[l]);
        } 
        return lrXor;
    }
};
// @lc code=end

