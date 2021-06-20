/*
 * @Author       : ApassEr
 * @Date         : 2020-05-24 18:26:04
 * @LastEditTime : 2020-05-24 18:52:06
 * @Description  : UVA136 Ugly Numbers
 * @Algorithm    : 优先队列
 */
#include<bits/stdc++.h>

using namespace std;

typedef long long LL;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    priority_queue<LL, vector<LL>, greater<LL>> pq;
    set<LL> s;
    pq.push(1);
    s.insert(1);
    int i = 0;
    const int coe[] = {2, 3, 5};
    while (++i) {
        LL ans = pq.top();
        pq.pop();
        if (i == 1500) {
            cout << "The 1500'th ugly number is " << ans << ".\n";
            break;
        }
        for (int j = 0; j < 3; ++j) {
            LL temp = ans * coe[j];
            if (!s.count(temp)) {
                pq.push(temp);
                s.insert(temp);
            }
        }
    }
    return 0;
}