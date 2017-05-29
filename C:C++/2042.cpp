#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
#define BLOCK 550
struct SqrtDecompostion {
public:
    void init(int n) {
        val.resize(n);
        bval.resize(n/BLOCK+1);
    }
    void update(int d, int ch) {
        bval[d/BLOCK] -= val[d];
        bval[d/BLOCK] += ch;
        val[d] = ch;
    }
    long long query(int l, int r) {
        long long ans = 0;
        for(int i=l/BLOCK + 1; i<r/BLOCK; i++) ans += bval[i];
        if(r/BLOCK == l/BLOCK) {
            for(int i=l;i<=r;i++) ans += val[i];
        }
        else {
            for(int i=l;i<(l/BLOCK+1)*BLOCK;i++) ans += val[i];
            for(int i=(r/BLOCK)*BLOCK;i<=r;i++) ans += val[i];
        }
        return ans;
    }
private:
    vector<long long> bval;
    vector<long long> val;
};
int main() {
    int i, n;
    int m, k;
    int x, y;
    int q;
    SqrtDecompostion sd;
    scanf("%d %d %d",&n,&m,&k);
    m += k;
    sd.init(n);
    for(i=0;i<n;i++) {
        scanf("%d",&x);
        sd.update(i, x);
    }
    for(i=0;i<m;i++) {
        scanf("%d",&q);
        scanf("%d %d",&x,&y);
        if(q == 1) sd.update(x-1, y);
        if(q == 2) {
            if(x > y) swap(x, y);
            printf("%lld\n",sd.query(x-1, y-1));
        }
    }
    return 0;
}