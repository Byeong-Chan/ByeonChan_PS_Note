#include <cstdio>
#include <algorithm>
using namespace std;
int p[10030];
struct node {
    int x;
    int y;
    int r;
    bool operator< (const node &a) const {
        return r > a.r;
    }
}o[310];
int dx[610];
int dp[610][610];
int main() {
    int t;
    int i, j, k, l, n, m;
    int st, ed, val;
    scanf("%d",&t);
    while(t--) {
        scanf("%d",&n);
        for(i=0;i<n;i++) {
            scanf("%d %d %d",&o[i].x,&o[i].y, &o[i].r);
            dx[i*2] = o[i].x;
            dx[i*2+1] = o[i].y;
        }
        
        dx[n*2] = 0;
        dx[n*2+1] = 10010;
        sort(dx, dx+n*2+2);
        sort(o, o+n);
        
        m = (int)(unique(dx, dx+n*2+2) - dx);
        for(i=0;i<m;i++) {
            p[dx[i]] = i;
            for(j=0;j<m;j++) dp[i][j] = 0;
        }

        for(k=1;k<m;k++) {
            for(i=0;i+k<m;i++) {
                j = i + k;
                for(l=0;l<n;l++) if(o[l].x > dx[i] && o[l].y < dx[j]) break;
                if(l == n) {
                    dp[i][j] = 0;
                    continue;
                }
                st = p[o[l].x];
                ed = p[o[l].y];
                val = o[l].r;
                
                dp[i][j] = 1000000000;
                if(st == i) st++;
                for(;st<=ed && st<j;st++) dp[i][j] = min(dp[i][j], dp[i][st] + dp[st][j] + val);
            }
        }
        
        printf("%d\n",dp[0][m-1]);
    }
    return 0;
}