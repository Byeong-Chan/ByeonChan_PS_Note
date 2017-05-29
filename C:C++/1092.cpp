#include <cstdio>
#include <algorithm>
using namespace std;
int d[52];
int o[10010];
int sav[52];
int main() {
    int i, j, n;
    int m;
    int sum;
    int st, ed, mid;
    scanf("%d",&n);
    for(i=0;i<n;i++) scanf("%d",&d[i]);
    sort(d, d+n);
    scanf("%d",&m);
    for(i=0;i<m;i++) scanf("%d",&o[i]);
    sort(o, o+m);
    for(i=0;i<n;i++) {
        for(j=0;j<m && o[j] <= d[i];j++);
        sav[i] = j;
    }
    if(sav[n-1] < m) {
        printf("-1\n");
        return 0;
    }
    st = 1;
    ed = m;
    while(st < ed) {
        sum = 0;
        mid = (st + ed) >> 1;
        for(i=n-1;i>=0;i--) {
            if(m-sum <= sav[i]) sum += mid;
            if(sum >= m) break;
        }
        if(sum >= m) ed = mid;
        else st = mid + 1;
    }
    printf("%d\n",st);
    return 0;
}