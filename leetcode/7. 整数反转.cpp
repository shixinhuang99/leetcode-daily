/*
 * @Author       : ApassEr
 * @Date         : 2020-03-17 23:58:16
 * @LastEditTime : 2020-03-17 23:58:55
 * @Description  : 7. Reverse Integer
 * @Algorithm    : 整数字符串转换
 */
class Solution {
public:
    int reverse(int x) {
        long long int ans = 0;
        const int overflow = 0x7fffffff;
        bool isNegative = x < 0 ? true : false;
        string str;
        stringstream itos;
        itos << x;
        itos >> str;
        std::reverse(str.begin(), str.end());
        stringstream stoi;
        stoi << str;
        stoi >> ans;
        if (isNegative) {
            ans = -ans;
        }
        if (ans < -overflow - 1 || ans > overflow) {
            ans = 0;
        }
        return ans;
    }
};