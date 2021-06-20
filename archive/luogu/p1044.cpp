/*
 * @Author       : ApassEr
 * @Date         : 2020-06-05 14:06:05
 * @LastEditTime : 2020-06-05 14:17:09
 * @Description  : P1044 栈
 * @Algorithm    : Catalan数列
 */
#include<bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    vector<long long> f(n + 1);
    f[0] = 1;
    for (int i = 1; i <= n; ++i) {
        f[i] = f[i - 1] * (4 * i - 2) / (i + 1);
    }
    cout << f[n];
    return 0;
}