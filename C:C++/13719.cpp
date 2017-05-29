#include <cstdio>
int o[1000010];
int main() {
    int i, n;
    scanf("%d",&n);
    int st = 0, ed = n - 1;
    long long hapst = 0, haped = 0;
    int ans = 0;
    for(i=0;i<n;i++) scanf("%d",&o[i]);
    hapst = o[st];
    haped = o[ed];
    while (st < ed) {
        if(hapst == haped) {
            st++;
            ed--;
            hapst = o[st];
            haped = o[ed];
            continue;
        }
        if(hapst < haped) {
            st++;
            hapst += o[st];
            ans++;
            continue;
        }
        if(hapst > haped) {
            ed--;
            haped += o[ed];
            ans++;
            continue;
        }
    }
    printf("%d\n",ans);
    return 0;
}