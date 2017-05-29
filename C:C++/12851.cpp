#include <cstdio>
#include <queue>
#include <algorithm>
using namespace std;
long long cnt[300010];
int ph[300010];
queue<pair<int, int> > q;
int main() {
    int n, m;
    pair<int, int> tmp;
    scanf("%d %d",&n,&m);
    q.push(make_pair(n, 0));
    cnt[n] = 1;
    while(q.size()) {
        tmp = q.front();
        q.pop();
        if (tmp.first == m) {
            printf("%d\n",tmp.second);
            break;
        }
        
        if ((tmp.first << 1) <= 300000) {
            if (cnt[tmp.first << 1] == 0) {
                q.push(make_pair(tmp.first << 1, tmp.second + 1));
                ph[tmp.first << 1] = tmp.second + 1;
            }
            if (ph[tmp.first << 1] == tmp.second + 1) cnt[tmp.first << 1] += cnt[tmp.first];
        }
        if (tmp.first - 1 >= 0) {
            if (cnt[tmp.first - 1] == 0) {
                q.push(make_pair(tmp.first - 1, tmp.second + 1));
                ph[tmp.first - 1] = tmp.second + 1;
            }
            if (ph[tmp.first - 1] == tmp.second + 1) cnt[tmp.first - 1] += cnt[tmp.first];
        }
        if (tmp.first + 1 <= 300000) {
            if (cnt[tmp.first + 1] == 0) {
                q.push(make_pair(tmp.first + 1, tmp.second + 1));
                ph[tmp.first + 1] = tmp.second + 1;
            }
            if (ph[tmp.first + 1] == tmp.second + 1) cnt[tmp.first + 1] += cnt[tmp.first];
        }
    }
    while (q.size()) q.pop();
    printf("%lld",cnt[m]);
    return 0;
}