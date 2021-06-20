/*
 * @Author       : ApassEr
 * @Date         : 2020-03-17 20:32:14
 * @LastEditTime : 2020-03-17 21:45:10
 * @Description  : P1056 排座椅
 * @Algorithm    : 贪心，排序
 */
#include<bits/stdc++.h>
#define min(x, y) ((x) < (y) ? (x) : (y))

using namespace std;

bool comp(vector<int> a, vector<int> b) {
    return a[1] > b[1];
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int m, n, k, l, d;
    cin >> m >> n >> k >> l >> d;
    vector<vector<int>> row(m, vector<int>(2, 0));
    vector<vector<int>> col(n, vector<int>(2, 0));
    for (int i = 0; i < m; ++i) {
        row[i][0] = i + 1;
    }
    for (int i = 0; i < n; ++i) {
        col[i][0] = i + 1;
    }
    for (int i = 0; i < d; ++i) {
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        if (x1 == x2) {
            ++col[min(y1, y2) - 1][1];
        } else if (y1 == y2) {
            ++row[min(x1, x2) - 1][1];
        }
    }
    sort(row.begin(), row.end(), comp);
    sort(col.begin(), col.end(), comp);
    vector<int> ans_row(k, 0);
    vector<int> ans_col(l, 0);
    for (int i = 0; i < k; ++i) {
        ans_row[i] = row[i][0];
    }
    for (int i = 0; i < l; ++i) {
        ans_col[i] = col[i][0];
    }
    sort(ans_row.begin(), ans_row.end());
    sort(ans_col.begin(), ans_col.end());
    for (int i = 0; i < k; ++i) {
        cout << ans_row[i];
        if (i != k - 1) {
            cout << ' ';
        }
    }
    cout << '\n';
    for (int i = 0; i < l; ++i) {
        cout << ans_col[i];
        if (i != l - 1) {
            cout << ' ';
        }
    }
    return 0;
}