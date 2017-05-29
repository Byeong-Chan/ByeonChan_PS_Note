#include <cstdio>
#define mod 1000
int A[5][5], E[5][5], tmp[5][5], N;
void init(int n) {
    N = n;
    for(int i=0;i<N;i++) {
        for(int j=0;j<N;j++) {
            E[i][j] = 0;
            scanf("%d",&A[i][j]);
        }
        E[i][i] = 1;
    }
}
void rep(long long n) {
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
                    E[i][j] += tmp[i][k] * A[k][j];
                    E[i][j] %= mod;
                }
            }
        }
    }
}
int main() {
    int n;
    long long b;
    scanf("%d %lld",&n,&b);
    init(n);
    rep(b);
    for(int i=0;i<N;i++) {
        for(int j=0;j<N;j++) {
            printf("%d ",E[i][j]);
        }
        printf("\n");
    }
    return 0;
}