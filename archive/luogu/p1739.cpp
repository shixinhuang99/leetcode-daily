/*
 * @Description  : P1739 ±Ì¥Ô Ω¿®∫≈∆•≈‰
 * @Author       : ApassEr
 * @Date         : 2020-02-13 10:31:25
 * @LastEditTime : 2020-02-13 10:49:32
 */
#include<bits/stdc++.h>

using namespace std;

int main(void){
    char str[256];
    for(int i = 0; str[i] = getchar(); ++i){
        if(str[i] == '@'){
            str[i] = '\0';break;
        }
    }
    char *p1, *p2;
    char a = '(', b = ')';
    bool quit = false;
    bool yes = true;
    while(!quit){
        p1 = strchr(str, a);
        p2 = strchr(str, b);
        if(p2 < p1){
            yes = false;break;
        }
        if((p1 == nullptr && !(p2 == nullptr)) || (!(p1 == nullptr) && p2 == nullptr)){
            yes = false;break;
        }
        if(p1 == nullptr && p2 == nullptr) quit = true;
        else *p1 = *p2 = '0';
    }
    if(yes) printf("YES");
    else printf("NO");
    return 0;
}