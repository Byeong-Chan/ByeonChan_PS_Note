#include <stdio.h>
int chk[10010];
int n;
int main() {
    int i, n;
    int x;
    int a, b;
    scanf("%d",&n);
    for(i=0;i<n;i++) {
        scanf("%d",&x);
        chk[x]++;
    }
    for(i=1;i<=10000;i++) {
        a = chk[i];
        while(a > 0) {
            printf("%d\n",i);
            a--;
        } 
    }
    return 0;
}