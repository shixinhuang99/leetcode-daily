/*
 * @Author       : ApassEr
 * @Date         : 2020-06-05 10:02:06
 * @LastEditTime : 2020-06-05 12:00:33
 * @Description  : P1086 花生采摘
 * @Algorithm    : 模拟
 */
#include<bits/stdc++.h>

using namespace std;

struct pos {
    int x;
    int y;
    int value;
    pos() = default;
    pos(int x_, int y_, int v) : x(x_), y(y_), value(v) {}
};

bool cmp(pos& a, pos& b) {
    return a.value > b.value;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, m, t;
    cin >> n >> m >> t;
    vector<pos> filed;
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            int v;
            cin >> v;
            if (v) {
                pos temp(i, j, v);
                filed.push_back(temp);
            }
        }
    }
    if (filed.empty()) {
        cout << 0;
        return 0;
    }
    sort(filed.begin(), filed.end(), cmp);
    int cnt = 0;
    int x = 0;
    int y = filed[0].y;
    int get_time;
    int back_time;
    for (int i = 0; i < (int)filed.size(); ++i) {
        get_time = abs(filed[i].x - x) + abs(filed[i].y - y) + 1;
        back_time = filed[i].x;
        t -= get_time;
        if (t - back_time < 0) {
            break;
        }
        cnt += filed[i].value;
        x = filed[i].x;
        y = filed[i].y;
    }
    cout << cnt;
    return 0;
}