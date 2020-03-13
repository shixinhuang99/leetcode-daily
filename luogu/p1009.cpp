/*
 * @Author       : ApassEr
 * @Date         : 2020-03-13 23:38:57
 * @LastEditTime : 2020-03-14 00:00:34
 * @Description  : P1009 阶乘之和
 * 高精度
 */
#include<bits/stdc++.h>

using namespace std;

int sum[100];
int pre[100];

int main() {
    int n;
    cin >> n;
    if (n == 0) {
        cout << '0';
        return 0;
    }
    sum[0] = 1;
    pre[0] = 1;
    for (int i = 2; i <= n; ++i) {
        for (int j = 0; j < 100; ++j) {
            pre[j] = pre[j] * i;
        }
        for (int j = 0; j < 100; ++j) {
            if (pre[j] >= 10) {
                pre[j + 1] += pre[j] / 10;
                pre[j] %= 10;
            }
        }
        for (int j = 0; j < 100; ++j) {
            sum[j] += pre[j];
            if (sum[j] >= 10) {
                sum[j + 1] += 1;
                sum[j] -= 10;
            }
        }
    }
    int index = 0;
    for (int i = 99; i >=0; --i) {
        if (sum[i] != 0) {
            index = i;
            break;
        }
    }
    for (int i = index; i >= 0; --i) {
        putchar(sum[i] + '0');
    }
    return 0;
}