/*
 * @Author       : ApassEr
 * @Date         : 2020-05-22 18:32:04
 * @LastEditTime : 2020-05-22 18:32:36
 * @Description  : P1616 疯狂的采药
 * @Algorithm    : 完全背包dp
 */
#include<bits/stdc++.h>

using namespace std;

struct foobar {
    int time;
    int value;
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int T, M;
    cin >> T >> M;
    vector<foobar> herbs(M);
    vector<int> dp(T + 1);
    for (int i = 0; i < M; ++i) {
        cin >> herbs[i].time >> herbs[i].value;
    }
    for (int i = 0; i < M; ++i) {
        for (int j = herbs[i].time; j <= T; ++j) {
            dp[j] = max(dp[j - herbs[i].time] + herbs[i].value, dp[j]);
        }
    }
    cout << dp[T];
    return 0;
}