/*
 * @Author       : ApassEr
 * @Date         : 2020-05-25 16:31:11
 * @LastEditTime : 2020-05-25 17:10:13
 * @Description  : UVA442 Matrix Chain Multiplication
 * @Algorithm    : 栈
 */
#include<bits/stdc++.h>

using namespace std;

struct matrix {
    int row;
    int col;
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    array<matrix, 26> arr;
    for (int i = 0; i < n; ++i) {
        string str;
        cin >> str;
        int index = str[0] - 'A';
        cin >> arr[index].row >> arr[index].col;
    }
    string expr;
    while (cin >> expr) {
        stack<matrix> s;
        int ans = 0;
        bool error = false;
        int len = expr.length();
        for (int i = 0; i < len; ++i) {
            if (isalpha(expr[i])) {
                s.push(arr[expr[i] - 'A']);
            } else if (expr[i] == ')') {
                matrix m2 = s.top(); s.pop();
                matrix m1 = s.top(); s.pop();
                if (m1.col != m2.row) {
                    error = true;
                    break;
                }
                ans += m1.row * m1.col * m2.col;
                matrix temp;
                temp.row = m1.row;
                temp.col = m2.col;
                s.push(temp);
            }
        }
        if (error) {
            cout << "error" << '\n';
        } else {
            cout << ans << '\n';
        }
    }
    return 0;
}