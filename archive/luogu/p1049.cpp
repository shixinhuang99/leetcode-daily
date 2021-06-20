/*
 * @Author       : ApassEr
 * @Date         : 2020-05-20 17:16:01
 * @LastEditTime : 2020-05-20 17:29:31
 * @Description  : P1049 装箱问题
 * @Algorithm    : 0-1背包dp
 */
#include<bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int V, n;
    cin >> V >> n;
    vector<int> v(n);
    vector<int> f(V + 1);
    for (int i = 0; i < n; ++i) {
        cin >> v[i];
    }
    for (int i = 0; i < n; ++i) {
        for (int j = V; j >= v[i]; --j) {
            f[j] = max(f[j], f[j - v[i]] + v[i]);
        }
    }
    cout << V - f[V];
    return 0;
}