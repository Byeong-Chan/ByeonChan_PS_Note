#include <cstdio>

const int mod = 100;
const int M = 2;

int tmp[8][8], E[8][8], A[8][8];

void init() {
    int i;
    for(i=0;i<M;i++) E[i][i] = 1;
}

void rep(int n) {
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
    int n;
    int x, y;
    int a1, a2, t1, t2;
    scanf("%d %d",&x,&y);
    A[0][0] = x;
    A[1][0] = y;
    A[0][1] = 1;
    scanf("%1d%1d %1d%1d",&a2,&t2,&a1,&t1);
    a1 *= 10;
    a1 += t1;
    a2 *= 10;
    a2 += t2;
    scanf("%d",&n);
    if(n == 0) {
        printf("%d\n",a2);
        return 0;
    }
    init();
    rep(n-1);
    int tmp = (E[0][0] * a1 + E[1][0] * a2) % mod;
    if(!(tmp / 10)) printf("0");
    printf("%d\n",tmp);
    return 0;
}