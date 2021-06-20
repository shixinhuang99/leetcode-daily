/*
 * @Author       : ApassEr
 * @Date         : 2020-05-21 17:24:59
 * @LastEditTime : 2020-05-21 18:22:42
 * @Description  : UVA101 The Blocks Problem
 * @Algorithm    : 模拟
 */
#include<bits/stdc++.h>

using namespace std;

int n;
vector<int> pile[25];

void findBlock (int block_id, int &p, int &h) {
    for (p = 0; p < n; ++p) {
        for (h = 0; h < (int)pile[p].size(); ++h) {
            if (block_id == pile[p][h]) {
                return;
            }
        }
    }
}

void moveBack (int p, int h) {
    for (int i = h + 1; i < (int)pile[p].size(); ++i) {
        int temp = pile[p][i];
        pile[temp].push_back(temp);
    }
    pile[p].resize(h + 1);
}

void pileOnto (int pa, int ha, int pb) {
    for (int i = ha; i < (int)pile[pa].size(); ++i) {
        pile[pb].push_back(pile[pa][i]);
    }
    pile[pa].resize(ha);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;
    for (int i = 0;i < n; ++i) {
        pile[i].push_back(i);
    }
    int a, b;
    string s1, s2;
    while(cin >> s1 >> a >> s2 >> b) {
        int pa, ha, pb, hb;
        findBlock(a, pa, ha);
        findBlock(b, pb, hb);
        if (pa == pb) {
            continue;
        }
        if (s1 == "move") {
            moveBack(pa, ha);
        }
        if (s2 == "onto") {
            moveBack(pb, hb);
        }
        pileOnto(pa, ha, pb);
    }
    for (int i = 0; i < n; ++i) {
        cout << i << ':';
        for (auto j : pile[i]) {
            cout << ' ' << j;
        }
        cout << '\n';
    }
    return 0;
}