/*
 * @Description  : P5601 –°D”Î±  ‘
 * @Author       : ApassEr
 * @Date         : 2020-02-12 16:52:43
 * @LastEditTime : 2020-02-12 17:05:48
 */
#include<bits/stdc++.h>
using namespace std;
int main(void){
    int n, q;
    scanf("%d %d", &n, &q);
    char lib[n][101];
    char ans[n][101];
    for(int i = 0; i < n; ++i){
        scanf("%s", lib[i]);
        scanf("%s", ans[i]);
    }
    char t[101];
    char op[101];
    for(int i = 0; i < q; ++i){
        int index;
        scanf("%s", t);
        for(int j = 0; j < n; ++j){
            if(strcmp(t, lib[j]) == 0){
                index = j;break;
            }
        }
        for(int j = 0; j < 4; ++j){
            scanf("%s", op);
            if(strcmp(op, ans[index]) == 0){
                switch(j){
                    case 0:printf("A\n");break;
                    case 1:printf("B\n");break;
                    case 2:printf("C\n");break;
                    case 3:printf("D\n");break;
                }
            }
        }
    }
    return 0;
}