#include <cstdio>
#include <vector>
#include <algorithm>
#include <set>
#include <stack>
#include <queue>

using namespace std;

const long long MAX = (long long)0x7fffffff << 30;

struct bung {
    int x;
    int yl;
    int yh;
    bool operator < (const bung &a) const {
        return x < a.x;
    }
};
bung o[100010];

struct node {
    int xpos;
    int ypos;
    int vpos;
    node() {}
    node(int ixpos, int iypos, int ivpos) {
        xpos = ixpos;
        ypos = iypos;
        vpos = ivpos;
    }
    bool operator < (const node &a) const {
        return ypos < a.ypos;
    }
};
set<node> plv;

struct info {
    int pos;
    long long cst;
    info() {}
    info(int ipos, long long icst) {
        pos = ipos;
        cst = icst;
    }
};

struct qnode {
    int pre;
    int pos;
    long long dist;
    qnode() {}
    qnode(int ipre, int ipos, long long idist) {
        pre = ipre;
        pos = ipos;
        dist = idist;
    }
    bool operator < (const qnode &a) const {
        return dist > a.dist;
    }
};

long long _abs(long long x) {
    return x < 0 ? -x : x;
}

priority_queue<qnode> q;
vector<info> edge[200010];
long long d[200010];
int vinfo[200010];
int ans[200010];
int main() {
    int i, n, m = 0;
    int vcnt = 0;
    int sty, edx;
    long long dis;
    stack<node> sav;
    set<node>::iterator j, ed;
    scanf("%d",&n);
    scanf("%d %d",&sty,&edx);
    for(i=0;i<n;i++) scanf("%d %d %d",&o[i].x,&o[i].yl,&o[i].yh);
    o[n].x = edx;
    o[n].yl = -1;
    o[n].yh = 2000001;
    
    
    plv.insert(node(0, sty, ++vcnt));
    vinfo[vcnt] = sty;
    sort(o,o+n);
    for(i=0;i<=n;i++) {
        ed = plv.upper_bound(node(-1, o[i].yh, -1));
        for(j = plv.lower_bound(node(-1, o[i].yl, -1)); j != ed; j++) sav.push(*j);
        if(sav.size()) {
            if(i == n) vcnt++;
            else vcnt += 2;
            while(sav.size()) {
                node tmp = sav.top();
                sav.pop();
                plv.erase(tmp);
                
                if(i == n) {
                    dis = o[i].x - tmp.xpos;
                    edge[tmp.vpos].push_back(info(vcnt, dis));
                    continue;
                }
                dis = _abs(tmp.ypos - o[i].yl) + o[i].x - tmp.xpos;
                edge[tmp.vpos].push_back(info(vcnt-1, dis));
                dis = _abs(tmp.ypos - o[i].yh) + o[i].x - tmp.xpos;
                edge[tmp.vpos].push_back(info(vcnt, dis));
            }
            if(i == n) continue;
            vinfo[vcnt-1] = o[i].yl;
            plv.insert(node(o[i].x, o[i].yl, vcnt-1));
            vinfo[vcnt] = o[i].yh;
            plv.insert(node(o[i].x, o[i].yh, vcnt));
        }
    }
    for(i=1;i<=vcnt;i++) d[i] = MAX;
    q.push(qnode(-1, 1, 0));
    while(q.size()) {
        qnode here = q.top();
        q.pop();
        if(d[here.pos] < here.dist) continue;
        if(here.pos == vcnt) ans[m++] = vinfo[here.pre];
        if(d[here.pos] == here.dist) continue;
        d[here.pos] = here.dist;
        for(i=0;i<edge[here.pos].size();i++) {
            info nxt = edge[here.pos][i];
            q.push(qnode(here.pos, nxt.pos, here.dist + nxt.cst));
        }
    }
    printf("%lld\n",d[vcnt]);
    printf("%d",m);
    sort(ans, ans+m);
    for(i=0;i<m;i++) printf(" %d",ans[i]);
    printf("\n");
    return 0;
}