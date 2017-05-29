#include <cstdio>
#include <algorithm>
using namespace std;
int o[200010];
int u[400010];
int fail[200010];
void make_fail(int n) {
    int i = -2, j = -1;
    while(j < n) {
        if(i < 0 || (i >= 0 && o[i] == o[j])) fail[++j] = ++i;
        else i = fail[i];
    }
}
int main() {
    int i, j, n, m;
    scanf("%d",&n);
    for(i=0;i<n;i++) scanf("%d",&o[i]);
    for(i=0;i<n;i++) scanf("%d",&u[i]);
    sort(o, o+n);
    sort(u, u+n);
    m = (n << 1) - 1;
    for(i=n;i<m;i++) u[i] = u[i-n];
    for(i=1;i<n;i++) o[i-1] = o[i] - o[i-1];
    for(i=1;i<m;i++) {
        u[i-1] = u[i] - u[i-1];
        if(u[i-1] < 0) u[i-1] += 360000;
    }
    n--;
    m--;
    make_fail(n);
    i = 0;
    j = 0;
    o[n] = -1;
    while(j<m) {
        if(i < 0 || (i >= 0 && o[i] == u[j])) {
            i++;
            j++;
        }
        else i = fail[i];
        if(i == n) {
            printf("possible\n");
            return 0;
        }
    }
    if(i == n) printf("possible\n");
    else printf("impossible\n");
    return 0;
}