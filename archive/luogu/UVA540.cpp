/*
 * @Author       : ApassEr
 * @Date         : 2020-05-24 17:28:30
 * @LastEditTime : 2020-05-24 18:06:15
 * @Description  : UVA540 Team Queue
 * @Algorithm    : 队列
 */
#include<bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int team_cnt;
    int scenario = 0;
    while (cin >> team_cnt && team_cnt) {
        cout << "Scenario #" << ++scenario << '\n';
        map<int, int> team;
        for (int i = 0; i < team_cnt; ++i) {
            int member_cnt;
            cin >> member_cnt;
            for (int j = 0; j < member_cnt; ++j) {
                int id;
                cin >> id;
                team[id] = i;
            }
        }
        queue<int> big;
        queue<int> small[team_cnt];
        string str;
        while (cin >> str && str[0] != 'S') {
            if (str[0] == 'E') {
                int id;
                cin >> id;
                if (small[team[id]].empty()) {
                    big.push(team[id]);
                }
                small[team[id]].push(id);
            } else {
                int t = big.front();
                cout << small[t].front() << '\n';
                small[t].pop();
                if (small[t].empty()) {
                    big.pop();
                }
            }
        }
        cout << '\n';
    }
    return 0;
}