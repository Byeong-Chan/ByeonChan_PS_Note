#include <cstdio>
int k;
int tree[1 << 22];
void init(int n) {
    for(k=1;k<n;k<<=1);
    for(int i = (k<<1) - 1; i >= 0; i--) tree[i] = 0;
}
void update(int d, int val) {
    d += k;
    d--;
    while(d > 0) {
        tree[d] += val;
        d >>= 1;
    }
}
int query(int Rank) {
    int d = 1;
    while(d < k) {
        int l = d << 1;
        int r = l + 1;
        if(Rank - tree[l] > 0) {
            Rank -= tree[l];
            d = r;
        }
        else d = l;
    }
    return d - k + 1;
}
int main() {
    int i;
    int n;
    int q;
    int x, y;
    int tmp;
    scanf("%d",&n);
    init(1000000);
    for(i=0;i<n;i++) {
        scanf("%d",&q);
        if(q == 1) {
            scanf("%d",&x);
            tmp = query(x);
            printf("%d\n",tmp);
            update(tmp, -1);
        }
        else {
            scanf("%d %d", &x, &y);
            update(x, y);
        }
    }
    return 0;
}