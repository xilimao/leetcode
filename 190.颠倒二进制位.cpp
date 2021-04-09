/*
 * @lc app=leetcode.cn id=190 lang=cpp
 *
 * [190] 颠倒二进制位
 */

// @lc code=start
class Solution {
public:
    uint32_t reverseBits(uint32_t n) {

        /*
        1.通过& 0000 0000 0000 0000 0000 0000 0000 0001,得到n当前最右侧的一位
        2.将ret左移一位，使ret的最右侧一位为 0(0|0 = 0, 0|1= 1)
        3.将获得的n的最右侧一位，位通过 | ret ,将其存入ret的最后一位
        3.将n右移一位并保存-依次处理32个
        */

        // uint32_t ret = 0;
        // for (int i = 0; i < 32; i++)
        // {
        //     ret = ret << 1;
        //     ret |= (n & 1); 
        //     n >>= 1;
        // }
        // return ret;


        n = (n >> 16) | (n << 16); //低16位与高16位交换
        n = ((n & 0xff00ff00) >> 8) | ((n & 0x00ff00ff) << 8); // 每16位中低8位和高8位交换
        n = ((n & 0xf0f0f0f0) >> 4) | ((n & 0x0f0f0f0f) << 4); // 每8位中低4位和高4位交换
        n = ((n & 0xcccccccc) >> 2) | ((n & 0x33333333) << 2); // 每4位中低2位和高2位交换 100 = c 0011=3
        n = ((n & 0xaaaaaaaa) >> 1) | ((n & 0x55555555) << 1); // 每2位中低1位和高1位交换 1010 = a 0101=5
        return n;
        
    }
};
// @lc code=end

