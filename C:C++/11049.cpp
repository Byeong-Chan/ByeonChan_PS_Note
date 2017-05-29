#include <cstdio>
#include <algorithm>
using namespace std;
int dp[510][510];
int o[510][2];
int dfs(int x, int y) {
    if(x == y || dp[x][y]) return dp[x][y];
    int min1 = 0x7fffffff;
    for(int i=x;i<y;i++) min1 = min(min1, dfs(x, i) + dfs(i+1, y) + o[x][0] * o[i+1][0] * o[y][1]);
    return dp[x][y] = min1;
}
int main() {
    int i, n;
    scanf("%d",&n);
    for(i=0;i<n;i++) scanf("%d %d",o[i],o[i]+1);
    printf("%d\n",dfs(0, n-1));
    return 0;
}