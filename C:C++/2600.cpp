#include <cstdio>
bool dp[1010][1010];
int main() {
    int i, j, k;
    int x[3];
    int k1, k2;
    scanf("%d %d %d",&x[0],&x[1],&x[2]);
    for(i=0;i<=1000;i++) {
        for(j=0;j<=i;j++) {
            if(dp[j][i-j]) continue;
            for(k=0;k<3;k++) {
                if(i-j+x[k] <= 1000) dp[j][i-j+x[k]] = true;
                if(j+x[k] <= 1000) dp[j+x[k]][i-j] = true;
            }
        }
    }
    for(i=0;i<5;i++) {
        scanf("%d %d",&k1,&k2);
        if(dp[k1][k2]) printf("A\n");
        else printf("B\n");
    }
    return 0;
}