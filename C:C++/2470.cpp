#include <cstdio>
#include <algorithm>
using namespace std;
int o[100010];
int n;
int dist(int x, int y) {
    if(x >= n || y >= n || x < 0 || y < 0 || x == y) return 0x7fffffff;
    return o[x] + o[y] < 0 ? - o[y] - o[x] : o[x] + o[y];
}
int main() {
    int i;
    int d;
    int tmp;
    int l, r;
    int ans = 0x7fffffff;
    int x = 0, y = 0x7fffffff;
    scanf("%d",&n);
    for(i=0;i<n;i++) scanf("%d",&o[i]);
    sort(o, o+n);
    for(i=0;i<n;i++) {
        d = -o[i];
        l = 0;
        r = n;
        while(l < r) {
            int mid = (l + r) >> 1;
            if(o[mid] < d) l = mid + 1;
            else r = mid;
        }
        tmp = dist(i, l);
        if(tmp < ans) {
            ans = tmp;
            x = o[i];
            y = o[l];
        }
        
        tmp = dist(i, l - 1);
        if(tmp < ans) {
            ans = tmp;
            x = o[i];
            y = o[l - 1];
        }
        
        tmp = dist(i, l + 1);
        if(tmp < ans) {
            ans = tmp;
            x = o[i];
            y = o[l + 1];
        }
    }
    if(x > y) swap(x, y);
    printf("%d %d\n",x,y);
    return 0;
}