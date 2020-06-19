/*
 * @Author       : ApassEr
 * @Date         : 2020-06-19 13:11:26
 * @LastEditTime : 2020-06-19 13:12:06
 * @Description  : 125. 验证回文串
 * @Algorithm    : 双指针
 */
class Solution {
public:
    bool isPalindrome(string s) {
        int l = 0;
        int r = s.size() - 1;
        while (l < r) {
            while (l < r && !isalnum(s[l])) {
                ++l;
            }
            while (l < r && !isalnum(s[r])) {
                --r;
            }
            if (l < r) {
                if (tolower(s[l]) != tolower(s[r])) {
                    return false;
                }
                ++l;
                --r;
            }
        }
        return true;
    }
};