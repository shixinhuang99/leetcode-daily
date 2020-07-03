/*
 * @Author       : ApassEr
 * @Date         : 2020-07-03 22:39:03
 * @LastEditTime : 2020-07-03 22:40:20
 * @Description  : 20. 有效的括号
 * @Algorithm    : 栈
 */
class Solution {
public:
    bool isValid(string s) {
        if (s.empty()) return true;
        stack<char> sc;
        unordered_map<char, char> m = {
            {')', '('},
            {']', '['},
            {'}', '{'}
        };
        for (auto i : s) {
            if (i == ')' || i == ']' || i == '}') {
                if (!sc.empty() && sc.top() == m[i]) {
                    sc.pop();
                } else {
                    return false;
                }
            } else {
                sc.push(i);
            }
        }
        return sc.empty() ? true : false;
    }
};