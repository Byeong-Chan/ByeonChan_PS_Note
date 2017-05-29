#include <cstdio>
#include <algorithm>
using namespace std;
const int BLOCK_SIZE = 750;
struct bung {
    int l;
    int r;
    int order;
    bool operator< (const bung &a) const {
        if (this->l / BLOCK_SIZE != a.l / BLOCK_SIZE) return this->l / BLOCK_SIZE < a.l / BLOCK_SIZE;
        return this->r < a.r;
    }
}q[100010];
int p[1000010];
int o[100010];
long long ans[100010];
int main() {
    int i, j;
    int n, Q;
    int mo_left = 0, mo_right = -1;
    long long hap = 0;
    long long tmp, tmp2;
    bung tmpq;
    scanf("%d %d", &n, &Q);
    for (i = 0; i < n; i++) scanf("%d", &o[i]);
    for (i = 0; i < Q; i++) {
        scanf("%d %d", &q[i].l, &q[i].r);
        q[i].l--;
        q[i].r--;
        q[i].order = i;
    }
    sort(q, q + Q);
    for (i = 0; i < Q; i++) {
        tmpq = q[i];
        while (tmpq.l < mo_left) {
            tmp = o[--mo_left];
            tmp2 = ++p[tmp];
            hap += tmp * ((tmp2 << 1) - 1);
        }
        while (tmpq.l > mo_left) {
            tmp = o[mo_left++];
            tmp2 = p[tmp]--;
            hap -= tmp * ((tmp2 << 1) - 1);
        }
        while (tmpq.r < mo_right) {
            tmp = o[mo_right--];
            tmp2 = p[tmp]--;
            hap -= tmp * ((tmp2 << 1) - 1);
        }
        while (tmpq.r > mo_right) {
            tmp = o[++mo_right];
            tmp2 = ++p[tmp];
            hap += tmp * ((tmp2 << 1) - 1);
        }
        ans[tmpq.order] = hap;
    }
    for (i = 0; i < Q; i++) printf("%lld\n", ans[i]);
    return 0;
}