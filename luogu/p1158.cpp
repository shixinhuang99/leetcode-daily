/*
 * @Author       : ApassEr
 * @Date         : 2020-06-03 10:33:46
 * @LastEditTime : 2020-06-03 12:18:24
 * @Description  : P1158 导弹拦截
 * @Algorithm    : 模拟，排序
 */
#include<bits/stdc++.h>

using namespace std;

struct pos {
    int x;
    int y;
    int r_a0;
    int r_a1;
};

bool comp(pos& a, pos& b) {
    return a.r_a0 > b.r_a0;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    pos a[2];
    cin >> a[0].x >> a[0].y >> a[1].x >> a[1].y;
    int cnt;
    cin >> cnt;
    pos b[cnt];
    for (int i = 0; i < cnt; ++i) {
        cin >> b[i].x >> b[i].y;
        b[i].r_a0 = pow((a[0].x - b[i].x), 2) + pow((a[0].y - b[i].y), 2);
        b[i].r_a1 = pow((a[1].x - b[i].x), 2) + pow((a[1].y - b[i].y), 2);
    }
    sort(b, b + cnt, comp);
    int ans = b[0].r_a0;
    int temp = b[0].r_a1;
    for (int i = 1; i < cnt; ++i) {
        if (temp < b[i].r_a1) {
            ans = min(temp + b[i].r_a0, ans);
            temp = b[i].r_a1;
        }
    }
    cout << ans;
    return 0;
}