#include <cstdio>
#include <algorithm>
using namespace std;
const int INF = 0x7fffffff;
struct node {
    int pos;
    int val;
    bool operator < (const node &a) const {
        return pos < a.pos;
    }
}o[1010];
int tmp[1010][2];
int dp[1010][2];
int hap[1010];
int main() {
    int i, j, n;
    int m;
    int st, ed;
    int sum, s;
    scanf("%d",&n);
    scanf("%d",&m);
    for(i=n;i>0;i--) scanf("%d %d",&o[i].pos,&o[i].val);
    sort(o+1,o+n+1);
    for(i=1;i<=n;i++) {
        hap[i] = o[i].val + hap[i-1];
        dp[i][0] = dp[i][1] = INF;
    }
    sum = hap[n];
    dp[m][0] = dp[m][1] = 0;
    for(i=1;i<n;i++) {
        for(j=n-i+1;j>0;j--) {
            tmp[j][0] = dp[j][0];
            tmp[j][1] = dp[j][1];
            dp[j][0] = dp[j][1] = INF;
        }
        for(st=n-i;st>0;st--) {
            ed = st + i;
            
            s = sum - hap[ed-1] + hap[st-1];
            if(tmp[st][0] != INF) dp[st][1] = min(dp[st][1], tmp[st][0] + (o[ed].pos - o[st].pos) * s);
            if(tmp[st][1] != INF) dp[st][1] = min(dp[st][1], tmp[st][1] + (o[ed].pos - o[ed-1].pos) * s);
            
            s = sum - hap[ed] + hap[st];
            if(tmp[st+1][0] != INF) dp[st][0] = min(dp[st][0], tmp[st+1][0] + (o[st+1].pos - o[st].pos) * s);
            if(tmp[st+1][1] != INF) dp[st][0] = min(dp[st][0], tmp[st+1][1] + (o[ed].pos - o[st].pos) * s);
        }
    }
    printf("%d\n",min(dp[1][0],dp[1][1]));
    return 0;
}