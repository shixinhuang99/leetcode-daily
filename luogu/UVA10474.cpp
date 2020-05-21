/*
 * @Author       : ApassEr
 * @Date         : 2020-05-21 14:51:54
 * @LastEditTime : 2020-05-21 15:40:00
 * @Description  : UVA10474 大理石在哪儿 Where is the Marble?
 * @Algorithm    : STL/排序/二分查找
 */
#include<bits/stdc++.h>

using namespace std;

int n, q, x;
int case0;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    while(cin >> n >> q && n) {
        vector<int> a(n);
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
        }
        sort(a.begin(), a.end());
        cout << "CASE# " << ++case0 << ":" << '\n';
        while (q--) {
            cin >> x;
            auto p = lower_bound(a.begin(), a.end(), x);
            if (*p == x) {
                cout << x << " found at " << p - a.begin() + 1 << '\n';
            } else {
                cout << x << " not found" << '\n';
            }
        }
    }
    return 0;
}