#include <cstdio>
#include <algorithm>
using namespace std;
struct node {
    int x;
    int i;
    bool operator < (const node &a) const {
        return x < a.x;
    }
}u[100010];
int o[100010];
bool ans[100010];
int main() {
    int i, n;
    int m;
    int l = 0, r = 0;
    scanf("%d",&n);
    for(i=0;i<n;i++) scanf("%d",&o[i]);
    scanf("%d",&m);
    for(i=0;i<m;i++) {
        scanf("%d",&u[i].x);
        u[i].i = i;
    }
    sort(o, o+n);
    sort(u, u+m);
    while(l < n || r < m) {
        if(r == m) {
            l++;
            continue;
        }
        else if(l == n) {
            r++;
            continue;
        }
        
        if(o[l] < u[r].x) l++;
        else if(o[l] > u[r].x) r++;
        else {
            ans[u[r].i] = true;
            r++;
        }
    }
    for(i=0;i<m;i++) printf("%d\n",ans[i]);
    return 0;
}