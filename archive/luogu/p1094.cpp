/*
 * @Author       : ApassEr
 * @Date         : 2020-06-03 14:02:21
 * @LastEditTime : 2020-06-03 14:34:47
 * @Description  : P1094 纪念品分组
 * @Algorithm    : 贪心，排序
 */

// 很慢(182ms)

#include<bits/stdc++.h>

using namespace std;

bool comp(int& a, int& b) {
    return a > b;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int w, n;
    cin >> w >> n;
    vector<int> v(n);
    for (int i = 0; i < n; ++i) {
        cin >> v[i];
    }
    sort(v.begin(), v.end(), comp);
    int cnt = 0;
    while (!v.empty()) {
        int t = w - v.front();
        auto iter = lower_bound(v.begin(), v.end(), t, greater<int>());
        if (iter != v.end()) {
            v.erase(iter);
        }
        if (!v.empty()) {
            v.erase(v.begin());
        }
        ++cnt;
    }
    cout << cnt;
    return 0;
}

// 题解思路(80ms)
/*
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int w, n;
    cin >> w >> n;
    int arr[n];
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }
    sort(arr, arr + n);
    int cnt = 0;
    int b = 0;
    int e = n - 1;
    while (b <= e) {
        if (arr[b] + arr[e] <= w) {
            ++b;
            --e;
            ++cnt;
        } else {
            --e;
            ++cnt;
        }
    }
    cout << cnt;
    return 0;
}
 */