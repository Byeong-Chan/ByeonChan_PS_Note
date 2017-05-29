#include <stdio.h>
int main()
{
    int x, n, d, c;
    int i, j;
    scanf("%d %d", &n, &x);
    for (i = x; i <= 100; i++) {
        d = n - ((i-1)*i / 2);
       if(d < 0) {
            i = 101;
            break;
        }
        if (d % i == 0) {
            c = d / i;
            for (j = 0; j < i; j++) printf("%d ", c+j);
            break;
        }
    }
    if (i==101) printf("-1");
    return 0;
}