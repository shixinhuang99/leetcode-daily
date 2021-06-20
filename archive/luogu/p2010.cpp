/*
 * @Author       : ApassEr
 * @Date         : 2020-06-12 20:38:55
 * @LastEditTime : 2020-06-12 23:56:48
 * @Description  : P2010 回文日期
 * @Algorithm    : 枚举(题解思路)
 */
#include<bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int beg;
    int end;
    cin >> beg >> end;
    int m[13] = {0,31,29,31,30,31,30,31,31,30,31,30,31};
    int cnt = 0;
    for (int i = 1; i <= 12; ++i) {
        for (int j = 1; j <= m[i]; ++j) {
            // 利用月日构造回文数而不是枚举并检查起始日期到结束日期的每个日期
            int y = (j % 10) * 1000 + (j / 10) * 100 + (i % 10) * 10 + (i / 10);
            int date = y * 10000 + i * 100 + j;

            if (date < beg || date > end) {
                continue;
            }
            ++cnt;
        }
    }
    cout << cnt;
    return 0;
}