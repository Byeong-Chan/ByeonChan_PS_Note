#include <stdio.h>
#include <string.h>
char o[100001];
int main() {
    int i, n;
    scanf("%s",o);
    n = strlen(o);
    for(i=0;i<n;i++) {
        printf("%c",o[i]);
        if((i+1)%10 == 0) printf("\n");
    }
    return 0;
}