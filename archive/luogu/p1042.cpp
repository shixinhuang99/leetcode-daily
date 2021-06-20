/*
 * @Author       : ApassEr
 * @Date         : 2020-03-16 17:22:16
 * @LastEditTime : 2020-03-16 18:09:00
 * @Description  : P1042 乒乓球
 * 模拟，字符串
 */
#include<bits/stdc++.h>

using namespace std;

string str;
vector<int> res(2);

void display(int n) {
    for (auto i : str) {
        if (i == 'E') {
            cout << res[0] << ':' << res[1] << endl;
            res[0] = 0;
            res[1] = 0;
            break;
        } else if (i == 'W') {
            ++res[0];
        } else {
            ++res[1];
        }
        if ((res[0] >=n || res[1] >= n) && abs(res[0] - res[1]) >= 2) {
            cout << res[0] << ':' << res[1] << endl;
            res[0] = 0;
            res[1] = 0;
        }
    }
}

int main() {
    bool quit = false;
    while (!quit) {
        string temp;
        cin >> temp;
        str += temp;
        for (auto i : temp) {
            if (i == 'E') {
                quit = true;
                break;
            }
        }
    }
    display(11);
    cout << endl;
    display(21);
    return 0;
}