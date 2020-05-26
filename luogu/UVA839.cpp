/*
 * @Author       : ApassEr
 * @Date         : 2020-05-26 22:50:53
 * @LastEditTime : 2020-05-26 23:08:57
 * @Description  : UVA839 Not so Mobile
 * @Algorithm    : 递归，树
 */
#include<bits/stdc++.h>

using namespace std;

bool foo(int &w) {
    int w1, d1, w2, d2;
    bool sub_left = true;
    bool sub_right = true;
    cin >> w1 >> d1 >> w2 >> d2;
    if (!w1) {
        sub_left = foo(w1);
    }
    if (!w2) {
        sub_right = foo(w2);
    }
    w = w1 + w2;
    return sub_left && sub_right && (w1 * d1 == w2 * d2);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int kase , w;
    cin >> kase;
    while (kase--) {
        if (foo(w)) {
            cout << "YES\n";
        } else {
            cout << "NO\n";
        }
        if (kase) {
            cout << '\n';
        }
    }
    return 0;
}