#include <cstdio>
#include <algorithm>
using namespace std;
int len[10010][10010];
int dp[10010];
char o[10010];
int main() {
    int i, j, n;
    int k, l;
    int all;
    int tmp;
    int st, ed;
    scanf("%d %d %d",&n,&k,&l);
    scanf("%s",o+1);
    for(i=2;i<=n;i++) {
        for(j=1;j<=n-i+1;j++) {
            st = j;
            ed = j + i - 1;
            if(o[st] == o[ed]) len[st][ed] = len[st+1][ed-1] + 1;
        }
    }
    for(i=1;i<=n;i++) dp[i] = 0x7fffffff;
    for(i=1;i<n;i++) {
        if(dp[i-1] == 0x7fffffff) continue;
        for(j=i+1;j<=n;j++) {
            if((tmp = len[i][j] * 2) == 0) continue;
            all = j - i + 1;
            if(tmp * l >= k * all) dp[j] = min(dp[j], dp[i-1] + 1);
        }
    }
    if(dp[n] == 0x7fffffff) printf("0\n");
    else printf("%d\n",dp[n]);
    return 0;
}