/*
 * @Author       : ApassEr
 * @Date         : 2020-03-14 18:12:37
 * @LastEditTime : 2020-03-14 19:24:44
 * @Description  : P1022 计算器的改良
 * 模拟
 */
#include<bits/stdc++.h>

using namespace std;

typedef struct info {
    int coe;
    int con;
} equation;

int main() {
    string str;
    cin >> str;
    equation sum = {0, 0};
    int end = 0;
    for ( ; str[end] != '\0'; ++end) {
        continue;
    }
    bool coeIn = false;
    bool right = true;
    int temp = 0;
    int cnt = 1;
    char ch;
    for (int i = end; i >= 0; --i) {
        if (isalpha(str[i])) {
            ch = str[i];
            coeIn = true;
            continue;
        }
        if (isdigit(str[i])) {
            temp += (str[i] - '0') * cnt;
            cnt *= 10;
            continue;
        }
        if (ispunct(str[i])) {
            if (str[i] == '-') {
                temp = -temp;
            }
            if (coeIn) {
                if (right) {
                    sum.coe += temp;
                } else {
                    sum.coe -= temp;
                }
            } else {
                if (right) {
                    sum.con += temp;
                } else {
                    sum.con -= temp;
                }
            }
            coeIn = false;
            temp = 0;
            cnt = 1;
        }
        if (str[i] == '=') {
            right = false;
        }
    }
    if (temp != 0) {
        if (coeIn) {
            sum.coe -= temp;
        } else {
            sum.con -= temp;
        }
    }
    if (isalpha(str[0])) {
        sum.coe -= 1;
    }
    double ans = (double)sum.con / (double)sum.coe;
    printf("%c=%.3lf", ch, -ans);
    return 0;
}