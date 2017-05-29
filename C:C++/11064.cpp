#include <cstdio>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
int moth[40010];
int mcst[40010];
int son[40010];
double dia[40010];
bool chk[40010];
vector<int> edge[40010];
vector<int> ecst[40010];
void dfs(int u) {
    int v;
    chk[u] = true;
    for(int i = 0; i < edge[u].size(); i++) {
        v = edge[u][i];
        if (chk[v]) continue;
        mcst[v] = ecst[u][i];
        moth[v] = u;
        son[u]++;
        dfs(v);
    }
}
void init(int n) {
    int i;
    for(i=1;i<=n;i++) {
        edge[i].clear();
        ecst[i].clear();
        chk[i] = false;
        dia[i] = -1;
    }
}
double bfs(int n, int D) {
    int i;
    int here, nxt;
    double hereD;
    double ans = 0;
    double half = (double)D / 2;
    queue<int> q;
    for(i=1;i<=n;i++) if(son[i] == 0) q.push(i), dia[i] = 0;
    while(1) {
        here = q.front();
        q.pop();
        if (here == 1) break;
        nxt = moth[here];
        if (--son[nxt] == 0) q.push(nxt);
        
        hereD = dia[here] + mcst[here];
        if (dia[nxt] == -1) {
            if (hereD > D) {
                ans += hereD - D;
                dia[nxt] = D;
            }
            else dia[nxt] = hereD;
        }
        else {
            if(dia[nxt] + hereD > D) {
                if (dia[nxt] * 2 >= D && hereD * 2 >= D) {
                    ans += (double)dia[nxt] - half;
                    ans += (double)hereD - half;
                    dia[nxt] = half;
                }
                else {
                    if (dia[nxt] < hereD) {
                        ans += hereD - D + dia[nxt];
                        dia[nxt] = D - dia[nxt];
                    }
                    else {
                        ans += dia[nxt] - D + hereD;
                        dia[nxt] = D - hereD;
                    }
                }
            }
            else if (hereD > dia[nxt]) dia[nxt] = hereD;
        }
    }
    return ans;
}
int main() {
    int i, t;
    int n, D;
    int x, y, z;
    for(scanf("%d",&t);t--;) {
        scanf("%d %d",&n,&D);
        init(n);
        for(i=0;i<n-1;i++) {
            scanf("%d %d %d",&x,&y,&z);
            edge[x].push_back(y);
            ecst[x].push_back(z);
            edge[y].push_back(x);
            ecst[y].push_back(z);
        }
        dfs(1);
        printf("%.1lf\n",bfs(n, D));
    }
    return 0;
}