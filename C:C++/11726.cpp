#include <stdio.h>
int dt[1010];
int sub(int n) {
    if(dt[n] > 0) return dt[n];
    return (dt[n] = (sub(n-1) + sub(n-2)) % 10007);
}
int main() {
    int n;
    dt[1] = 1;
    dt[2] = 2;
    scanf("%d",&n);
    printf("%d",sub(n));
    return 0;
}