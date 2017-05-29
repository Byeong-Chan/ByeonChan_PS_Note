#include <cstdio>
bool chk[1000010];
int main() {
    int i, j, n, k;
    int cnt = 0;
    scanf("%d %d",&n,&k);
    for(i=2;i<=n;i++) {
        if(chk[i]) continue;
        cnt++;
        chk[i] = true;
        if(cnt == k) {
            printf("%d\n",i);
            return 0;
        }
        for(j=i*i;j<=n;j+=i) {
            if(chk[j]) continue;
            cnt++;
            chk[j] = true;
            if(cnt == k) {
                printf("%d\n",j);
                return 0;
            }
        }
    }
    return 0;
}