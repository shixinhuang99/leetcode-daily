/*
 * @Author       : ApassEr
 * @Date         : 2020-06-07 14:35:11
 * @LastEditTime : 2020-06-07 17:36:17
 * @Description  : P1309 瑞士轮(题解思路)
 * @Algorithm    : 归并，快排
 */
#include<bits/stdc++.h>

using namespace std;

const int maxn = 2e5 + 10;

struct foo {
    int id;
    int score;
    int level;
    bool operator<(const foo& rhs) const {
        if (score == rhs.score) {
            return id < rhs.id;
        }
        return score > rhs.score;
    }
};

foo winer[maxn];
foo loser[maxn];
foo player[maxn];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, r, q;
    cin >> n >> r >> q;
    int t = n;
    n *= 2;
    for (int i = 0; i < n; ++i) {
        player[i].id = i + 1;
        cin >> player[i].score;
    }
    for (int i = 0; i < n; ++i) {
        cin >> player[i].level;
    }
    sort(player, player + n);
    for (int i = 0; i < r; ++i) {
        for (int j = 0, k = 0; j < n; j += 2, ++k) {
            if (player[j].level > player[j + 1].level) {
                ++player[j].score;
                winer[k] = player[j];
                loser[k] = player[j + 1];
            } else {
                ++player[j + 1].score;
                winer[k] = player[j + 1];
                loser[k] = player[j];
            }
        }
        merge(winer, winer + t, loser, loser + t, player);
    }
    cout << player[q - 1].id;
    return 0;
}