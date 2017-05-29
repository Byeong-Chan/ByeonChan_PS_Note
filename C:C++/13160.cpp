#include <cstdio>
#include <map>
#include <algorithm>
using namespace std;
struct bung {
    int x;
    int y;
}o[3000100];
map<int, int> t;
int p[6000100];
int table[6000100];
int main() {
    int i, n, m = 0;
    int k = 0;
    int ans, tmp;
    scanf("%d",&n);
    for(i=0;i<n;i++) {
        scanf("%d %d",&o[i].x,&o[i].y);
        o[i].x--;
        p[m++] = o[i].x;
        p[m++] = o[i].y;
    }
    sort(p, p+m);
    for (i=0;i<m;i++) if (t[p[i]] == 0) t[p[i]] = ++k;
    for(i=0;i<n;i++) {
        o[i].x = t[o[i].x];
        o[i].y = t[o[i].y];
        table[o[i].x]++;
        table[o[i].y]--;
    }
    tmp = ans = 0;
    for(i=1;i<=m;i++) {
        table[i] += table[i-1];
        if (table[i] > ans) {
            ans = table[i];
            tmp = i;
        }
    }
    printf("%d\n",ans);
    for(i=0;i<n;i++) {
        if (o[i].x <= tmp && o[i].y > tmp) printf("%d ", i+1);
    }
    printf("\n");
    return 0;
}