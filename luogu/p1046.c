#include<stdio.h>
#define BENCH 30
int main(void){
    int lenth[10];
    int handmax;
    int count = 0;

    for(int i = 0; i < 10; i++){
        scanf("%d", &lenth[i]);
    }
    scanf("%d", &handmax);
    for(int i = 0; i < 10; i++){
        if((handmax + BENCH) >= lenth[i]){
            count++;
        }
    }
    printf("%d", count);

    return 0;
}