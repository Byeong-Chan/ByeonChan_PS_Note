#include <cstdio>
int o[3022];
int u[3022], tmp[3022];
int main() {
    int i, j;
    int n;
    bool sw = false;
    o[0] = 1;
    scanf("%d",&n);
    if(n == 0) {
        printf("0\n");
        return 0;
    }
    for(i=1;i<n;i++) {
        for(j=0;j<3010;j++) {
            tmp[j] = o[j];
            o[j] = 0;
        }
        for(j=0;j<3010;j++) {
            o[j] += u[j] + tmp[j];
            o[j+1] += (o[j] / 10);
            o[j] %= 10;
        }
        for(j=0;j<3010;j++) u[j] = tmp[j];
    }
    for(i=3009;i>=0;i--) {
        if(sw && o[i] == 0) printf("0");
        else if(o[i] != 0) {
            sw = true;
            printf("%d",o[i]);
        }
    }
    printf("\n");
    return 0;
}