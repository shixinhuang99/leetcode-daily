/*
 * @Author       : ApassEr
 * @Date         : 2020-06-16 15:05:51
 * @LastEditTime : 2020-06-16 16:02:17
 * @Description  : P2118 比例简化(题解思路)
 * @Algorithm    : 数论，枚举
 */
#include<bits/stdc++.h>

using namespace std;

int getGcd(int a, int b) {
    while (b != 0) {
        int t = a;
        a = b;
        b = t % b;
    }
    return a;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int a, b ,l;
    cin >> a >> b >> l;
    int ans_a = l;
    int ans_b = 1;
    for (int i = 1; i <= l; ++i) {
        for (int j = 1; j <= l; ++j) {
            if (getGcd(i, j) == 1 && i * b >= j * a && i * ans_b < j * ans_a) {
                ans_a = i;
                ans_b = j;
            }
        }
    }
    cout << ans_a << ' ' << ans_b;
    return 0;
}