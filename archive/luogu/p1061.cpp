/*
 * @Author       : ApassEr
 * @Date         : 2020-05-22 13:37:57
 * @LastEditTime : 2020-05-22 14:44:51
 * @Description  : P1061 Jam的计数法
 * @Algorithm    : 模拟
 */
#include<bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int s, t, w;
    cin >> s >> t >> w;
    string str;
    cin >> str;
    for (int i = 0; i < 5; ++i) {
        int index = -1;
        for (int j = w - 1, target = t; j >= 0; --j, --target) {
            if (str[j] < target + 96) {
                index = j;
                break;
            }
        }
        if (index != -1) {
            ++str[index];
            for (int j = index + 1; j < w; ++j) {
                str[j] = str[j - 1] + 1;
            }
            cout << str << '\n';
        }
    }
    return 0;
}