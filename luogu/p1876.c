/*
 * @Description  : P1876 ����
 * @Author       : ApassEr
 * @Date         : 2020-02-06 19:36:21
 * @LastEditors  : ApassEr
 * @LastEditTime : 2020-02-06 20:38:50
 */
/*
���
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
�ӱ�ó���Ϊ��ȫƽ����
*/
#include<stdio.h>
#include<math.h>
int main(void){
    double n;
    scanf("%lf", &n);
    double t;
    // �ҵ���n�������ȫƽ����t
    for(double i = n; t = sqrt(i); --i){
        if(t - (int)t == 0){
            break;
        }
    }
    // ���1��t��������ȫƽ����
    for(double i = 1; i <= t; ++i){
        printf("%.0lf ", pow(i, 2));
    }
    /*
    ���汾��
    int n;
    scanf("%d", &n);
    for(int i = 1; i * i <= n; ++i){
        printf("%d ", i * i);
    }
     */
    return 0;
}