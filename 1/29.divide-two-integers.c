/*
 * @lc app=leetcode id=29 lang=c
 *
 * [29] Divide Two Integers
 */
//看的别人的解答 还是溢出了好几次 对边界不敏感 对数字不敏感， long...
// @lc code=start

int divide(int dividend, int divisor)
{
    if (dividend == INT_MIN && divisor == -1) {
        return INT_MAX;
    }
    int sign = (dividend > 0) ^ (divisor > 0) ? -1 : 1;
    long dvd = dividend, dis = divisor;
    if (dvd < 0) {
        dvd = -dvd;
    }
    if (dis < 0) {
        dis = -dis;
    }
    long result = 0;
    while (dvd >= dis) {
        long temp = dis, m = 1;

        while (dvd >= (temp << 1)) {
            m = m << 1;
            temp = temp << 1;
        }
        dvd -= temp;
        result += m;
    }
    return result * sign;
}

// @lc code=end
