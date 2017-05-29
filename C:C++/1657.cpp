#include <cstdio>
#include <algorithm>

using namespace std;

char o[16][16];
int dp[1<<14], tmp[1<<14];
int sc[256][256];

int main() {
    int i, j, k, n, m;
    int len;
    int ans = 0;
    int nxt;
    int x, y;
    int sav;
    
    scanf("%d %d",&n, &m);
    len = (1 << m);
    
    
    sc['A']['A'] = 10;
    sc['A']['B'] = sc['B']['A'] = 8;
    sc['B']['B'] = 6;
    sc['A']['C'] = sc['C']['A'] = 7;
    sc['B']['C'] = sc['C']['B'] = 4;
    sc['C']['C'] = 3;
    sc['A']['D'] = sc['D']['A'] = 5;
    sc['B']['D'] = sc['D']['B'] = 3;
    sc['C']['D'] = sc['D']['C'] = 2;
    sc['D']['D'] = 2;
    for(i=(int)'A'; i <= (int)'D'; i++) sc[i]['F'] = sc['F'][i] = 1;
    int maxd;
    scanf("%d %d",&n,&m);
    for(i=0;i<n;i++) scanf("%s",o[i]);
    k = 1 << (m-1);
    maxd = (1 << m) - 1;
    
    dp[maxd] = 0;
    int M = n * m;
    for(i=0;i<M;i++) {
        for(j=(1<<m)-1;j>=0;j--) {
            tmp[j] = dp[j];
            dp[j] = 0;
        }
        for(j=(1<<m)-1;j>=0;j--) {
            x = i / m;
            y = i % m;
            nxt = j >> 1;
            
            sav = 0;
            if(x-1 >= 0) sav = sc[o[x][y]][o[x-1][y]];
            if((j & 1) == 0) dp[nxt + k] = max(dp[nxt + k], tmp[j] + sav);
            
            sav = 0;
            if(y-1 >= 0) sav = sc[o[x][y]][o[x][y-1]];
            if((j & (1 << (m-1))) == 0) dp[nxt + k + (k >> 1)] = max(dp[nxt + k + (k >> 1)], tmp[j] + sav);
            
            dp[nxt] = max(dp[nxt], tmp[j]);
        }
        for(j=(1<<m)-1;j>=0;j--) if(dp[j] > ans) ans = dp[j];
    }
    printf("%d\n",ans);
    return 0;
}