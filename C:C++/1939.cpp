#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
int q[10010];
struct node {
    int lim;
    int nxt;
    void inp(int a,int b) {
        this->lim = a;
        this->nxt = b;
    }
};
vector<node> edge[10010];
int chk[10010];
int main() {
    int n, m;
    int i;
    int x, y, z;
    int first, last;
    int st, ed, mid;
    int qt, qh, here;
    int e = 0;
    bool sw;
    node tmp;
    scanf("%d %d",&n,&m);
    for(i=0;i<m;i++) {
        scanf("%d %d %d",&x,&y,&z);
        tmp.inp(z, y);
        edge[x].push_back(tmp);
        tmp.inp(z, x);
        edge[y].push_back(tmp);
    }
    scanf("%d %d",&first, &last);
    st = 1;
    ed = 1000000001;
    while (st < ed) {
        mid = (st+ed) >> 1;
        qt = qh = 0;
        sw = false;
        q[qt++] = first;
        e++;
        chk[first] = e;
        while (qh < qt) {
            here = q[qh++];
            if (here == last) {
                sw = true;
                break;
            }
            for (i=0;i<edge[here].size();i++) {
                tmp = edge[here][i];
                if (chk[tmp.nxt] == e || tmp.lim < mid) continue;
                chk[tmp.nxt] = e;
                q[qt++] = tmp.nxt;
            }
        }
        if (sw) st = mid + 1;
        else ed = mid;
    }
    printf("%d\n",st-1);
    return 0;
}