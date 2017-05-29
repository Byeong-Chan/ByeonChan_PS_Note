#include <cstdio>
#include <algorithm>
#include <vector>

using namespace std;

vector<int> p, q;
int dp[410][410], tmp[410][410];
int main() {
    int i, j, k, n;
    int pp;
    int tmp1, tmp2;
    int x;
    int sz1, sz2;
    int ans = -0x7fffffff;
    scanf("%d",&n);
    for(i=0;i<n;i++) {
        scanf("%d",&x);
        if(x != 0) p.push_back(x);
    }
    for(i=0;i<n;i++) {
        scanf("%d",&x);
        if(x != 0) q.push_back(x);
    }
    if(p.size() > q.size()) swap(p, q);
    sz1 = (int)p.size();
    sz2 = (int)q.size();
    pp = sz2 - (n - sz1);
    if(pp < 0) pp = 0;
    if(pp == 0) ans = 0;
    for(k=1;k<=sz1;k++) {
        for(i=0;i<=sz1;i++) {
            for(j=0;j<=sz2;j++) {
                tmp[i][j] = dp[i][j];
                dp[i][j] = -0x7fffffff;
            }
        }
        for(i=1;i<=sz1;i++) {
            for(j=1;j<=sz2;j++) {
                if(tmp[i-1][j-1] == -0x7fffffff) continue;
                dp[i][j] = max(dp[i][j], tmp[i-1][j-1] + p[i-1] * q[j-1]);
            }
        }
        for(i=0;i<=sz1;i++) {
            for(j=0;j<=sz2;j++) {
                if(i-1 >= 0) dp[i][j] = max(dp[i][j], dp[i-1][j]);
                if(j-1 >= 0) dp[i][j] = max(dp[i][j], dp[i][j-1]);
                if(k >= pp) ans = max(ans, dp[i][j]);
            }
        }
    }
    printf("%d\n",ans);
    return 0;
}