/*
 * @Author       : ApassEr
 * @Date         : 2020-05-25 18:15:47
 * @LastEditTime : 2020-05-25 18:33:17
 * @Description  : UVA11988 Broken Keyboard (a.k.a. Beiju Text)
 * @Algorithm    : 链表
 */
#include<bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    string str;
    while (cin >> str) {
        str = " " + str;
        int cur = 0;
        int last = 0;
        int len = str.length();
        vector<int> next(len, 0);
        for (int i = 1; i < len; ++i) {
            if (str[i] == '[') {
                cur = 0;
            } else if (str[i] == ']') {
                cur = last;
            } else {
                next[i] = next[cur];
                next[cur] = i;
                if (cur == last) {
                    last = i;
                }
                cur = i;
            }
        }
        for (int i = next[0]; i != 0; i = next[i]) {
            cout << str[i];
        }
        cout << '\n';
    }
    return 0;
}