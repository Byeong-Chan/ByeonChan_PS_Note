#include <cstdio>
char o[220][220];
int chk[220][220];
struct node {
    int x;
    int y;
    void inp(int a, int b) {
        this->x = a;
        this->y = b;
    }
};
node q[41100];
bool visit[41100];
int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};
int main() {
    int i, j, l, n, m, pos;
    int px, py;
    int qt, qh;
    int e = 0;
    int cnt;
    int tx, ty;
    int ans = 0;
    double _in;
    node here, tmp;
    scanf("%d %d %lf",&m,&n,&_in);
    pos = (int)(_in * 2);
    n <<= 1;
    m <<= 1;
    n++;
    m++;
    for(i=0;i<n;i++) scanf("%s",o[i]);
    for (i=0;i<n;i++) {
        for(j=0;j<m;j++) {
            if (chk[i][j]) continue;
            if (o[i][j] == 'B') {
                qt = qh = 0;
                e++;
                chk[i][j] = e;
                tmp.inp(i, j);
                q[qt++] = tmp;
                while (qh < qt) {
                    here = q[qh++];
                    for (l=0;l<4;l++) {
                        tx = here.x + dx[l];
                        ty = here.y + dy[l];
                        if (tx < 0 || tx >= n || ty < 0 || ty >= m) continue;
                        if (chk[tx][ty]) continue;
                        if (o[tx][ty] != 'B' && o[tx][ty] != '.') continue;
                        chk[tx][ty] = e;
                        tmp.inp(tx,ty);
                        q[qt++] = tmp;
                    }
                }
            }
        }
    }
    
    py = -1;
    px = -1;
    
    tx = n-1;
    ty = pos;
    cnt = 0;
    while (1) {
        if (px == -1 && tx == 0) px = 1;
        if (px == 1 && tx == n-1) px = -1;
        if (py == -1 && ty == 0) py = 1;
        if (py == 1 && ty == m-1) py = -1;
        
        if (!(tx & 1)) {
            e = chk[tx + px][ty];
            if (e != 0 && visit[e] == 0) {
                visit[e] = true;
                ans++;
            }
        }
        if (!(ty & 1)) {
            e = chk[tx][ty + py];
            if (e != 0 && visit[e] == 0) {
                visit[e] = true;
                ans++;
            }
        }
        e = chk[tx][ty];
        if (e != 0 && visit[e] == 0) {
            visit[e] = true;
            ans++;
        }
        
        if (tx == n-1) cnt++;
        if (cnt == 2) break;
        tx += px;
        ty += py;
    }
    printf("%d\n",ans);
    return 0;
}