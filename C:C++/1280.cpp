#include <cstdio>

const long long mod = 1000000007;

struct BIT {
    long long sum[200010];
    long long mul[200010];
    int o[200010];
    int N;
    void init(int n) {
        N = n;
        for(int i = 1; i <= n; i++) {
            sum[i] = 0;
            mul[i] = 0;
        }
    }
    
    void update(int i, long long val1, long long val2) {
        val1 %= mod;
        val2 %= mod;
        if(val1 < 0) val1 += mod;
        if(val2 < 0) val2 += mod;
        while(i <= N) {
            sum[i] += val1;
            sum[i] %= mod;
            mul[i] += val2;
            mul[i] %= mod;
            i += (i & (-i));
        }
    }
    
    void range_update(int l, int r, long long val) {
        update(l, val, -(l-1) * val);
        update(r, -val, r * val);
    }
    
    long long query(int i) {
        long long ans = 0;
        long long hap = 0;
        long long tmp = i;
        while(i > 0) {
            ans += sum[i];
            ans %= mod;
            hap += mul[i];
            hap %= mod;
            i -= (i & (-i));
        }
        return (ans * tmp + hap) % mod;
    }
};

BIT dec1, dec2;

int main() {
    int i, n;
    int x;
    long long ans = 1;
    long long hap = 0;
    scanf("%d",&n);
    dec1.init(200000);
    dec2.init(200000);
    for(i=0;i<n;i++) {
        scanf("%d",&x);
        x++;
        hap = 0;
        hap += dec1.query(x);
        hap += dec2.query(200000) - dec2.query(x-1);
        if(x < 200000) dec1.range_update(x+1, 200000, 1);
        if(x > 1) dec2.range_update(1, x-1, 1);
        hap %= mod;
        if(i > 0) ans *= hap;
        ans %= mod;
        if(ans < 0) ans += mod;
    }
    if(ans < 0) ans += mod;
    printf("%lld\n",ans);
    return 0;
}