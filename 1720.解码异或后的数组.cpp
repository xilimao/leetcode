/*
 * @lc app=leetcode.cn id=1720 lang=cpp
 *
 * [1720] 解码异或后的数组
 */

// @lc code=start


//encoded[i−1]


class Solution {
public:
/*
异或运算具有如下性质：
异或运算满足交换律和结合律；
任意整数和自身做异或运算的结果都等于 00，即 x⊕x=0；
任意整数和 00 做异或运算的结果都等于其自身，即 x⊕0=0⊕x=x。

推导过程
encoded[i−1]=arr[i−1]⊕arr[i]
encoded[i−1]⊕arr[i−1]=arr[i−1]⊕arr[i]⊕arr[i−1]
arr[i−1]⊕encoded[i−1]=arr[i−1]⊕arr[i−1]⊕arr[i]
arr[i−1]⊕encoded[i−1]=0⊕arr[i]
arr[i−1]⊕encoded[i−1]=arr[i]
*/

    vector<int> decode(vector<int>& encoded, int first) {
        //解码前的数组长度比解码后的大1
        int n = encoded.size() + 1;
        vector<int> arr(n);
        arr[0] = first;

        for (int i = 1; i < n; i++)
        {
            arr[i] = encoded[i - 1] ^ arr[i - 1];
        }

        return arr;
    }
};
// @lc code=end

