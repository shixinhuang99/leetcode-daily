/*
 * @Author       : ApassEr
 * @Date         : 2020-06-06 17:50:06
 * @LastEditTime : 2020-06-06 17:51:22
 * @Description  : 8. 字符串转换整数 (atoi)
 * @Algorithm    : 模拟
 */
class Solution {
public:
    int myAtoi(string str) {
        if (str.empty()) return 0;
        int index = 0;
        int64_t ans = 0;
        bool neg = false;
        while (str[index] == ' ') {
            ++index;
        }
        if (str[index] == '-') {
            neg = true;
            ++index;
        } else if (str[index] == '+') {
            ++index;
        }
        if (!isdigit(str[index])) return 0;
        while (isdigit(str[index])) {
            ans = ans * 10 + str[index] - '0';
            if (ans > INT_MAX) {
                return neg ? INT_MIN : INT_MAX;
            }
            ++index;
        }
        return neg ? -ans : ans;
    }
};