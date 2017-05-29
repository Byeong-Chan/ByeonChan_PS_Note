#include <cstdio>
#include <algorithm>

using namespace std;

int N;
long long sum[1000010];
long long mul[1000010];

void init(int n) {
    N = n;
    for(int i=1;i<=n;i++) {
        sum[i] = 0;
        mul[i] = 0;
    }
}

void update(int i, long long val1, long long val2) {
    while(i <= N) {
        sum[i] += val1;
        mul[i] += val2;
        i += (i & (-i));
    }
}

void range_update(int l, int r, long long val) {
    update(l, val, -val * (l-1));
    update(r, -val, val * r);
}

long long query(int i) {
    long long ans = 0;
    long long hap = 0;
    int tmp = i;
    while(i > 0) {
        ans += sum[i];
        hap += mul[i];
        i -= (i & (-i));
    }
    return ans * tmp + hap;
}

int main() {
    int i, n;
    int q1, q2, q;
    int x, y, z;
    scanf("%d %d %d",&n, &q1, &q2);
    init(n);
    for(i=1;i<=n;i++) {
        scanf("%d",&z);
        range_update(i, i, (long long)z);
    }
    for(i=q1+q2;i>0;i--) {
        scanf("%d",&q);
        if(q == 1) {
            scanf("%d %d %d",&x,&y,&z);
            if(x > y) swap(x, y);
            range_update(x, y, (long long)z);
        }
        else {
            scanf("%d %d",&x,&y);
            if(x > y) swap(x, y);
            printf("%lld\n",query(y) - query(x-1));
        }
    }
    return 0;
}