/*
 * @lc app=leetcode.cn id=1011 lang=cpp
 *
 * [1011] 在 D 天内送达包裹的能力
 */

// @lc code=start
class Solution {
public:
    int shipWithinDays(vector<int>& weights, int D) 
    {
        // 序列中最大元素地址（迭代器）
        int left = *max_element(weights.begin(), weights.end());
        //取vector的和,第四个参数可以使用labmbda表达式，也可以使用系统的minus<int>(),multiplies<int>() 
        int right = accumulate(weights.begin(), weights.end(), 0);

        while (left < right)
        {
            //取中间值
            int mid = (left + right) / 2;
            //need:需要运输的天数
            int need = 1;
            //cur:当前这一天已经运送的包裹总和
            int cur = 0;

            for (int weight : weights)
            {
                //如果当前大于mid 则本天无法运输 需要加一天，重量清0
                if(cur + weight > mid)
                {
                    ++need;
                    cur = 0;
                }
                //如果不是则当天重量增加
                cur += weight;
            }

            if(need <= D)
            {
                //要求最低的运载能力
                //如果需要的天数<=要求天数,说明运载能力不是最低。
                //也就是说运载能力较大,所以需要把右边界调整为mid,缩小一下
                right = mid;
            }
            else
            {
                //需要的天数>要求天数,说明运载能力太低,需要调大左边界
                //运载能力太低
                left = mid + 1;
            }
        }
        return left;
    }
};
// @lc code=end

