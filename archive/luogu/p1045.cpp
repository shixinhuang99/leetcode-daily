/*
 * @Author       : ApassEr
 * @Date         : 2020-03-16 20:29:45
 * @LastEditTime : 2020-03-16 22:10:56
 * @Description  : P1045 麦森数
 * 数论，高精度快速幂
 */
#include<bits/stdc++.h>

using namespace std;

bool done = false;

vector<int> binpow(vector<int> a, vector<int> b) {
    vector<int> temp(501, 0);
    for (int i = 0; i < 500; ++i) {
        for (int j = 0; j <= i; ++j) {
            temp[i] += a[j] * b[i - j];
        }
        if (temp[i] >= 10) {
            temp[i + 1] += temp[i] / 10;
            temp[i] %= 10;
        }
    }
    return temp;
}

int main() {
    int p;
    cin >> p;
    int s = p * log10(2) + 1;
    cout << s << endl;
    vector<int> res(501, 0);
    vector<int> a(501, 0);
    res[0] = 1;
    a[0] = 2;
    while (p > 0) {
        if (p & 1) {
            res = binpow(res, a);
        }
        res[500] = 0;
        a = binpow(a, a);
        p >>= 1;
    }
    for (int i = 499; i >= 0; --i) {
        if (i == 0) {
            res[i] -= 1;
        }
        cout << res[i];
        if (i % 50 == 0) {
            cout << endl;
        }
    }
    return 0;
}