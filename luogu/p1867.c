/*
 * @Description  : P1867 【Mc生存】经验值
 * @Author       : ApassEr
 * @Date         : 2020-02-06 18:06:40
 * @LastEditors  : ApassEr
 * @LastEditTime : 2020-02-06 19:03:57
 */
#include<stdio.h>
#include<math.h>
int main(void){
    int n;
    scanf("%d", &n);
    double hp = 10;
    int level = 0;
    double all_exp = 0;
    double get_exp;
    double dhp;
    for(int i = 0; i < n; ++i){
        scanf("%lf %lf", &dhp, &get_exp);
        hp -= dhp;
        if(hp <= 0){
            break;
        }else if(hp > 10){
            hp = 10;
        }
        all_exp += get_exp;
    }
    while(all_exp - (pow(2, level)) >= 0){
        all_exp -= ((pow(2, level)));
        level++;
    }
    printf("%d %.0lf", level, all_exp);
    return 0;
}