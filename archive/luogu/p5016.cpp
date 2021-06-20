/*
 * @Author       : ApassEr
 * @Date         : 2020-07-01 16:13:33
 * @LastEditTime : 2020-07-01 17:20:18
 * @Description  : P5016 龙虎斗
 * @Algorithm    : 模拟
 */
#include<bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    vector<int64_t> army(n + 1);
    for (int i = 1; i <= n; ++i) {
        cin >> army[i];
    }
    int m, p1;
    int64_t s1, s2;
    cin >> m >> p1 >> s1 >> s2;
    army[p1] += s1;
    int64_t left = 0;
    int64_t right = 0;
    for (int i = 1; i < m; ++i) {
        left += army[i] * (m - i);
    }
    for (int i = m + 1; i <= n; ++i) {
        right += army[i] * (i - m);
    }
    int64_t pre = INT64_MAX;
    int64_t cur;
    int ans;
    for (int i = 1; i <= n; ++i) {
        int64_t t1 = left;
        int64_t t2 = right;
        if (i < m) {
            t1 += s2 * (m - i);
        } else if (i > m) {
            t2 += s2 * (i - m);
        }
        cur = abs(t1 - t2);
        if (cur < pre) {
            pre = cur;
            ans = i;
        }
    }
    cout << ans;
    return 0;
}