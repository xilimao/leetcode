/*
 * @lc app=leetcode.cn id=1190 lang=cpp
 *
 * [1190] 反转每对括号间的子串
 */

// @lc code=start
class Solution {
public:
    string reverseParentheses(string s) {
        stack<string> stk;
        string str = "";

        for (auto &ch : s)
        {
            if(ch == '(')
            {
                //遇到左括号,则将当前的字符串入栈
                stk.push(str);
                //并且清空str,准备记录下一()内的字符
                str = "";
            }
            else if(ch == ')')
            {
                //遇到右括号，说明当前已经匹配了一组(),那么此时就可以将当前字符串反转
                reverse(str.begin(), str.end());
                //将反转后的str与前一个组合，然后继续寻找右括号
                str = stk.top() + str;
                //
                stk.pop();
            }
            else
            {
                //将未匹配到的字符组合到str中，等到匹配
                str.push_back(ch);
            }
        }

        return str;
    }
};
// @lc code=end

