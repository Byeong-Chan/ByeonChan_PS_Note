#include <cstdio>
#include <algorithm>
using namespace std;
int table[2010];
struct node {
    int x;
    int y;
    int val;
    bool operator < (const node &a) const {
        return y < a.y;
    }
};
node o[10010];
int main() {
    int i, j, n;
    int cap, m;
    int ans = 0;
    int maxx;
    scanf("%d %d",&n,&cap);
    scanf("%d",&m);
    for(i=0;i<m;i++) scanf("%d %d %d",&o[i].x,&o[i].y,&o[i].val);
    sort(o,o+m);
    for(i=0;i<m;i++) {
        maxx = 0;
        for(j=o[i].x;j<o[i].y;j++) if(table[j] > maxx) maxx = table[j];
        int tmp = min(cap - maxx, o[i].val);
        ans += tmp;
        for(j=o[i].x;j<o[i].y;j++) table[j] += tmp;
    }
    printf("%d\n",ans);
    return 0;
}