/*
 * @Description  : P2708 Ӳ�ҷ�ת
 * @Author       : ApassEr
 * @Date         : 2020-02-11 12:30:58
 * @LastEditTime : 2020-02-11 12:45:17
 */
#include<bits/stdc++.h>
using namespace std;
int main(void){
    char str[10001];
    for(int i = 0; str[i] = getchar(); ++i){
        if(str[i] == EOF){
            str[i] = '\0';break;
        }
    }
    char search = str[0] == '0' ? '1' : '0';
    char next = str[0] == '0' ? '0' : '1';
    char temp;
    char *p;
    int cnt = 0;
    // �ҵ��治ͬ��λ��
    while(p = strchr(str, search)){
        // �ڴ�֮ǰ��ȫ������
        for(char *t = &str[0]; t <= p - 1; ++t){
            *t = search;
        }
        temp = search;
        search = next;
        next = temp;
        ++cnt;
    }
    if(str[0] == '0'){
        printf("%d", cnt + 1);
    }else{
        printf("%d", cnt);
    }
    return 0;
}
// 1001000111100