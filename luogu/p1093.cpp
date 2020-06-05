/*
 * @Author       : ApassEr
 * @Date         : 2020-06-05 15:08:49
 * @LastEditTime : 2020-06-05 15:26:31
 * @Description  : P1093 奖学金
 * @Algorithm    : 排序
 */
#include<bits/stdc++.h>

using namespace std;

const int bar = 5;

struct foo {
    int id;
    int ch;
    int all;
    foo(int i, int c, int a) : id(i), ch(c), all(a) {}
};

bool cmp(foo& a, foo& b) {
    if (a.all != b.all) {
        return a.all > b.all;
    } else if (a.ch != b.ch) {
        return a.ch > b.ch;
    } else {
        return a.id < b.id;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    vector<foo> v;
    for (int i = 1; i <= n; ++i) {
        int a, b, c;
        cin >> a >> b >> c;
        foo t(i, a, a + b + c);
        v.push_back(t);
    }
    sort(v.begin(), v.end(), cmp);
    for (int i = 0; i < bar; ++i) {
        cout << v[i].id << ' ' << v[i].all << '\n';
    }
    return 0;
}