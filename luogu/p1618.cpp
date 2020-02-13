/*
 * @Description  : P1618 ÈýÁ¬»÷£¨Éý¼¶°æ£©
 * @Author       : ApassEr
 * @Date         : 2020-02-13 17:30:55
 * @LastEditTime : 2020-02-13 18:06:30
 */
#include<bits/stdc++.h>

using namespace std;

int main(void){
    int a, b, c;
    scanf("%d %d %d", &a, &b, &c);
    if(c % a == 0 && b % a == 0){
        b /= a;
        c /= a;
        a /= a;
    }
    char str[10];
    char target[10] = "123456789";
    int max = 999 / c;
    bool flag = false;
    for(int i = 123; i < max; ++i){
        sprintf(str, "%d%d%d", i * a, i * b, i * c);
        sort(str, str + 9);
        if(strcmp(str, target) == 0){
            printf("%d %d %d\n", i * a, i * b, i * c);
            flag = true;
        }
    }
    sprintf(str, "%d%d%d", a, b, c);
    if(strcmp(str, target) == 0){
        printf("%d %d %d\n", a, b, c);
        flag = true;
    }
    if(!flag) printf("No!!!");
    return 0;
}