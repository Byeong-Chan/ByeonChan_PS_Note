#include <cstdio>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;
int o[3010];
vector<int> color[3010];
int nodecolor[3010];
bool chk[3010];
int p[3010];
int main() {
    int i, j, n, m;
    int x, y;
    int a, b;
    int k;
    int sav, cnt = 0;
    scanf("%d %d", &n, &m);
    for (i=1;i<=n;i++) {
        nodecolor[i] = i;
        color[i].push_back(i);
    }
    for (i=0;i<m;i++) {
        scanf ("%d %d",&a,&b);
        if (b < a) {
            for(j=b;j<a;j++) {
                x = nodecolor[j];
                y = nodecolor[j+1];
                if (x != y) {
                    if (color[x].size() < color[y].size()) {
                        while (color[x].size()) {
                            sav = color[x].back();
                            color[x].pop_back();
                            nodecolor[sav] = y;
                            color[y].push_back(sav);
                        }
                    }
                    else {
                        while (color[y].size()) {
                            sav = color[y].back();
                            color[y].pop_back();
                            nodecolor[sav] = x;
                            color[x].push_back(sav);
                        }
                    }
                }
            }
        }
    }
    for (i=1;i<=n;i++) {
        x = nodecolor[i];
        if (chk[x]) continue;
        chk[x] = true;
        p[cnt++] = (int)color[x].size();
    }
    for(i=1;i<=n;i++) {
        if (n % i == 0) {
            k = 0;
            for(j=0;j<cnt;j++) {
                k += p[j];
                if (k > i) break;
                if (k == i) k = 0;
            }
            if (j == cnt) {
                printf("%d",n/i);
                break;
            }
        }
    }
    return 0;
}