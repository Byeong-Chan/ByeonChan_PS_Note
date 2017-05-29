#include <cstdio>
#include <algorithm>
using namespace std;
struct bung {
    int h;
    int d;
    bool operator< (const bung &a) const {
        return this->h < a.h;
    }
}o[200010];
int chk[200010];
int main() {
    int i, j, n, m, h;
    int sum = 0;
    scanf("%d %d",&n,&m);
    for(i=0;i<n;i++) {
        scanf("%d",&h);
        o[i].h = h;
        o[i].d = -1;
        sum++;
        if (i & 1) {
            o[i].h = m-h;
            o[i].d = 1;
            sum--;
        }
    }
    chk[sum]++;
    sort(o, o+n);
    j = 0;
    for(i=1;i<m;i++) {
        for(;j<n;j++) {
            if (o[j].h == i) sum += o[j].d;
            else break;
        }
        chk[sum]++;
    }
    for(i=0;i<=n;i++) {
        if(chk[i] != 0) {
            printf("%d %d\n",i,chk[i]);
            break;
        }
    }
    return 0;
}