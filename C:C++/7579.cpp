#include <cstdio>
#include <algorithm>
using namespace std;
int c[110], m[110], dp[10110];
int main() {
    int i, j, N, M;
    scanf("%d %d",&N, &M);
    for(i=0;i<N;i++) scanf("%d",&m[i]);
    for(i=0;i<N;i++) scanf("%d",&c[i]);
    for(i=0;i<N;i++) for(j=10000;j>=0;j--) dp[j+c[i]] = max(dp[j+c[i]], dp[j] + m[i]);
    for(i=0;i<=10000;i++) if(dp[i] >= M) break;
    printf("%d\n",i);
    return 0;
}