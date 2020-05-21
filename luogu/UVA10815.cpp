/*
 * @Author       : ApassEr
 * @Date         : 2020-05-21 19:06:10
 * @LastEditTime : 2020-05-21 19:14:14
 * @Description  : UVA10815 Andy's First Dictionary
 * @Algorithm    : STL:set
 */
#include<bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    set<string> dict;
    string str, buf;
    while (cin >> str) {
        for (int i = 0; i < str.length(); ++i) {
            if (isalpha(str[i])) {
                str[i] = tolower(str[i]);
            } else {
                str[i] = ' ';
            }
        }
        stringstream ss(str);
        while (ss >> buf) {
            dict.insert(buf);
        }
    }
    for (auto i : dict) {
        cout << i << '\n';
    }
    return 0;
}