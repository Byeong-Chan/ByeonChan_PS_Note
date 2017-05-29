#include <cstdio>
#include <queue>
#include <algorithm>
#include <functional>
#include <vector>
using namespace std;
struct node {
    int x;
    int y;
    node() {}
    node(int ix, int iy) : x(ix), y(iy) {}
    bool operator< (const node &a) const {
        if(x != a.x) return y < a.y;
        else return x < a.x;
    }
}o[50010];
priority_queue<int, vector<int>, greater<int> > p;
bool cmp(const node &a, const node &b) {
    if(a.x != b.x) return a.x < b.x;
    else return a.y < b.y;
}
int main() {
    int i;
    int n, k;
    long long m;
    int x, y;
    int ans = 0;
    long long sum = 0;
    scanf("%d %d %lld",&n,&k,&m);
    for(i=0;i<n;i++) {
        scanf("%d %d",&x,&y);
        o[i] = node(x, y);
    }
    sort(o, o+n);
    for(i=0;i<k;i++) {
        if(sum + o[i].y <= m) {
            sum += o[i].y;
            p.push(o[i].x - o[i].y);
        }
        else {
            printf("%d\n",(int)p.size());
            return 0;
        }
    }
    sort(o+k,o+n, cmp);
    for(i=k;i<n;i++) {
        if(p.top() < o[i].x - o[i].y) {
            if(o[i].y + p.top() + sum > m) continue;
            sum += o[i].y + p.top();
            p.pop();
            p.push(o[i].x - o[i].y);
            ans++;
        }
        else {
            if(o[i].x + sum > m) continue;
            sum += o[i].x;
            ans++;
        }
    }
    
    printf("%d\n",k+ans);
    return 0;
}