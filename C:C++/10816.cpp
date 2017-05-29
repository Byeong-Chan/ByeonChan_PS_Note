#include <cstdio>
#include <algorithm>
using namespace std;
int o[500010];
int lb(int l, int r, int val) {
    int mid;
    while(l <= r) {
        mid = (l + r) >> 1;
        if(o[mid] < val) l = mid + 1;
        else r = mid - 1;
    }
    return l;
}
int ub(int l, int r, int val) {
    int mid;
    while(l <= r) {
        mid = (l + r) >> 1;
        if(o[mid] <= val) l = mid + 1;
        else r = mid - 1;
    }
    return l;
}
int main() {
    int i, n,m;
    int x;
    scanf("%d",&n);
    for(i=0;i<n;i++) {
        scanf("%d",&o[i]);
    }
    sort(o, o+n);
    scanf("%d",&m);
    for(i=0;i<m;i++) {
        scanf("%d",&x);
        printf("%d ",ub(0,n-1,x) - lb(0,n-1,x));
    }
    printf("\n");
    return 0;
}