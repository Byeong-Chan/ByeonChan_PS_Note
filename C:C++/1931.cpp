#include <cstdio>
#include <algorithm>
using namespace std;
struct bung {
    int x;
    int y;
}o[100010];
bool cmp(bung a,bung b) {
    if(a.y != b.y) return a.y < b.y;
    return a.x < b.x;
}
int main() {
    int i, n;
    int d = -0x7fffffff;
    int ans = 0;
    scanf("%d",&n);
    for(i=0;i<n;i++) {
        scanf("%lld %lld",&o[i].x,&o[i].y);
    }
    sort(o, o+n, cmp);
    for(i=0;i<n;i++) {
        if(d <= o[i].x) {
            d = o[i].y;
            ans++;
        }
    }
    printf("%d",ans);
    return 0;
}