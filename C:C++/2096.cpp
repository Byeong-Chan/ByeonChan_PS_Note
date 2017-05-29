#include <cstdio>
#include <algorithm>
using namespace std;
int dp1[3];
int dp2[3];
int tmp[3];
int main() {
    int i, j;
    int n;
    int x, y, z;
    scanf("%d",&n);
    scanf("%d %d %d",&x,&y,&z);
    dp1[0] = dp2[0] = x;
    dp1[1] = dp2[1] = y;
    dp1[2] = dp2[2] = z;
    for(i=1;i<n;i++) {
        scanf("%d %d %d",&x,&y,&z);
        for(j=0;j<3;j++) {
            tmp[j] = dp1[j];
            dp1[j] = 0;
        }
        dp1[0] = max(tmp[0]+x, tmp[1]+x);
        dp1[1] = max(tmp[0]+y, max(tmp[1]+y, tmp[2] + y));
        dp1[2] = max(tmp[1]+z, tmp[2]+z);
        for(j=0;j<3;j++) {
            tmp[j] = dp2[j];
            dp2[j] = 0;
        }
        dp2[0] = min(tmp[0]+x, tmp[1]+x);
        dp2[1] = min(tmp[0]+y, min(tmp[1]+y, tmp[2] + y));
        dp2[2] = min(tmp[1]+z, tmp[2]+z);
    }
    printf("%d %d\n",max(dp1[0], max(dp1[1], dp1[2])), min(dp2[0], min(dp2[1], dp2[2])));
    return 0;
}