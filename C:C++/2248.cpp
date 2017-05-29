#include <cstdio>
long long C[50][50];
long long Csum[50][50];
void make_comb() {
    int i, j;
    C[0][0] = 1;
    for (i=1;i<=32;i++) {
        C[i][0] = 1;
        for(j=1;j<=i;j++) {
            C[i][j] = C[i-1][j-1] + C[i-1][j];
        }
    }
}
void make_combsum() {
    int i, j;
    Csum[0][0] = 1;
    for(i=1;i<=32;i++) {
        Csum[i][0] = 1;
        for(j=1;j<=i;j++) {
            Csum[i][j] += Csum[i][j-1] + C[i][j];
        }
    }
}
bool ans[34];
int main() {
    int n, m;
    long long c;
    int i, j;
    int sum = 0;
    int tmp;
    make_comb();
    make_combsum();
    scanf("%d %d %lld",&n,&m,&c);
    for (i=m-1;i>=0;i--) {
        if (sum + 1 >= c) continue;
        sum++;
        for(j=0;j<n;j++) {
            tmp = i > j ? j : i;
            if (sum + Csum[j][tmp] >= c) break;
            sum += Csum[j][tmp];
        }
        ans[j] = 1;
    }
    for(i=n-1;i>=0;i--) printf("%d",ans[i]);
    printf("\n");
    return 0;
}