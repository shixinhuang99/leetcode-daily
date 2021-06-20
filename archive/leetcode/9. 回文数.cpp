/*
 * @Author       : ApassEr
 * @Date         : 2020-03-18 00:45:42
 * @LastEditTime : 2020-03-18 00:47:03
 * @Description  : 9. Palindrome Number
 * @Algorithm    : 整数反转
 */
class Solution {
public:
    bool isPalindrome(int x) {
        if (x < 0) {
            return false;
        } else if (x != 0 && x % 10 == 0) {
            return false;
        }
        long long copy = x;
        long long y = 0;
        while (copy > 0) {
            y = y * 10 + copy % 10;
            copy /= 10;
        }
        return y == x;
    }
};