#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

long long _abs(long long x) {
    if(x < 0) return -x;
    return x;
}

long long gcd(long long a, long long b) {
    if(a % b == 0) return b;
    else return gcd(b, a%b);
}

long long mod(long long a, long long b, long long k) {
    long long tmp = 0;
    long long t = 1;
    while(t <= b) {
        if(b & t) tmp = (tmp + a) % k;
        
        a <<= 1;
        a %= k;
        
        t <<= 1;
    }
    return tmp;
}

int main () {
    const int limit = 1 << 18;
    const long long judge = (long long)1 << 32;
    long long n;
    vector<long long> refactor, ans;
    
    scanf("%lld",&n);
    
    while(1) {
        long long number = n, x_fixed = 2, cycle_size = 2, x = 2, factor = 1;
        
        while (factor == 1) {
            for (int count=1;count <= cycle_size && factor <= 1;count++) {
                x = (mod(x, x, number) + 1) % number;
                if(x == x_fixed) x = (x + 31) % number;
                factor = gcd(_abs(x - x_fixed), number);
            }
            
            cycle_size *= 2;
            x_fixed = x;
            if(x == 1) {
                x += 32131;
                x %= number;
            }
            if(cycle_size > limit) break;
        }
        if(cycle_size > limit) {
            ans.push_back(n);
            break;
        }
        if(factor > judge) {
            refactor.push_back(n/factor);
            n=factor;
            continue;
        }
        refactor.push_back(factor);
        n /= factor;
        if(n == 1) break;
    }
    for(long long i : refactor) {
        long long tmp = i;
        for(long long j = 2; j * j <= i; j++) {
            while(tmp % j == 0) {
                tmp /= j;
                ans.push_back(j);
            }
        }
        if(tmp > 1) ans.push_back(tmp);
    }
    sort(ans.begin(), ans.end());
    for(long long i : ans) printf("%lld\n",i);
    return 0;
}