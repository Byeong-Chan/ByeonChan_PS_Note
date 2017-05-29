#include <cstdio>

long long mod;
int M;

long long sav[40][40], tmp[40][40], tmp2[40][40], E[40][40], A[40][40];
long long P[23][40][40];
int K[23];

void init() {
    int i, j;
    for(i=0;i<M;i++) {
        E[i][i] = 1;
        for(j=0;j<M;j++) {
            if(i != j) E[i][j] = 0;
        }
    }
}

void rep(long long n) {
    if(n <= 0) return;
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
void rep2(int n) {
    if(n <= 0) return;
    rep2(n >> 1);
    int i, j, k;
    
    if(n == 1) {
        for(i=0;i<M;i++) {
            for(j=0;j<M;j++) {
                tmp[i][j] = sav[i][j];
                E[i][j] = A[i][j];
            }
        }
        for(i=0;i<M;i++) {
            for(j=0;j<M;j++) {
                for(k=0;k<M;k++) {
                    sav[i][j] += tmp[i][k] * E[k][j];
                    sav[i][j] %= mod;
                }
            }
        }
    }
    else {
        for(i=0;i<M;i++) {
            for(j=0;j<M;j++) {
                tmp[i][j] = sav[i][j];
                tmp2[i][j] = E[i][j];
                E[i][j] = 0;
            }
        }
        for(i=0;i<M;i++) {
            for(j=0;j<M;j++) {
                for(k=0;k<M;k++) {
                    E[i][j] += tmp2[i][k] * tmp2[k][j];
                    E[i][j] %= mod;
                }
            }
        }
        for(i=0;i<M;i++) {
            for(j=0;j<M;j++) {
                for(k=0;k<M;k++) {
                    sav[i][j] += tmp[i][k] * E[k][j];
                    sav[i][j] %= mod;
                }
            }
        }
    }
}
int main() {
    int i, j;
    int n, k, m;
    int x, y;
    int pp, qq;
    long long ans = 0;
    char o[40] = {0,};
    scanf("%d %d %d",&n,&k,&m);
    k--;
    M = n;
    mod = m;
    init();
    for(i=0;i<n;i++) {
        scanf("%s",o);
        for(j=0;j<n;j++) {
            A[i][j] = 0;
            if(o[j] == 'Y') A[i][j] = 1;
        }
    }
    for(K[0] = 1;K[0] < k;K[0] <<= 1);
    pp = k;
    qq = 0;
    for(i=0,j=K[0];j>0;j>>=1) {
        if(pp - j >= 0) {
            K[i++] = j;
            
            qq += j;
            init();
            rep(qq);
            for(x=0;x<M;x++) for(y=0;y<M;y++) P[i][x][y] = E[x][y];
            pp -= j;
        }
    }
    for(j=0;j<=i;j++) {
        for(x=0;x<M;x++) {
            for(y=0;y<M;y++) {
                sav[x][y] = 0;
                if(j > 0) sav[x][y] = P[j][x][y];
                else if(x == y) sav[x][y] = 1;
            }
        }
        rep2(K[j] - 1);
        for(x=0;x<M;x++) ans += sav[x][x];
        ans %= mod;
    }
    ans -= M;
    while(ans < 0) ans += mod;
    printf("%lld\n",ans);
    return 0;
}