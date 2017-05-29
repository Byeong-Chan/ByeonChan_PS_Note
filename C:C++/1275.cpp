#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

int N;
long long sum[1000100], o[1000100];

void init(int n) {
    N = n + 1;
}
void add(int i, long long val) {
    while (i < N) {
        sum[i] += val;
        i += (i & (-i));
    }
}

long long query(int i) {
    long long ans = 0;
    while (i) {
        ans += sum[i];
        i -= (i & (-i));
    }
    return ans;
}

int main() {
    int i;
    int n, m;
    int x, y, a;
    long long b;
    scanf("%d %d",&n,&m);
    init(n);
    for(i=1;i<=n;i++) {
        scanf("%lld",&o[i]);
        add(i, o[i]);
    }
    for(i=0;i<m;i++) {
        scanf("%d %d %d %lld",&x,&y,&a,&b);
        if(x > y) swap(x, y);
        printf("%lld\n",query(y) - query(x-1));
        
        add(a, -o[a]);
        add(a, b);
        o[a] = b;
    }
    return 0;
}