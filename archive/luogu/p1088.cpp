/*
 * @Author       : ApassEr
 * @Date         : 2020-06-05 14:35:50
 * @LastEditTime : 2020-06-05 14:45:37
 * @Description  : P1088 火星人
 * @Algorithm    : 全排列
 */
#include<bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, m;
    cin >> n >> m;
    vector<int> v;
    int t;
    while (cin >> t) {
        v.push_back(t);
    }
    for (int i = 0; i < m; ++i) {
        next_permutation(v.begin(), v.end());
    }
    for (auto i : v) {
        cout << i << ' ';
    }
    return 0;
}