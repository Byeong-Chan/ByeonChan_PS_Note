#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

int N;
vector<long long> sum, o;

void init(int n) {
    N = n + 1;
    o. clear();
    sum.clear();
    o.resize(n + 2);
    sum.resize(n + 2);
}
void add(int i, long long val) {
    while(i <= N) {
        sum[i] += val;
        i += (i & (-i));
    }
}

long long query(int i) {
    long long ans = 0;
    while(i) {
        ans += sum[i];
        i -= (i & (-i));
    }
    return ans;
}

int main() {
    char q;
    int i, n, m;
    int x, y;
    while(scanf("%d %d\n",&n,&m) == 2) {
        init(n);
        for(i=1;i<=n;i++) {
            scanf("%d",&x);
            o[i] = 0;
            if(x < 0) {
                o[i] = 1;
                add(i, o[i]);
            }
            else if(x == 0) {
                o[i] = -100000;
                add(i, o[i]);
            }
        }
        for(i=0;i<m;i++) {
            scanf("\n%c",&q);
            scanf("%d %d",&x,&y);
            if(q == 'C') {
                add(x, -o[x]);
                o[x] = 0;
                if(y < 0) o[x] = 1;
                else if(y == 0) o[x] = -100000;
                add(x, o[x]);
            }
            else {
                long long tmp = query(y) - query(x - 1);
                if(tmp < 0) printf("0");
                else if(tmp & 1) printf("-");
                else printf("+");
            }
        }
        printf("\n");
    }
    return 0;
}