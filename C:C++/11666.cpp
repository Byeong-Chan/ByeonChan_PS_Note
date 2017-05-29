#include <cstdio>
#include <queue>
#include <algorithm>
using namespace std;
struct bung {
    int st;
    int ed;
    bool operator< (const bung &a) const {
        return this->st < a.st;
    }
}o[300010];
priority_queue<int, vector<int>, greater<int> > q;
int main() {
    int i, n, m;
    int tmp;
    int ans = 0;
    scanf("%d %d",&n,&m);
    for(i=0;i<n;i++) {
        scanf("%d %d", &o[i].st, &o[i].ed);
        o[i].ed += o[i].st;
    }
    sort(o, o+n);
    for(i=0;i<n;i++) {
        ans++;
        while(q.size()) {
            tmp = q.top();
            if(o[i].st < tmp) break;
            q.pop();
            if(o[i].st <= tmp+m) {
                ans--;
                break;
            }
        }
        q.push(o[i].ed);
    }
    printf("%d",n-ans);
    return 0;
}