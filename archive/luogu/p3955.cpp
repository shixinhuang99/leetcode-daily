/*
 * @Author       : ApassEr
 * @Date         : 2020-06-30 22:00:31
 * @LastEditTime : 2020-06-30 22:49:49
 * @Description  : P3955 图书管理员
 * @Algorithm    : 模拟
 */
#include<bits/stdc++.h>

using namespace std;

int mod[8] = {1, 10, 100, 1000, 10000, 100000, 1000000, 10000000};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, q;
    cin >> n >> q;
    vector<int> book(n);
    for (int i = 0; i < n; ++i) {
        cin >> book[i];
    }
    sort(book.begin(), book.end());
    int len, code;
    for (int i = 0; i < q; ++i) {
        cin >> len >> code;
        int ans = -1;
        for (int j = 0; j < n; ++j) {
            if (book[j] % mod[len] == code) {
                ans = book[j];
                break;
            }
        }
        cout << ans << '\n';
    }
    return 0;
}