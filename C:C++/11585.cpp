#include <cstdio>
#include <cstring>
int f[1000010];
char o[2000010];
char u[1000010];
void make_fail(char *p, int m) {
    int i = -2, j = -1;
    while(j < m) {
        if(i < 0 || (i >= 0 && p[i] == p[j])) {
            i++, j++;
            f[j] = i;
        }
        else i = f[i];
    }
}
int match(char *s, char *p, int n, int m) {
    make_fail(p, m);
    int i = 0, j = 0;
    int ans = 0;
    while(j <= n) {
        if(i == m) {
            i = f[i];
            ans++;
        }
        else if(i < 0 || (i >= 0 && p[i] == s[j])) i++, j++;
        else i = f[i];
    }
    return ans;
}
int gcd(int a, int b) {
    return a % b == 0 ? b : gcd(b, a%b);
}
int main() {
    int i, n;
    int p, q;
    scanf("%d\n",&n);
    for(i=0;i<n;i++) {
        if(i < n-1) scanf("%c ",&u[i]);
        else scanf("%c\n",&u[i]);
    }
    for(i=0;i<n;i++) {
        if(i < n-1) scanf("%c ",&o[i]);
        else scanf("%c",&o[i]);
    }
    strncat(o, o, n-1);
    q = match(o, u, 2*n-1, n);
    p = gcd(n, q);
    printf("%d/%d\n",q/p, n/p);
    return 0;
}