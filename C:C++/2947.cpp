#include <cstdio>
int main() {
    int i, j, k, n = 5;
    int o[11];
    int tmp;
    for(i=0;i<n;i++) scanf("%d",&o[i]);
    for (i=0;i<n-1;i++) {
        for(j=0;j<n-i-1;j++) {
            if(o[j] > o[j+1]) {
                tmp = o[j];
                o[j] = o[j+1];
                o[j+1] = tmp;
                for(k=0;k<n;k++) printf("%d ",o[k]);
                printf("\n");
            }
        }
    }
    return 0;
}