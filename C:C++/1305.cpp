#include <cstdio>
char o[3000010];
int f[3000010];
void make_fail(char *str, int m) {
    int i = -2, j = -1;
    while(j < m) {
        if(i < 0) {
            i++, j++;
            f[j] = i;
        }
        else if(str[i] == str[j]) {
            i++, j++;
            f[j] = i;
        }
        else i = f[i];
    }
}
int main() {
    int n;
    scanf("%d\n",&n);
    scanf("%[^\n]",o);
    make_fail(o, n);
    printf("%d\n",n-f[n]);
    return 0;
}