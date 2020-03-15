/*
 * @Author       : ApassEr
 * @Date         : 2020-03-15 21:02:55
 * @LastEditTime : 2020-03-15 21:36:56
 * @Description  : P1010 幂次方
 * 分治
 */
#include<bits/stdc++.h>

using namespace std;

const int mask = 0x1;

void func(int n) {
    vector<int> bin(16);
    vector<int> temp;
    for (int i = 0; i < 16; ++i, n >>= 1) {
        bin[i] = mask & n;
    }
    for (int i = 15; i >= 0; --i) {
        if (bin[i] == 1) {
            temp.push_back(i);
        }
    }
    for (auto i : temp) {
        if (i > 2) {
            cout << "2(";
            func(i);
            cout << ')';
        } else if (i == 2) {
            cout << "2(2)";
        } else if (i == 1) {
            cout << "2";
        } else {
            cout << "2(0)";
        }
        if (i != *(temp.end() - 1)) {
            cout << '+';
        }
    }
}

int main() {
    int n;
    cin >> n;
    func(n);
    return 0;
}