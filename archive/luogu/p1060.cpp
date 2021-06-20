/*
 * @Author       : ApassEr
 * @Date         : 2020-05-22 18:39:40
 * @LastEditTime : 2020-05-22 19:35:02
 * @Description  : P1060 开心的金明
 * @Algorithm    : 0-1背包dp
 */
#include<bits/stdc++.h>

using namespace std;

struct foo {
    int v;
    int p;
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, m;
    cin >> n >> m;
    vector<foo> bar(m);
    vector<int> dp(n + 1);
    for (int i = 0; i < m; ++i) {
        cin >> bar[i].v >> bar[i].p;
        bar[i].p = bar[i].v * bar[i].p;
    }
    for (int i = 0; i < m; ++i) {
        for (int j = n; j >= bar[i].v; --j) {
            dp[j] = max(dp[j - bar[i].v] + bar[i].p, dp[j]);
        }
    }
    cout << dp[n];
    return 0;
}