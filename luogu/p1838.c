#include<stdio.h>
#include<string.h>
int main(void){
    char a[10];
    char uim[10];
    char get[10];
    scanf("%s", get);
    int len = strlen(get);
    int x = 0, y = 0;
    for(int i = 0; i < len; ++i){
        if((i + 1) % 2 != 0){
            a[x++] = get[i];
        }else{
            uim[y++] = get[i];
        }
    }
    a[x] = uim[y] = '\0';
    const char *target[8] = {
        "123",
        "456",
        "789",
        "147",
        "258",
        "369",
        "159",
        "357"
    };
    int drew = 1;
    int len1 = strlen(a);
    int len2 = strlen(uim);
    int cnt1, cnt2;
    for(int i = 0; i < 8; ++i){
        cnt1 = 0;
        for(int j = 0; j < len1; ++j){
            if(strchr(target[i], a[j])){
                cnt1++;
            }
        }
        cnt2 = 0;
        for(int j = 0; j < len2; ++j){
            if(strchr(target[i], uim[j])){
                cnt2++;
            }
        }
        if(cnt1 == 3){
            printf("xiaoa wins.");drew = 0;break;
        }else if(cnt2 == 3){
            printf("uim wins.");drew = 0;break;
        }
    }
    if(drew){
        printf("drew.");
    }
    return 0;
}