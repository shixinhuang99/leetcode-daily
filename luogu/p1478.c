/* P1478 陶陶摘苹果（升级版） */
#include<stdio.h>
int main(void){
    int n, s; // n:苹果数 s:力气
    int a, b;
    scanf("%d%d", &n, &s);
    scanf("%d%d", &a, &b);
    int ar[n][2];
    int ct = 0;
    for(int i = 0; i < n; ++i){
        scanf("%d%d", &ar[i][0], &ar[i][1]);
    }
    // 按所需力气从小到大排序
    for(int i = 0; i < n; ++i){
        for(int j = i + 1; j < n; ++j){
            int temp;
            if(ar[j][1] < ar[i][1]){
                temp = ar[j][1];
                ar[j][1] = ar[i][1];
                ar[i][1] = temp;
                temp = ar[j][0];
                ar[j][0] = ar[i][0];
                ar[i][0] = temp;
            }
        }
    }
    for(int i = 0; i < n; ++i){
        if(a + b >= ar[i][0]){
            if(s > 0 && s >= ar[i][1]){
                ++ct;
                s -= ar[i][1];
            }else if(s == 0 && ar[i][1] == 0){
                ++ct;
            }
        }
    }
    printf("%d", ct);
    return 0;
}