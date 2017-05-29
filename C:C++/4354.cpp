#include <cstdio>
#include <cstring>

int fail[1000010];
char o[1000010];
void make_fail(int n) {
    int i = -2, j = -1;
    while(j < n) {
        if(i < 0 || (i >= 0 && o[i] == o[j])) fail[++j] = ++i;
        else i = fail[i];
    }
}
int main() {
    int n;
    while(scanf("%s",o)) {
        if(o[0] == '.') break;
        n = strlen(o);
        make_fail(n);
        if(n % (n - fail[n]) == 0) printf("%d\n",n/(n - fail[n]));
        else printf("1\n");
    }
    return 0;
}