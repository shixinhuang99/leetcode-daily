/*
 * @Author       : ApassEr
 * @Date         : 2020-03-14 16:16:57
 * @LastEditTime : 2020-03-14 17:25:58
 * @Description  : P1011 车站
 * 模拟
 */
#include<bits/stdc++.h>

using namespace std;

struct info {
    int a;
    int t;
};

int main() {
    int a, n, m, x;
    cin >> a >> n >> m >> x;
    struct info up[n] = {
        {1, 0},
        {0, 1}
    };
    struct info down[n] = {
        {0, 0},
        {0, 1}
    };
    struct info sum_up = {1, 1};
    struct info sum_down = {0, 1};
    struct info sum_upInX;
    struct info sum_downInX;
    for (int i = 2; i < n - 1; ++i) {
        up[i].a = up[i - 1].a + up[i - 2].a;
        up[i].t = up[i - 1].t + up[i - 2].t;
        down[i] = up[i - 1];
        sum_up.a += up[i].a;
        sum_up.t += up[i].t;
        sum_down.a += down[i].a;
        sum_down.t += down[i].t;
        if (i + 1 == x) {
            sum_upInX = sum_up;
            sum_downInX = sum_down;
        }
    }
    int upin2 = (m - ((sum_up.a - sum_down.a) * a)) / (sum_up.t - sum_down.t);
    int ans = (sum_upInX.a - sum_downInX.a) * a + (sum_upInX.t - sum_downInX.t) * upin2;
    cout << ans;
    return 0;
}