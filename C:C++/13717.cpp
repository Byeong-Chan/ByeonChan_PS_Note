#include <cstdio>
#include <cstring>
int main() {
    int i, n;
    int ans1 = 0;
    char max1= 0, ans2[23];
    char x[23];
    int m, k;
    int p;
    scanf("%d",&n);
    for(i=0;i<n;i++) {
        scanf("%s",x);
        scanf("%d %d",&m,&k);
        p = 0;
        while(k-m >= 0) {
            k-=m;
            k+=2;
            p++;
        }
        ans1 += p;
        if(max1 < p) {
            max1 = p;
            strcpy(ans2, x);
        }
    }
    printf("%d\n",ans1);
    printf("%s\n",ans2);
    return 0;
}