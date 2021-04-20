/*
 * @lc app=leetcode.cn id=28 lang=cpp
 *
 * [28] 实现 strStr()
 */

// @lc code=start
class Solution {
public:
    int strStr(string haystack, string needle) {

        int hayLen = haystack.size();
        int needLen = needle.size();

        //如果i>hayLen - needLen,那么后续的字符串肯定不会匹配
        for (int i = 0; i <= hayLen - needLen; i++)
        {
            //记录匹配字符的个数
            int times = 0;
            for (int j = 0; j < needLen; j++)
            {
                //逐个从i+j,尝试与needle字符做完全比较
                if(haystack[i + j] == needle[j])
                {
                    //匹配上则j++循环继续、个数加1
                    times ++;
                }
                else
                {
                    //匹配不上则i++
                    break;
                }
            }

            if(times == needLen)
            {
                return i;
            }
        } 

        return -1;
    }
};
// @lc code=end

