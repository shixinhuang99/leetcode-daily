/*
 * @Author       : ApassEr
 * @Date         : 2020-05-22 11:42:34
 * @LastEditTime : 2020-05-22 18:34:52
 * @Description  : UVA156 Ananagrams
 * @Algorithm    : STL:map
 */
#include<bits/stdc++.h>

using namespace std;

string init(const string &s) {
    string temp = s;
    for (auto &i : temp) {
        i = tolower(i);
    }
    sort(temp.begin(), temp.end());
    return temp;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    string s;
    vector<string> words;
    map<string, int> cnt;
    while (cin >> s && s != "#") {
        words.push_back(s);
        string result = init(s);
        if (!cnt.count(result)) {
            cnt[result] = 0;
        }
        ++cnt[result];
    }
    vector<string> ans;
    for (auto i : words) {
        if (cnt[init(i)] == 1) {
            ans.push_back(i);
        }
    }
    sort(ans.begin(), ans.end());
    for (auto i : ans) {
        cout << i << '\n';
    }
    return 0;
}