#include <cstdio>
int o[110];
int u[110];
int main() {
    int n, m;
    int cnt = 0;
    int ans = 0;
    scanf("%d %d",&n,&m);
    for(int i=0;i<m;i++) scanf("%d",&o[i]);
    for(int i=0;i<m;i++) {
        int j, k;
        for(j=0;j<cnt;j++) if(u[j] == o[i]) break;
        if(j < cnt) continue;
        if(cnt < n) u[cnt++] = o[i];
        else {
            int max1 = -1;
            int tmp = 0;
            for(j=0;j<cnt;j++) {
                for(k=i+1;k<m;k++) if(u[j] == o[k]) break;
                if(k > max1) {
                    max1 = k;
                    tmp = u[j];
                }
            }
            for(j=0;j<cnt;j++) if(tmp == u[j]) u[j] = o[i];
            ans++;
        }
    }
    printf("%d\n",ans);
}