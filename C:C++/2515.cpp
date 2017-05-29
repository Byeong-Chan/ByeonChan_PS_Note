#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;
struct bung {
    int h;
    int c;
    bung() {}
    bung(int ih, int ic): h(ih), c(ic) {};
    bool operator< (const bung &a) const {
        return h < a.h;
    }
};
int main() {
    int i, n, m;
    int h, c;
    vector<int> dp(300010);
    vector<bung> o(300010);
    scanf("%d %d", &n, &m);
    for(i=1;i<=n;i++) {
        scanf("%d %d",&h,&c);
        o[i] = bung(h, c);
    }
    sort(o.begin() + 1, o.begin() + n + 1);
    int st = 0;
    for(i=1;i<=n;i++) {
        while(o[i].h - o[st + 1].h >= m) st++;
        dp[i] = dp[st] + o[i].c;
        dp[i] = max(dp[i], dp[i-1]);
    }
    printf("%d\n",dp[n]);
    return 0;
}