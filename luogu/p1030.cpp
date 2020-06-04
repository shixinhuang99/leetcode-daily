/*
 * @Author       : ApassEr
 * @Date         : 2020-06-04 23:20:25
 * @LastEditTime : 2020-06-05 00:31:50
 * @Description  : P1030 求先序排列
 * @Algorithm    : 构造二叉树，dfs
 */
#include<bits/stdc++.h>

using namespace std;

const int maxn = 100;

vector<int> pre_order;
int in_order[maxn];
int post_order[maxn];
int lch[maxn];
int rch[maxn];
int node_cnt;

int build(int L1, int R1, int L2, int R2) {
    if (L1 > R1) {
        return 0;
    }
    int root = post_order[R2];
    int in_order_root_index = L1;
    while (in_order[in_order_root_index] != root) {
        ++in_order_root_index;
    }
    int lch_node_cnt = in_order_root_index - L1;
    lch[root] = build(L1, in_order_root_index - 1, L2, L2 + lch_node_cnt - 1);
    rch[root] = build(in_order_root_index + 1, R1, L2 + lch_node_cnt, R2 -1);
    return root;
}

void dfs(int node) {
    pre_order.push_back(node);
    if (lch[node]) {
        dfs(lch[node]);
    }
    if (rch[node]) {
        dfs(rch[node]);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    string s1, s2;
    cin >> s1 >> s2;
    node_cnt = s1.size();
    for (int i = 0; i < node_cnt; ++i) {
        in_order[i] = s1[i];
        post_order[i] = s2[i];
    }
    build(0, node_cnt - 1, 0, node_cnt - 1);
    dfs(post_order[node_cnt - 1]);
    for (auto i : pre_order) {
        cout << (char)i;
    }
    return 0;
}