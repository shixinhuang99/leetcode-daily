/*
 * @Author       : ApassEr
 * @Date         : 2020-06-17 22:13:34
 * @LastEditTime : 2020-06-18 00:33:54
 * @Description  : P2239 螺旋矩阵
 * @Algorithm    : 找规律，等差数列
 */
#include<bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, i, j;
    cin >> n >> i >> j;
    int q = min(i, min(j, min(n - i + 1, n - j + 1)));
    int Aq = 4 * (n - 2 * q + 1);
    int Sq_1 = (4 * (q - 1)) * (n - (q - 1));
    int dit = i + j - 2 * q + 1;
    int ans;
    if (i <= j) {
        ans = Sq_1 + dit;
    } else {
        ans = Sq_1 + Aq - dit + 2;
    }
    cout << ans;
    return 0;
}

// 圈数：q = min(i, j, n - i + 1, n - j + 1)
// 第q圈有多少数：Aq = 4 * (n - 2 * q  + 1)
// 前q圈有多少数：Sq = (4 * q) * (n - q)
// m(i, j)具体位置：1）top & right：S(q - 1) + (i + j - 2 * q + 1)
//                2）bottom & left：S(q - 1) + Aq - (i + j - 2 * q) + 2