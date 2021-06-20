/*
 * @Author       : ApassEr
 * @Date         : 2020-05-26 13:24:42
 * @LastEditTime : 2020-05-26 14:26:41
 * @Description  : UVA679 Dropping Balls
 * @Algorithm    : 模拟
 */
#include<bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int case_cnt;
    cin >> case_cnt;
    for (int i = 0; i < case_cnt; ++i) {
        int D, I;
        cin >> D >> I;
        int next = 1;
        for (int j = 0; j < D - 1; ++j) {
            if (I % 2) {
                next = 2 * next;
                I = (I + 1) / 2;
            } else {
                next = 2 * next + 1;
                I /= 2;
            }
        }
        cout << next << '\n';
    }
    int t;
    cin >> t;
    return 0;
}