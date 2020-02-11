#include<stdio.h>
#include<string.h>
int main(void){
    char a[7], b[7];
    unsigned r1 = 1, r2 = 1;
    gets(a);
    gets(b);
    for(int i = 0; i < strlen(a); ++i){
        r1 *= (a[i] -64);
    }
    for(int i = 0; i < strlen(b); ++i){
        r2 *= (b[i] -64);
    }
    if(r1 % 47 == r2 % 47){
        printf("GO");
    }else{
        printf("STAY");
    }
    return 0;
}