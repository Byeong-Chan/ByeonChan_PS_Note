#include <cstdio>
#include <algorithm>
using namespace std;
int STR[110];
int INT[110];
int dp[110][110];
struct node {
    int x;
    int y;
    int pt;
    bool operator< (const node &a) const {
        int sav1 = this->x < this->y ? this->x : this->y;
        int sav2 = a.x < a.y ? a.x : a.y;
        if(sav1 != sav2) return sav1 < sav2;
        else return this->x < a.x;
    }
}o[110];
int main() {
    int i, j, k, n;
    int m = 0, m2 = 0;
    int cnt, ans = 0;
    int x, y;
    scanf("%d",&n);
    for(i=0;i<n;i++) {
        scanf("%d %d %d",&o[i].x,&o[i].y,&o[i].pt);
        STR[i] = o[i].x;
        INT[i] = o[i].y;
        if(o[i].x == 1 || o[i].y == 1) dp[0][0] += o[i].pt;
    }
    STR[n] = 1;
    STR[n+1] = 0x7fffffff;
    INT[n] = 1;
    INT[n+1] = 0x7fffffff;
    sort(STR, STR+n+1);
    sort(INT, INT+n+1);
    sort(o, o+n);
    for(i=0;i<=n;i++) {
        if (STR[i] == STR[i+1]) continue;
        STR[m++] = STR[i];
    }
    for(i=0;i<=n;i++) {
        if (INT[i] == INT[i+1]) continue;
        INT[m2++] = INT[i];
    }
    int tmp1, tmp2;
    dp[0][0]++;
    for(i=0;i<m;i++) {
        for(j=0;j<m2;j++) {
            if(dp[i][j] <= 1) continue;
            tmp1 = tmp2 = 0;
            for(k=0;k<n;k++) {
                if (j+1 < m2 && STR[i] < o[k].x && INT[j+1] == o[k].y) tmp2 += o[k].pt;
                if (i+1 < m && STR[i+1] == o[k].x && INT[j] < o[k].y) tmp1 += o[k].pt;
            }
            if(i+1 < m && dp[i][j] - STR[i+1] + STR[i] > 0) dp[i+1][j] = dp[i][j] - STR[i+1] + STR[i] + tmp1;
            if(j+1 < m2 && dp[i][j] - INT[j+1] + INT[j] > 0) dp[i][j+1] = dp[i][j] - INT[j+1] + INT[j] + tmp2;
        }
    }
    for(i=0;i<m;i++) {
        for(j=0;j<m2;j++) {
            if(dp[i][j] == 0) continue;
            x = STR[i];
            y = INT[j];
            cnt = 0;
            for(k=0;k<n;k++) if (x >= o[k].x || y >= o[k].y) cnt++;
            if (ans < cnt) ans = cnt;
        }
    }
    printf("%d\n",ans);
    return 0;
}