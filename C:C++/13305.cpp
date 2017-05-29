#include <cstdio>
long long ans[100010];
long long len[100010];
long long cost[100010];
int main() {
    int i;
    int n;
    int cnt = 0;
    long long sum = 0;
    scanf("%d",&n);
    for(i=1;i<n;i++) {
        scanf("%lld",&len[i]);
        len[i] += len[i-1];
    }
    for(i=0;i<n;i++) scanf("%lld",&cost[i]);
    ans[cnt++] = 0;
    for(i=1;i<n-1;i++) if(cost[ ans[cnt-1] ] > cost[i]) ans[cnt++] = i;
    ans[cnt++] = n - 1;
    for(i=1;i<cnt;i++) sum += (len[ans[i]] - len[ans[i-1]]) * cost[ans[i-1]];
    printf("%lld\n",sum);
    return 0;
}