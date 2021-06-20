/*
 * @Author       : ApassEr
 * @Date         : 2020-05-26 18:37:23
 * @LastEditTime : 2020-05-26 19:12:50
 * @Description  : UVA548 Tree
 * @Algorithm    : DFS,构造树
 */
#include<bits/stdc++.h>

using namespace std;

const int maxn = 10010;
int node_cnt;
array<int, maxn> in_order;
array<int, maxn> post_order;
array<int, maxn> lch;
array<int, maxn> rch;

bool readInput(array<int, maxn> &arr) {
    node_cnt = 0;
    string str;
    int n;
    if (!getline(cin, str)) {
        return false;
    }
    stringstream stoi(str);
    while (stoi >> n) {
        arr[node_cnt++] = n;
    }
    return node_cnt > 0;
}

int build(int L1, int R1, int L2, int R2) {
    if (L1 > R1) {
        return 0;
    }
    int root = post_order[R2];
    int search = L1;
    while (in_order[search] != root) {
        ++search;
    }
    int lch_node_cnt = search - L1;
    lch[root] = build(L1, search - 1, L2, L2 + lch_node_cnt - 1);
    rch[root] = build(search + 1, R1, L2 + lch_node_cnt, R2 - 1);
    return root;
}

int cur_ans, best_ans;
void dfs(int node, int sum) {
    sum += node;
    if (!lch[node] && !rch[node]) {
        if (sum < best_ans || (sum == best_ans && node < cur_ans)) {
            cur_ans = node;
            best_ans = sum;
        }
    }
    if (lch[node]) {
        dfs(lch[node], sum);
    }
    if (rch[node]) {
        dfs(rch[node], sum);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    while (readInput(in_order)) {
        readInput(post_order);
        build(0, node_cnt - 1, 0, node_cnt - 1);
        best_ans = 100000000;
        dfs(post_order[node_cnt - 1], 0);
        cout << cur_ans << '\n';
    }
    return 0;
}