/*
 * @Author       : ApassEr
 * @Date         : 2020-05-22 15:31:31
 * @LastEditTime : 2020-05-22 17:16:36
 * @Description  : P1068 分数线划定
 * @Algorithm    : 排序
 */
#include<bits/stdc++.h>

using namespace std;

struct info {
    int id;
    int score;
};

bool comp(info a, info b) {
    if (a.score == b.score) {
        return a.id < b.id;
    }
    return a.score > b.score;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, m;
    cin >> n >> m;
    vector<info> a;
    for (int i = 0; i < n; ++i) {
        info temp;
        cin >> temp.id >> temp.score;
        a.push_back(temp);
    }
    sort(a.begin(), a.end(), comp);
    m = m * 1.5;
    int score_line = a[m - 1].score;
    int cnt = 0;
    for (auto i : a) {
        if (i.score >= score_line) {
            ++cnt;
        }
    }
    cout << score_line << ' ' << cnt << '\n';
    for (int i = 0; i < cnt; ++i) {
        cout << a[i].id << ' ' << a[i].score << '\n';
    }
    return 0;
}