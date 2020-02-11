/* P1568 赛跑 */
#include<stdio.h>
int main(void){
    int n, m;
    scanf("%d %d", &n, &m);
    int sh[n][2];
    int kc[m][2];
    int t = 0; // 总时长
    for(int i = 0; i < n; ++i){
        scanf("%d %d", &sh[i][0], &sh[i][1]);
        t += sh[i][1];
    }
    for(int i = 0; i < m; ++i){
        scanf("%d %d", &kc[i][0], &kc[i][1]);
    }
    // sh和kc每个时间单位已经经过的路程
    int sh_s[t];
    int kc_s[t];
    // 路程计算
    for(int i = 0, temp = 0, p = 0; i < n; ++i){
        for(int j = 0; j < sh[i][1]; ++j){
            temp += sh[i][0];
            sh_s[p++] = temp;
        }
    }
    for(int i = 0, temp = 0, p = 0; i < m; ++i){
        for(int j = 0; j < kc[i][1]; ++j){
            temp += kc[i][0];
            kc_s[p++] = temp;
        }
    }
    int ct = 0; // 变化次数
    char search; // 状态量
    int index; // 起始点
    // 忽略刚开始的领先状态并确定状态量和起始点
    for(int i = 0; i < t; ++i){
        int j = sh_s[i] - kc_s[i];
        if(j == 0){
            continue;
        }else if(j > 0){
            search = 'k';
            index = i;
            break;
        }else{
            search = 's';
            index = i;
            break;
        }
    }
    // 确定变化次数
    for(int i = index + 1; i < t; ++i){
        switch(search){
            case 'k':if(kc_s[i] > sh_s[i]){
                ++ct;
                search = 's';
            }
            break;
            case 's':if(sh_s[i] > kc_s[i]){
                ++ct;
                search = 'k';
            }
            break;
        }
    }
    // debug
    // printf("%d\n", t);
    // for(int i = 0; i < t; ++i){
    //     printf("%d %d\n", sh_s[i], kc_s[i]);
    // }
    printf("%d", ct);
    return 0;
}