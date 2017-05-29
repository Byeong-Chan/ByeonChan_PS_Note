#include <cstdio>
#include <algorithm>
using namespace std;
char o[1010];
int dp[1010];
int main() {
    int i, j, n;
    scanf("%d",&n);
    scanf("%s",o);
    for(i=1;i<n;i++) dp[i] = 1087654321;
    for(i=0;i<n;i++) {
        for(j=i+1;j<n;j++) {
            if(o[i] == 'B' && o[j] == 'O') dp[j] = min(dp[j], dp[i] + (j-i) * (j-i));
            if(o[i] == 'O' && o[j] == 'J') dp[j] = min(dp[j], dp[i] + (j-i) * (j-i));
            if(o[i] == 'J' && o[j] == 'B') dp[j] = min(dp[j], dp[i] + (j-i) * (j-i));
        }
    }
    if(dp[n-1] >= 1087654321) printf("-1\n");
    else printf("%d\n",dp[n-1]);
    return 0;
}