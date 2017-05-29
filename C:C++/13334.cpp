#include <cstdio>
#include <queue>
#include <vector>
#include <algorithm>
#include <functional>
using namespace std;

struct bung {
    int x;
    int y;
    bool operator < (const bung &a) const {
        if(y != a.y) return y < a.y;
        else return x > a.x;
    }
}o[100010];

priority_queue<int, vector<int>, greater<int> > q;

int main() {
    int i;
    int n;
    int d;
    int ans = 0;
    scanf("%d",&n);
    for(i=0;i<n;i++) {
        scanf("%d %d",&o[i].x,&o[i].y);
        if(o[i].x > o[i].y) swap(o[i].x, o[i].y);
    }
    scanf("%d",&d);
    
    sort(o,o+n);
    for(i=0;i<n;i++) {
        q.push(o[i].x);
        while(q.size()) {
            if(o[i].y - q.top() <= d) break;
            q.pop();
        }
        if(ans < q.size()) ans = (int)q.size();
    }
    printf("%d\n",ans);
    return 0;
}