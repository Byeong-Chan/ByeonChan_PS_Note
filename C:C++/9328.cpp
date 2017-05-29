#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;
char o[110][110];
struct node {
    int x;
    int y;
    void inp(int a, int b) {
        this->x = a;
        this->y = b;
    }
};
vector<node> p[28];
node q[11010];
bool chk[28];
bool visit[110][110];
char s[110];
int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};
int main() {
    int i, j, n, m;
    int qh, qt;
    int tx, ty;
    int go;
    int ans;
    int t;
    node here, tmp;
    scanf("%d",&t);
    while (t--) {
        scanf("%d %d",&n,&m);
        for(i=1;i<=n;i++) scanf("%s",o[i] + 1);
        scanf("%s",s);
        if (s[0] != '0') for(char *k = s; *k != '\0'; k++) chk[*k - 'a'] = true;
        n+=2;
        m+=2;
        for (i=0;i<n;i++) {
            for(j=0;j<m;j++) {
                if (o[i][j] == 0) o[i][j] = '.';
            }
        }
        
        ans = 0;
        tmp.inp(0, 0);
        qh = qt = 0;
        q[qt++] = tmp;
        visit[0][0] = true;
        while (qh < qt) {
            here = q[qh++];
            if (o[here.x][here.y] == '$') ans++;
            for(i=0;i<4;i++) {
                tx = here.x + dx[i];
                ty = here.y + dy[i];
                if (tx < 0 || tx >= n || ty < 0 || ty >= m) continue;
                if (o[tx][ty] == '*') continue;
                if (visit[tx][ty]) continue;
                if (o[tx][ty] >= 'a' && o[tx][ty] <= 'z') {
                    go = o[tx][ty] - 'a';
                    if (!chk[go]) {
                        for (j=0;j<p[go].size();j++) {
                            tmp = p[go][j];
                            q[qt++] = tmp;
                        }
                        chk[go] = true;
                    }
                }
                if (o[tx][ty] >= 'A' && o[tx][ty] <= 'Z') {
                    go = o[tx][ty] - 'A';
                    if (!chk[go]) {
                        visit[tx][ty] = true;
                        tmp.inp(tx, ty);
                        p[go].push_back(tmp);
                        continue;
                    }
                }
                visit[tx][ty] = true;
                tmp.inp(tx, ty);
                q[qt++] = tmp;
            }
        }
        printf("%d\n",ans);
        for (i=0;i<n;i++) {
            for(j=0;j<m;j++) {
                visit[i][j] = false;
                o[i][j] = '\0';
            }
        }
        for (i=0;i<26;i++) chk[i] = 0, p[i].clear();
        for (char *k = s; *k != '\0'; k++) *k = '\0';
    }
    return 0;
}