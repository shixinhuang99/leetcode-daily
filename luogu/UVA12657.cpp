/*
 * @Author       : ApassEr
 * @Date         : 2020-05-25 20:30:29
 * @LastEditTime : 2020-05-26 00:38:42
 * @Description  : UVA12657 Boxes in a Line
 * @Algorithm    : 双向链表
 */
#include<bits/stdc++.h>

using namespace std;

array<int, 100010> Right;
array<int, 100010> Left;

void link(int L, int R) {
    Right[L] = R;
    Left[R] = L;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, m;
    int kase = 0;
    while (cin >> n >> m) {
        for (int i = 1; i <= n; ++i) {
            Left[i] = i - 1;
            Right[i] = i + 1;
        }
        Right[n] = 0;
        Right[0] = 1;
        Left[0] = n;
        bool rev = false;
        for (int i = 0; i < m; ++i) {
            int op;
            cin >> op;
            if (op == 4) {
                rev = !rev;
            } else {
                int x, y;
                cin >> x >> y;
                if (op != 3 && rev) {
                    op = 3 - op;
                }
                if (op == 3 && x == Right[y]) {
                    swap(x, y);
                }
                if (op == 1 && x == Left[y]) {
                    continue;
                }
                if (op == 2 && x == Right[y]) {
                    continue;
                }
                int lx = Left[x];
                int rx = Right[x];
                int ly = Left[y];
                int ry = Right[y];
                if (op == 1) {
                    link(lx, rx);
                    link(ly, x);
                    link(x, y);
                } else if (op == 2) {
                    link(lx, rx);
                    link(y, x);
                    link(x, ry);
                } else if (op == 3) {
                    if (x == Left[y]) {
                        link(lx, y);
                        link(y, x);
                        link(x , ry);
                    } else {
                        link(lx, y);
                        link(y, rx);
                        link(ly, x);
                        link(x, ry);
                    }
                }
            }
        }
        long long ans = 0;
        int iter = 0;
        for (int i = 1; i <= n; ++i) {
            iter = Right[iter];
            if (i % 2 != 0) {
                ans += iter;
            }
        }
        if (rev && n % 2 == 0) {
            ans = (long long)n * (n + 1) / 2 - ans;
        }
        cout << "Case " << ++kase << ": " << ans << '\n';
    }
    return 0;
}