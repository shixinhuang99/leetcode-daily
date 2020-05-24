/*
 * @Author       : ApassEr
 * @Date         : 2020-05-24 16:00:36
 * @LastEditTime : 2020-05-24 16:30:47
 * @Description  : UVA12096 The SetStack Computer
 * @Algorithm    : 栈
 */
#include<bits/stdc++.h>

using namespace std;

#define ALL(x) x.begin(), x.end()
#define INS(x) inserter(x, x.begin())

map <set<int>, int> id;
vector<set<int>> set0;

int ID(set<int> x) {
    if (id.count(x)) {
        return id[x];
    }
    set0.push_back(x);
    return id[x] = set0.size() - 1;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    stack<int> s;
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        int m;
        cin >> m;
        for (int j = 0; j < m; ++j) {
            string op;
            cin >> op;
            if (op[0] == 'P') {
                s.push(ID(set<int>()));
            } else if (op[0] == 'D') {
                s.push(s.top());
            } else {
                set<int> x1 = set0[s.top()];
                s.pop();
                set<int> x2 = set0[s.top()];
                s.pop();
                set<int> x;
                if (op[0] == 'U') {
                    set_union(ALL(x1), ALL(x2), INS(x));
                } else if (op[0] == 'I') {
                    set_intersection(ALL(x1), ALL(x2), INS(x));
                } else {
                    x = x2;
                    x.insert(ID(x1));
                }
                s.push(ID(x));
            }
            cout << set0[s.top()].size() << '\n';
        }
        cout << "***" << '\n';
    }
    return 0;
}