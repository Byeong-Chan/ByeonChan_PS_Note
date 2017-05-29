#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
struct edge {
    int x;
    int y;
    int cost;
    const bool operator< (const edge &a) const {
        return cost < a.cost;
    }
};
class disjoint_set {
public:
    void init(int n) {
        parents.clear();
        parents.resize(n+1);
        for(int i = 1; i <= n; i++) parents[i] = i;
    }
    int find(int x) {
        if(x == parents[x]) return x;
        else return parents[x] = find(parents[x]);
    }
    void uni(int x, int y) {
        x = find(x);
        y = find(y);
        parents[y] = x;
    }
private:
    vector<int> parents;
};
int main() {
    int n, m;
    scanf("%d %d",&n, &m);
    disjoint_set ds;
    vector<edge> e(m);
    ds.init(n);
    for(int i=0;i<m;i++) scanf("%d %d %d", &e[i].x,&e[i].y,&e[i].cost);
    sort(e.begin(), e.end());
    int ans = 0;
    for(int i=0;i<m;i++) {
        if(ds.find(e[i].x) == ds.find(e[i].y)) continue;
        ds.uni(e[i].x, e[i].y);
        ans += e[i].cost;
    }
    printf("%d\n",ans);
    return 0;
}