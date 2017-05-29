#include <cstdio>
#include <algorithm>
#include <map>
using namespace std;
int seg[3100000];
int k;
void init(int n) {
    for(k=1;k<n;k<<=1);
    for(int i=0;i<k*2;i++) seg[i] = 0;
}
void single_update(int d, int val) {
    d += k;
    while(d > 0) {
        seg[d] += val;
        d >>= 1;
    }
}
int range_query(int st, int ed) {
    int ans = 0;
    st += k;
    ed += k;
    while(1) {
        if(st == ed) {
            ans += seg[st];
            break;
        }
        if(st & 1) {
            ans += seg[st];
            st++;
        }
        if(!(ed & 1)) {
            ans += seg[ed];
            ed--;
        }
        if(st > ed) break;
        st >>= 1;
        ed >>= 1;
    }
    return ans;
}
map<int, int> tx;
int main() {
    int i, n;
    int x;
    int tmp;
    long long ans = 0;
    scanf("%d",&n);
    for(i=0;i<n;i++) {
        scanf("%d",&x);
        tx[x] = i + 1;
    }
    init(n);
    for(i=0;i<n;i++) {
        scanf("%d",&x);
        tmp = tx[x] - 1;
        if(tmp == -1) continue;
        if(tmp < n) ans += range_query(tmp, n - 1);
        single_update(tmp, 1);
    }
    printf("%lld\n",ans);
    return 0;
}