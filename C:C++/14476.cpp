#include <cstdio>
int dp[1000010];
int o[1000010];
int gcd(int a, int b) {
    if(a % b == 0) return b;
    else return gcd(b, a%b);
}
int main() {
    int i, n;
    int x = 1;
    int tmp, ans;
    int del = 1;
    int sav;
    scanf("%d",&n);
    for(i=0;i<n;i++) scanf("%d",&o[i]);
    dp[n-1] = o[n-1];
    for(i=n-2;i>=0;i--) dp[i] = gcd(dp[i+1], o[i]);
    tmp = ans = dp[0];
    
    if(ans < dp[1]) {
        ans = dp[1];
        del = o[0];
    }
    
    for(i=0;i<n-1;i++) {
        if(i == 0) x = o[i];
        else x = gcd(x, o[i]);
        
        if(i == n-2) {
            if(x > ans) {
                ans = x;
                del = o[i+1];
            }
        }
        else if((sav=gcd(x, dp[i+2])) > ans) {
            ans = sav;
            del = o[i+1];
        }
    }
    if(ans == tmp) printf("-1\n");
    else printf("%d %d\n", ans, del);
    return 0;
}