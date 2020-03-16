/*
 * @Author       : ApassEr
 * @Date         : 2020-03-16 14:10:07
 * @LastEditTime : 2020-03-16 14:25:53
 * @Description  : P1029 最大公约数和最小公倍数问题
 * gcd
 */
#include<bits/stdc++.h>

using namespace std;

int getGcd(int max, int min) {
    if (min == 0) {
        return max;
    }
    return getGcd(min, max % min);
}

int main() {
    int x, y;
    cin >> x >> y;
    int res = x * y;
    int cnt = 0;
    for (int p = x; p <= y; ++p) {
        double t = (double)res / (double)p;
        if (t > (int)t) {
            continue;
        }
        int q = (int)t;
        int min = p > q ? q : p;
        int max = p > q ? p : q;
        int gcd = getGcd(max, min);
        int lcm = res / gcd;
        if (gcd == x && lcm == y) {
            ++cnt;
        }
    }
    cout << cnt;
    return 0;
}