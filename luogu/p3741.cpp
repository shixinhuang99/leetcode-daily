/*
 * @Description  : P3741 honokaµÄ¼üÅÌ
 * @Author       : ApassEr
 * @Date         : 2020-02-12 11:09:46
 * @LastEditTime : 2020-02-12 11:13:29
 */
#include<bits/stdc++.h>
using namespace std;
int main(void){
    int n;
    scanf("%d", &n);
    char str[++n];
    for(int i = 0; str[i] = getchar(); ++i){
        if(str[i] == '\n' || str[i] == '\r') --i;
        else if(str[i] == EOF){
            str[i] = '\0';break;
        }
    }
    char a[] = "VK";
    char b[] = "VV";
    char c[] = "KK";
    int cnt = 0;
    char *p;
    while(p = strstr(str, a)){
        ++cnt;
        *p = *(p + 1) = '0';
    }
    while(strstr(str, b) || strstr(str, c)){
        ++cnt;break;
    }
    printf("%d", cnt);
    return 0;
}