#include <cstdio>
#include <algorithm>
using namespace std;
struct node {
    int pos;
    int cst;
    bool operator< (const node &a) const {
        return this->cst < a.cst;
    }
}o[510];
int dt[510][510];
int ans[510][510];
int cstset[510];
int main() {
    int n, m, Q;
    int i, j, k;
    int x, y, z;
    int tmp1, tmp2;
    scanf("%d %d %d",&n,&m,&Q);
    for (i=0;i<n;i++) {
        scanf("%d",&o[i].cst);
        o[i].pos = i + 1;
        cstset[i+1] = o[i].cst;
    }
    sort(o,o+n);
    for(i=0;i<m;i++) {
        scanf("%d %d %d",&x,&y,&z);
        dt[x][y] = z;
        dt[y][x] = z;
        ans[y][x] = ans[x][y] = dt[x][y] + max(cstset[x], cstset[y]);
    }
    for(i=0;i<n;i++) {
        for(j=0;j<n;j++) {
            if (i == j) continue;
            for(k=0;k<n;k++) {
                if (i == k || j == k) continue;
                x = o[i].pos;
                y = o[j].pos;
                z = o[k].pos;
                if (dt[y][x] == 0 || dt[x][z] == 0) continue;
                
                tmp1 = dt[y][x] + dt[x][z];
                tmp2 = max(o[i].cst, max(o[j].cst, o[k].cst));
                if (dt[y][z] == 0 || dt[y][z] > tmp1) dt[y][z] = tmp1;
                if (ans[y][z] == 0 || ans[y][z] > tmp1 + tmp2) ans[y][z] = tmp1 + tmp2;
            }
        }
    }
    for(i=0;i<Q;i++) {
        scanf("%d %d",&x,&y);
        if (ans[x][y] == 0) printf("-1\n");
        else printf("%d\n",ans[x][y]);
    }
    return 0;
}