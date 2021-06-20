/*
 * @Description  : P1579 ¸çµÂ°ÍºÕ²ÂÏë£¨Éý¼¶°æ£©
 * @Author       : ApassEr
 * @Date         : 2020-02-13 18:33:42
 * @LastEditTime : 2020-02-13 20:13:21
 */
#include<bits/stdc++.h>

using namespace std;

int main(void){
    int n;
    scanf("%d", &n);

    // °£ÊÏÉ¸
    char is_prime[++n];
    int pri[n];
    int cnt = 0;
    memset(is_prime, '1', n);
    is_prime[0] = is_prime[1] = '0';
    for(int i = 2; i <= n; ++i){
        if(is_prime[i] == '1'){
            pri[cnt++] = i;
        }
        for(int j = i * i; j <= n; j += i) is_prime[j] = '0';
    }

    for(int i = 0; i < cnt; ++i){
        for(int j = 0; j < cnt; ++j){
            for(int k = 0; k < cnt; ++k){
                if(pri[i] + pri[j] + pri[k] == n - 1){
                    printf("%d %d %d", pri[i], pri[j], pri[k]);
                    return 0;
                }
            }
        }
    }
    return 0;
}