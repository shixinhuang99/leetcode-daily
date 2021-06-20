/*
 * @Author       : ApassEr
 * @Date         : 2020-06-14 19:59:35
 * @LastEditTime : 2020-06-15 00:20:32
 * @Description  : P2058 海港
 * @Algorithm    : 模拟
 */
#include<bits/stdc++.h>

using namespace std;

const int L = 86400;

vector<pair<int, int>> p;
unordered_map<int, int> nats;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int i = 0;
    int ans = 0;
    int boats;
    cin >> boats;
    while (boats--) {
        int t, n;
        cin >> t >> n;
        while (n--) {
            int nat;
            cin >> nat;
            p.push_back({t, nat});
            if (nats[nat] == 0) ++ans;
            ++nats[nat];
        }
        while (t - p[i].first >= L) {
            --nats[p[i].second];
            if (nats[p[i].second] == 0) {
                --ans;
            }
            ++i;
        }
        cout << ans << '\n';
    }
    return 0;
}