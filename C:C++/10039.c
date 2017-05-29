#include <stdio.h>
int main() {
    int i, e = 0, x;
    for(i=0;i<5;i++) {
        scanf("%d",&x);
        if(x<40) x = 40;
        e += x;
    }
    printf("%d",e/5);
    return 0;
}