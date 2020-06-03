/*
 * @Author       : ApassEr
 * @Date         : 2020-06-03 17:33:27
 * @LastEditTime : 2020-06-03 19:14:33
 * @Description  : P1020 导弹拦截
 * @Algorithm    : dp求最长(不上升/上升)子序列，Dilworth定理
 */
#include<bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    vector<int> a;
    int t;
    while (cin >> t) {
        a.push_back(t);
    }
    if (a.empty()) {
        cout << 0 << '\n' << 0;
        return 0;
    }
    vector<int> dp(a.size() + 1, -1);
    int len = 0;
    int min = dp[0];
    for (int i = 0; i < (int)a.size(); ++i) {
        *upper_bound(dp.begin(), dp.end(), a[i], greater<int>()) = a[i];
    }
    while (dp[len] != min) {
        ++len;
    }
    cout << len << '\n';
    dp.assign(dp.size(), 1e6);
    int cnt = 0;
    int mx = dp[0];
    for (int i = 0; i < (int)a.size(); ++i) {
        *lower_bound(dp.begin(), dp.end(), a[i]) = a[i];
    }
    while (dp[cnt] != mx) {
        ++cnt;
    }
    cout << cnt;
    return 0;
}