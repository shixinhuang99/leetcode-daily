/*
 * @Author       : ApassEr
 * @Date         : 2020-05-25 15:16:10
 * @LastEditTime : 2020-05-25 16:01:02
 * @Description  : UVA514 Rails
 * @Algorithm    : 栈
 */
#include<bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    while (cin >> n && n) {
        bool next = false;
        while (!next) {
            stack<int> s;
            vector<int> out(n);
            int in = 1;
            int index = 0;
            bool ans = true;
            for (int i = 0; i < n; ++i) {
                cin >> out[i];
                if (out[i] == 0) {
                    next = true;
                    break;
                }
            }
            if (!next) {
                while (index < n) {
                    if (in == out[index]) {
                        ++in;
                        ++index;
                    } else if (!s.empty() && s.top() == out[index]) {
                        s.pop();
                        ++index;
                    } else if (in <= n) {
                        s.push(in++);
                    } else {
                        ans = false;
                        break;
                    }
                }
                cout << (ans ? "Yes" : "No") << '\n';
            }
        }
        cout << '\n';
    }
    return 0;
}