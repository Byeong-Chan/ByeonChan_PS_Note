#include <cstdio>
#include <algorithm>
using namespace std;
int N;
int bit[500010];
int o[500010];
int dx[500010];
void init(int n) {
    N = n + 1;
    for(int i=1;i<=n;i++) bit[i] = 0;
}
void update(int i, int val) {
    while(i < N) {
        bit[i] += val;
        i += i & (-i);
    }
}
int query(int i) {
    int ans = 0;
    while(i > 0) {
        ans += bit[i];
        i -= i & (-i);
    }
    return ans;
}
int lb(int l, int r, int val) {
    int mid;
    while(l <= r) {
        mid = (l+r) >> 1;
        if(val <= dx[mid]) r = mid - 1;
        else l = mid + 1;
    }
    return l + 1;
}
int main() {
    int i, n;
    int m;
    int x;
    scanf("%d",&n);
    for(i=0;i<n;i++) {
        scanf("%d",&o[i]);
        dx[i] = o[i];
    }
    sort(dx, dx+n);
    m = (int)(unique(dx, dx+n) - dx);
    init(m);
    for(i=0;i<n;i++) {
        x = lb(0, m - 1, o[i]);
        printf("%d\n",query(m)-query(x)+1);
        update(x, 1);
    }
    return 0;
}