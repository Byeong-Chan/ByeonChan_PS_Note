#include <cstdio>
#include <algorithm>
#include <map>
#include <vector>
using namespace std;
map<vector<int>, long long> dp[36][5][5];
int main() {
    vector<int> tmp;
     
    int k, i, j, n, l;
    int sum = 0;
    long long ans = 0;
    scanf("%d",&n);
    tmp.resize(n);
    for(i=0;i<n;i++) {
        scanf("%d",&tmp[i]);
        sum += tmp[i];
    }
    for(i=0;i<n;i++) {
        for(j=0;j<n;j++) {
            if (i==j) continue;
            tmp[i]--;
            tmp[j]--;
            dp[2][i][j][tmp] = 1;
            tmp[i]++;
            tmp[j]++;
        }
    }
    map<vector<int>, long long>::iterator it;
    for(k=3;k<=sum;k++) {
        for(i=0;i<n;i++) {
            for(j=0;j<n;j++) {
                if (i == j) continue;
                for(it=dp[k-1][i][j].begin();it!=dp[k-1][i][j].end();it++) {
                    for(l=0;l<n;l++) {
                        if (l == i || l == j || it->first[l] == 0) continue;
                        tmp = it->first;
                        tmp[l]--;
                        if (k == sum) ans += it->second;
                        else dp[k][j][l][tmp] += it->second;
                    }
                }
                dp[k-1][i][j].clear();
            }
        }
    }
    printf("%lld",ans);
    return 0;
}