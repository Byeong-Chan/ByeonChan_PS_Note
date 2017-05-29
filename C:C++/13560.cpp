#include <cstdio>
int ss[10010];
int main() {
    int i, j, k, n;
    int x;
    int sum = 0;
    bool cant = false;
    scanf("%d",&n);
    for (i=0;i<n;i++) {
        scanf("%d",&x);
        if (x >= n) {
            printf("-1");
            return 0;
        }
        ss[n - 1 - x]++;
        sum += n - 1 - x;
    }
    for (i=n;i>=1;i--) {
        if (sum != i * (i-1) / 2) break;
        sum = 0;
        for (k=0;k<n;k++) if (ss[k] > 0) {
            ss[k]--;
            break;
        }
        if (k == n) {
            cant = true;
            break;
        }
        for (j=0;j<=n;j++) {
            if (ss[j]) {
                if (k) {
                    if (ss[j] > k) {
                        ss[j-1] += ss[j] - k;
                        ss[j] = k;
                        k = 0;
                    }
                    else k -= ss[j];
                }
                else {
                    if (j-1 < 0) {
                        cant = true;
                        break;
                    }
                    ss[j-1] += ss[j];
                    ss[j] = 0;
                }
            }
            if (j) sum += (j-1) * ss[j-1];
        }
        if (cant) break;
    }
    if (i) printf("-1\n");
    else printf("1\n");
    return 0;
}