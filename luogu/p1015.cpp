/*
 * @Author       : ApassEr
 * @Date         : 2020-03-15 17:24:53
 * @LastEditTime : 2020-03-18 13:57:55
 * @Description  : P1015 回文数
 * 模拟，高精度
 */
#include<bits/stdc++.h>

using namespace std;

int main() {
    int n;
    string s;
    cin >> n >> s;
    vector<int> m;
    int hex[6] = {10, 11, 12, 13, 14, 15};
    for (int i = 0; i != (int)s.size(); ++i) {
        if (isalpha(s[i])) {
            toupper(s[i]);
            m.push_back(hex[s[i] - 'A']);
        } else {
            m.push_back(s[i] - '0');
        }
    }
    int stepCnt = 0;
    while (stepCnt <= 30) {
        vector<int> copy = m;
        reverse(copy.begin(), copy.end());
        if (copy == m) {
            break;
        }
        int size = (int)m.size();
        for (int i = 0; i < size; ++i) {
            m[i] += copy[i];
            if (m[i] >= n) {
                if (i + 1 == size) {
                    m.push_back(1);
                } else {
                    m[i + 1] += 1;
                }
                m[i] -= n;
            }
        }
        reverse(m.begin(), m.end());
        ++stepCnt;
    }
    if (stepCnt <= 30) {
        cout << "STEP=" << stepCnt;
    } else {
        cout << "Impossible!";
    }
    return 0;
}