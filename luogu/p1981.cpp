/*
 * @Author       : ApassEr
 * @Date         : 2020-06-05 15:48:28
 * @LastEditTime : 2020-06-05 19:31:16
 * @Description  : P1981 表达式求值
 * @Algorithm    : 模拟，栈
 */
#include<bits/stdc++.h>

using namespace std;

const int mod = 10000;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int64_t n;
    int64_t ans = 0;
    int64_t multi;
    char ch;
    char pre_ch = 0;
    while (cin >> n) {
        cin >> ch;
        if (pre_ch == 0) {
            multi = n;
        }
        if (pre_ch == '+') {
            ans = (ans + multi) % mod;
            multi = n;
        }
        if (pre_ch == '*') {
            multi = (multi * n) % mod;
        }
        pre_ch = ch;
    }
    cout << (ans + multi) % mod;
    return 0;
}