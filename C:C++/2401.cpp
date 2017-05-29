#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

int fail[510][10010];
int len[510];
int x[510];
int dp[100010];
char o[100010];
char u[510][10010];
void make_fail(char *str, int *fail, int n) {
    int i = -2, j = -1;
    while(j < n) {
        if(i < 0 || (i >= 0 && str[i] == str[j])) fail[++j] = ++i;
        else i = fail[i];
    }
}
int main() {
    int i, n, m;
    int y;
    scanf("%s",o);
    n = (int)strlen(o);
    scanf("%d",&m);
    for(i=0;i<m;i++) {
        scanf("%s",u[i]);
        len[i] = (int)strlen(u[i]);
        make_fail(u[i], fail[i], len[i]);
    }
    y = 0;
    while(y < n) {
        for(i=0;i<m;i++) {
            while(x[i] >= 0 && u[i][x[i]] != o[y]) x[i] = fail[i][x[i]];
            x[i]++;
            if(x[i] == len[i]) dp[y+1] = max(dp[y+1], dp[y+1-len[i]] + len[i]);
        }
        y++;
        dp[y] = max(dp[y], dp[y-1]);
    }
    printf("%d\n",dp[n]);
    return 0;
}