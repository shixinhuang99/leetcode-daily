/*
 * @Author       : ApassEr
 * @Date         : 2020-06-06 14:44:59
 * @LastEditTime : 2020-06-06 15:03:02
 * @Description  : P1190 接水问题
 * @Algorithm    : 贪心
 */
#include<bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, m;
    cin >> n >> m;
    vector<int> v(m);
    vector<int> v2(n - m);
    for (int i = 0; i < m; ++i) {
        cin >> v[i];
    }
    for (int i = n - m -1; i >= 0; --i) {
        cin >> v2[i];
    }
    while (!v2.empty()) {
        sort(v.begin(), v.end());
        v.front() += v2.back();
        v2.pop_back();
    }
    sort(v.begin(), v.end());
    cout << v.back();
    return 0;
}