/*
 * @Description  : P5711 �����3.��3�������ж�
 * @Author       : ApassEr
 * @Date         : 2020-02-12 21:30:24
 * @LastEditTime : 2020-02-12 21:33:05
 */
#include<bits/stdc++.h>

using namespace std;

int main(void){
    int n;
    scanf("%d", &n);
    if((n % 4 == 0 && n % 100 != 0) || (n % 400 == 0 && n % 3200 != 0) || n % 172800 == 0) printf("1");
    else printf("0");
    return 0;
}