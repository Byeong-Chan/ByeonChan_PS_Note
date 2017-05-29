#include <cstdio>
const long long mod = 31991;
int N;
long long E[101][101], A[101][101], tmp[101][101];
void rep(int n) {
    if(n == 0) return;
    rep(n >> 1);
    int i, j, k;
    for(i=0;i<N;i++) {
        for(j=0;j<N;j++) {
            tmp[i][j] = E[i][j];
            E[i][j] = 0;
        }
    }
    for(i=0;i<N;i++) {
        for(j=0;j<N;j++) {
            for(k=0;k<N;k++) {
                E[i][j] += tmp[i][k] * tmp[k][j];
                E[i][j] %= mod;
            }
        }
    }
    if(n & 1) {
        for(i=0;i<N;i++) {
            for(j=0;j<N;j++) {
                tmp[i][j] = E[i][j];
                E[i][j] = 0;
            }
        }
        for(i=0;i<N;i++) {
            for(j=0;j<N;j++) {
                for(k=0;k<N;k++) {
                    E[i][j] += A[i][k] * tmp[k][j];
                    E[i][j] %= mod;
                }
            }
        }
    }
}
int main() {
    int i, j, d, n;
    scanf("%d %d", &d, &n);
    N = d;
    for(i=0;i<N;i++) {
        for(j=0;j<N;j++) if(i == j-1) A[i][j] = 1;
        E[i][i] = 1;
        A[i][0] = 1;
    }
    rep(n);
    printf("%lld\n",E[0][0]);
    return 0;
}