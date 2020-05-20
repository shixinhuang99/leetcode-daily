/*
 * @Author       : ApassEr
 * @Date         : 2020-02-11 14:44:59
 * @LastEditTime : 2020-05-20 16:47:31
 * @Description  : P1048 采药
 * @Algorithm    : 0-1背包dp
 */
#include<bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int T, M;
    cin >> T >> M;
    vector<int> t(M);
    vector<int> v(M);
    vector<int> f(T + 1);
    for (int i = 0; i < M; ++i) {
        cin >> t[i] >> v[i];
    }
    for (int i = 0; i < M; ++i) {
        for (int j = T; j >= t[i]; --j) {
            if ((f[j - t[i]] + v[i]) > f[j]) {
                f[j] = f[j - t[i]] + v[i];
            }
        }
    }
    cout << f[T];
    return 0;
}