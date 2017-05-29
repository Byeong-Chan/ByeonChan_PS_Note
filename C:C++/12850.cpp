#include <cstdio>

const long long mod = 1000000007;
const int M = 8;

long long tmp[8][8], E[8][8], A[8][8] = {
    0, 1, 1, 0, 0, 0, 0, 0,
    1, 0, 0, 1, 1, 0, 0, 0,
    1, 0, 0, 1, 0, 0, 0, 0,
    0, 1, 1, 0, 1, 1, 0, 0,
    0, 1, 0, 1, 0, 1, 1, 0,
    0, 0, 0, 1, 1, 0, 1, 1,
    0, 0, 0, 0, 1, 1, 0, 1,
    0, 0, 0, 0, 0, 1, 1, 0
};

void init() {
    int i;
    for(i=0;i<M;i++) E[i][i] = 1;
}

void rep(long long n) {
    if(n == 0) return;
    rep(n >> 1);
    int i, j, k;
    for(i=0;i<M;i++) {
        for(j=0;j<M;j++) {
            tmp[i][j] = E[i][j];
            E[i][j] = 0;
        }
    }
    for(i=0;i<M;i++) {
        for(j=0;j<M;j++) {
            for(k=0;k<M;k++) {
                E[i][j] += tmp[i][k] * tmp[k][j];
                E[i][j] %= mod;
            }
        }
    }
    if(n & 1) {
        for(i=0;i<M;i++) {
            for(j=0;j<M;j++) {
                tmp[i][j] = E[i][j];
                E[i][j] = 0;
            }
        }
        for(i=0;i<M;i++) {
            for(j=0;j<M;j++) {
                for(k=0;k<M;k++) {
                    E[i][j] += tmp[i][k] * A[k][j];
                    E[i][j] %= mod;
                }
            }
        }
    }
}
int main() {
    long long n;
    scanf("%lld",&n);
    init();
    rep(n);
    printf("%lld\n",E[7][7]);
    return 0;
}