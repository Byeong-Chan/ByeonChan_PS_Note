#include <cstdio>
int q[16] = {0, 1, 0, 0, 2, 10, 4, 40, 92, 352, 724, 2680, 14200, 73712, 365596, 2279184};
int main() {
    int n;
    scanf("%d",&n);
    printf("%d",q[n]);
    return 0;
}