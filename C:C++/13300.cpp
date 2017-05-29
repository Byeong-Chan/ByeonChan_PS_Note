#include <cstdio>
int people[2][7];
int main() {
    int n;
    int i;
    int x, y;
    int k;
    int ans = 0;
    scanf("%d %d",&n,&k);
    for(i=0;i<n;i++) {
        scanf("%d %d",&x,&y);
        people[x][y]++;
    }
    for(i=1;i<=6;i++) ans += (people[0][i] + k - 1) / k + (people[1][i] + k - 1) / k;
    printf("%d\n",ans);
    return 0;
}