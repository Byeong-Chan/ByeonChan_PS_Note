#include <cstdio>
int main() {
    int i, n;
    int tmp;
    scanf("%d",&n);
    tmp = n;
    for(i=2;i*i<=n;i++) {
        while(tmp % i == 0) {
            tmp /= i;
            printf("%d\n",i);
        }
    }
    if(tmp > 1) printf("%d\n",tmp);
    return 0;
}