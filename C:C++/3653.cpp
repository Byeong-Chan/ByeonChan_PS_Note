#include <cstdio>

int sum[200010];
int cnt[200010];
int N;

void init(int n, int m) {
    N = n + m;
    for(int i=1;i<=N;i++) sum[i] = 0;
}

void update(int i, int val) {
    while(i <= N) {
        sum[i] += val;
        i += (i & (-i));
    }
}

int query(int i) {
    int ans = 0;
    while(i > 0) {
        ans += sum[i];
        i -= (i & (-i));
    }
    return ans;
}

int main() {
    int t;
    int i, n, m, x;
    scanf("%d",&t);
    while(t--) {
        scanf("%d %d",&n,&m);
        init(n, m);
        for(i=1;i<=n;i++) {
            update(i, 1);
            cnt[i] = n - i + 1;
        }
        for(i=0;i<m;i++) {
            scanf("%d",&x);
            printf("%d ",query(n) - query(cnt[x]));
            update(cnt[x], -1);
            cnt[x] = ++n;
            update(cnt[x], 1);
        }
        printf("\n");
    }
    return 0;
}