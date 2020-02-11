/*
 * @Description  : P1876 开灯
 * @Author       : ApassEr
 * @Date         : 2020-02-06 19:36:21
 * @LastEditors  : ApassEr
 * @LastEditTime : 2020-02-06 20:38:50
 */
/*
打表：
#include<stdio.h>
int main(void){
    int light[1001] = {0};
    for(int n = 1; n <= 1000; ++n){
        for(int i = 1, j = 1; i <= n; ++i, ++j){
            if(i * j >= 1001){
                break;
            }else{
                if(light[i * j] == 1){
                    light[i * j] = 0;
                }else{
                    light[i * j] = 1;
                }
            }
        }
        printf("n = %3d: ", n);
        for(int i = 1; i <= n; ++i){
            if(light[i] == 1){
                printf("%d ", i);
                light[i] = 0;
            }
        }
        printf("\n");
    }
    return 0;
}
从表得出答案为完全平方数
*/
#include<stdio.h>
#include<math.h>
int main(void){
    double n;
    scanf("%lf", &n);
    double t;
    // 找到离n最近的完全平方数t
    for(double i = n; t = sqrt(i); --i){
        if(t - (int)t == 0){
            break;
        }
    }
    // 输出1到t的所有完全平方数
    for(double i = 1; i <= t; ++i){
        printf("%.0lf ", pow(i, 2));
    }
    /*
    简洁版本：
    int n;
    scanf("%d", &n);
    for(int i = 1; i * i <= n; ++i){
        printf("%d ", i * i);
    }
     */
    return 0;
}