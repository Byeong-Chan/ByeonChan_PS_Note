#include <cstdio>
#include <algorithm>
using namespace std;
char o[53][53];
int at[53][53];
int num[2503];
int dx[8] = {1, -1, 0, 0, 1, -1, 1, -1};
int dy[8] = {0, 0, 1, -1, 1, 1, -1, -1};
int chk[53][53];
pair<int, int> q[2503];
int main() {
    int k, i, j, l, n;
    int e = 0;
    int qh, qt;
    int cnt;
    int st, ed, mid;
    int all = 0;
    int stx = 0, sty = 0;
    int rat, lat;
    int tx, ty;
    int pp = 0;
    bool sw;
    pair<int, int> here;
    scanf("%d",&n);
    for(i=0;i<n;i++) scanf("%s",o[i]);
    for(i=0;i<n;i++) {
        for(j=0;j<n;j++) {
            scanf("%d",&at[i][j]);
            num[e++] = at[i][j];
            if (o[i][j] == 'P') {
                stx = i;
                sty = j;
            }
            if (o[i][j] == 'K') all++;
        }
    }
    num[e] = 0x7fffffff;
    sort(num, num+e);
    st = 0;
    ed = 1000000;
    while (st < ed) {
        mid = (st + ed) >> 1;
        sw = false;
        for(k=0;k<e;k++) {
            if (num[k] == num[k+1]) continue;
            lat = num[k];
            rat = num[k] + mid;
            if (at[stx][sty] < lat || at[stx][sty] > rat) continue;
            cnt = 0;
            qh = qt = 0;
            q[qt++] = make_pair(stx, sty);
            chk[stx][sty] = ++pp;
            while (qh < qt) {
                here = q[qh++];
                if (o[here.first][here.second] == 'K') cnt++;
                for(l=0;l<8;l++) {
                    tx = here.first + dx[l];
                    ty = here.second + dy[l];
                    if (tx < 0 || ty < 0 || tx >= n || ty >= n) continue;
                    if (chk[tx][ty] == pp) continue;
                    if (at[tx][ty] < lat || at[tx][ty] > rat) continue;
                    chk[tx][ty] = pp;
                    q[qt++] = make_pair(tx, ty);
                }
            }
            if (cnt == all) {
                sw = true;
                break;
            }
        }
        
        if (sw) ed = mid;
        else st = mid + 1;
    }
    printf("%d\n",st);
    return 0;
}