#include <cstdio>
#include <vector>
using namespace std;
vector<int> p[100010];
bool d[100010];
int main() {
    int i, j, n;
    int m;
    int x;
    int cnt;
    int sz = 0;
    scanf("%d",&n);
    for(i=1;i<=n;i++) {
        scanf("%d",&m);
        for(j=0;j<m;j++) {
            scanf("%d",&x);
            p[i].push_back(x);
        }
    }
    bool flag = true;
    while(flag) {
        flag = false;
        for(i=1;i<=n;i++) {
            cnt = 0;
            for(j=0;j<p[i].size();j++) if(d[i] == d[p[i][j]]) cnt++;
            if(cnt >= 2) d[i] = !d[i], flag = true;
        }
    }
    
    for(i=1;i<=n;i++) if(d[i]) sz++;
    if(sz == 0) d[1] = true, sz++;
    
    printf("%d ",n - sz);
    for(i=1;i<=n;i++) if(!d[i]) printf("%d ",i);
    printf("\n");
    printf("%d ",sz);
    for(i=1;i<=n;i++) if(d[i]) printf("%d ",i);
    printf("\n");
    return 0;
}