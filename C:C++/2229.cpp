#include <cstdio>
#include <algorithm>

using namespace std;

int dp[1010];
int sco[1010][1010];
int o[1010];
int main() {
    int i, j;
    int maxx, minx;
    int n;
    scanf("%d",&n);
    for(i=0;i<n;i++) scanf("%d",&o[i]);
    for(i=0;i<n;i++) {
        maxx = minx = o[i];
        for(j=i+1;j<n;j++) {
            minx = min(minx, o[j]);
            maxx = max(maxx, o[j]);
            sco[i][j] = maxx - minx;
        }
    }
    for(i=0;i<n;i++) dp[i] = sco[0][i];
    for(i=0;i<n-1;i++) {
        for(j=i+1;j<n;j++) {
            dp[j] = max(dp[j], dp[i] + sco[i+1][j]);
        }
    }
    printf("%d\n",dp[n-1]);
    return 0;
}