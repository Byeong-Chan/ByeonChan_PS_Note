#include <cstdio>
int main() {
    int x = 1, y = 1, n;
    int sum = 1;
    int ans = 0;
    scanf("%d",&n);
    while (y <= n) {
        if (sum <= n) {
            if (sum == n) ans++;
            sum += ++y;
            continue;
        }
        else sum -= x++;
    }
    printf("%d\n",ans);
    return 0;
}