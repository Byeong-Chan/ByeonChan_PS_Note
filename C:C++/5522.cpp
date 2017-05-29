#include <stdio.h>
int main() {
    int i, hap = 0, _in;
    for(i=0;i<5;i++) {
        scanf("%d",&_in);
        hap += _in;
    }
    printf("%d",hap);
    return 0;
}