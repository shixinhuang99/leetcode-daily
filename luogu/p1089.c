#include<stdio.h>
int main(void){
    const int a = 300;
    int budget[12];
    int r = 0;
    int b = 0;
    for(int i = 0; i < 12; i++){
        scanf("%d", &budget[i]);
    }
    for(int i = 0; i < 12; i++){
        r += 300 - budget[i];
        while(r >= 100){
            r -= 100;
            b += 100;
        }
        if(r < 0){
            printf("-%d", i + 1);
            break;
        }
    }
    if(r > 0){
        printf("%d", b += (b * 0.2) + r);
    }
    return 0;
}