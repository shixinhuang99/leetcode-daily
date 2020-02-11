/* P1420 ×î³¤Á¬ºÅ */
#include<stdio.h>
int main(void){
    int n;
    scanf("%d", &n);
    int a, t;
    scanf("%d", &a);
    int ct = 1;
    int _ct = 0;
    for(int i = 1; i < n; ++i){
        t = a;
        scanf("%d", &a);
        if(a - t == 1){
            ++ct;
        }else{
            if(_ct < ct){
                _ct = ct;
            }
            ct = 1;
        }
    }
    printf("%d", _ct);
    return 0;
}