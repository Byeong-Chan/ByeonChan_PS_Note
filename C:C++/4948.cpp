#include <cstdio>
bool chk[3000010];
int sum[3000010];
int main() {
    int i, j;
    chk[1] = true;
    for(i=2;i*i<=3000000;i++) {
        if(chk[i]) continue;
        for(j=i*i;j<=3000000;j+=i) {
            if(chk[j]) continue;
            chk[j] = true;
        }
    }
    for(i=1;i<=3000000;i++) {
        sum[i] += sum[i-1];
        if(!chk[i]) sum[i]++;
    }
    int n;
    while(true) {
        scanf("%d",&n);
        if(n==0) break;
        printf("%d\n",sum[n<<1] - sum[n]);
    }
    return 0;
}