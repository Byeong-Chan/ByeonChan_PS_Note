#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
int dp[10010];
struct node {
    int y;
    int val;
    node() {}
    node(int iy, int ival) {
        y = iy;
        val = ival;
    }
};
vector<node> p[10010];
int main() {
    int i, j;
    int n, D;
    int x, y, z;
    scanf("%d %d",&n,&D);
    for(i=0;i<n;i++) {
        scanf("%d %d %d",&x, &y,&z);
        p[x].push_back(node(y, z));
    }
    for(i=1;i<=D;i++) dp[i] = 0x7fffffff;
    for(i=0;i<D;i++) {
        for(j=0;j<p[i].size();j++) {
            node tmp = p[i][j];
            dp[tmp.y] = min(dp[tmp.y], dp[i] + tmp.val);
        }
        dp[i+1] = min(dp[i+1], dp[i] + 1);
    }
    printf("%d\n",dp[D]);
    return 0;
}