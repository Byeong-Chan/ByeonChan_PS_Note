#include <cstdio>
int o[5010];
int main() {
    int i, n, m;
    int st, ed, mid;
    scanf("%d %d",&n,&m);
    for(i=0;i<n;i++) scanf("%d",&o[i]);
    st = 0;
    ed = 10000;
    while(st <= ed) {
        mid = (st + ed) >> 1;
        int min1 = o[0];
        int max1 = o[0];
        int cnt = 1;
        for(i=1;i<n;i++) {
            if(min1 > o[i]) min1 = o[i];
            if(max1 < o[i]) max1 = o[i];
            if(max1 - min1 > mid) {
                cnt++;
                max1 = o[i];
                min1 = o[i];
            }
        }
        if(cnt <= m) ed = mid - 1;
        else st = mid + 1;
    }
    printf("%d\n",st);
    return 0;
}