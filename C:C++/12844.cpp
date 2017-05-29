#include <cstdio>
#include <algorithm>

using namespace std;

int N;
int sum[500010];
int mul[500010];
void init(int n) {
    N = n;
    for(int i=1;i<=n;i++) sum[i] = mul[i] = 0;
}

void update(int i, int val1, int val2) {
    while(i <= N) {
        sum[i] ^= val1;
        mul[i] ^= val2;
        i += (i & (-i));
    }
}

void range_xor(int x, int y, int val) {
    int tmp1 = ((x - 1) & 1) ? val : 0, tmp2 = (y & 1) ? val : 0;
    update(x, val, tmp1);
    update(y, val, tmp2);
}

int query(int i) {
    bool sw = i & 1;
    int ans1 = 0, ans2 = 0;
    while(i > 0) {
        ans1 ^= sum[i];
        ans2 ^= mul[i];
        i -= (i & (-i));
    }
    ans1 ^= (sw ? 0 : ans1);
    return ans1 ^ ans2;
}
int main() {
    int i, x, y, z, n, m;
    int qu;
    scanf("%d",&n);
    init(n);
    for(i=1;i<=n;i++) {
        scanf("%d",&x);
        range_xor(i, i, x);
    }
    scanf("%d",&m);
    while(m--) {
        scanf("%d",&qu);
        if(qu == 1) {
            scanf("%d %d %d",&x,&y,&z);
            if(x > y) swap(x, y);
            range_xor(x+1, y+1, z);
        }
        else {
            scanf("%d %d",&x,&y);
            if(x > y) swap(x, y);
            printf("%d\n",query(x) ^ query(y+1));
        }
    }
    return 0;
}