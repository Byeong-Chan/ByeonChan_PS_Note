#include <cstdio>
const long long mod = 1000000;

long long A[2][2], E[2][2], tmp[2][2];

void rep(long long n) {
    if(n == 0) return;
    rep(n >> 1);
    int i, j, k;
    for(i=0;i<2;i++) {
        for(j=0;j<2;j++) {
            tmp[i][j] = E[i][j];
            E[i][j] = 0;
        }
    }
    for(i=0;i<2;i++) {
        for(j=0;j<2;j++) {
            for(k=0;k<2;k++) {
                E[i][j] += tmp[i][k] * tmp[k][j];
                E[i][j] %= mod;
            }
        }
    }
    if(n & 1) {
        for(i=0;i<2;i++) {
            for(j=0;j<2;j++) {
                tmp[i][j] = E[i][j];
                E[i][j] = 0;
            }
        }
        for(i=0;i<2;i++) {
            for(j=0;j<2;j++) {
                for(k=0;k<2;k++) {
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
    if(n == 0) {
        printf("0\n");
        return 0;
    }
    A[0][0] = 1;
    A[0][1] = 1;
    A[1][0] = 1;
    A[1][1] = 0;
    E[0][0] = 1;
    E[1][1] = 1;
    rep(n - 1);
    printf("%lld\n",E[0][0]);
    return 0;
}