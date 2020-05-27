/*
 * @Author       : ApassEr
 * @Date         : 2020-05-27 10:40:11
 * @LastEditTime : 2020-05-27 11:29:07
 * @Description  : UVA699 The Falling Leaves
 * @Algorithm    : 递归，树的遍历
 */
#include<bits/stdc++.h>

using namespace std;

const int maxn = 200;
array<int, maxn> sum;

void build(int node) {
    int v;
    cin >> v;
    if (v == -1) {
        return;
    }
    sum[node] += v;
    build(node - 1);
    build(node + 1);
}

bool init() {
    int v;
    cin >> v;
    if (v == -1) {
        return false;
    }
    memset(sum.begin(), 0, sizeof(sum));
    int root = maxn / 2;
    sum[root] = v;
    build(root - 1);
    build(root + 1);
    return true;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int kase = 0;
    while (init()) {
        int pos = 0;
        while (sum[pos] == 0) {
            ++pos;
        }
        cout << "Case " << ++kase << ":\n" << sum[pos++];
        while (sum[pos] != 0) {
            cout << ' ' << sum[pos];
            ++pos;
        }
        cout << "\n\n";
    }
    return 0;
}