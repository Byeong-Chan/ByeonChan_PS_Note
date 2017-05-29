#include <cstdio>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;
char o[510][510];
int dx[4] = {1, 1, -1, -1};
int dy[4] = {1, -1, 1, -1};
int fx[4] = {1, 1, 0, 0};
int fy[4] = {1, 0, 1, 0};
int tr[4][256];

struct edge_info {
    int nxt;
    int val;
    edge_info() {}
    edge_info(int inxt, int ival) {
        nxt = inxt;
        val = ival;
    }
};

struct node {
    int pos;
    int val;
    node() {}
    node(int ipos, int ival) {
        pos = ipos;
        val = ival;
    }
    bool operator < (const node &a) const {
        return val > a.val;
    }
};

vector<edge_info> edge[260010];
priority_queue<node> q;
int ans[260010];

int main() {
    int i, j, k;
    int n, m;
    int ed;
    int st;
    int x, y;
    int ix, iy;
    int pos1, pos2;
    scanf("%d %d",&n,&m);
    n++;
    m++;
    st = 0;
    ed = m * n - 1;
    tr[0]['\\'] = tr[1]['/'] = tr[2]['/'] = tr[3]['\\'] = 0;
    tr[0]['/'] = tr[1]['\\'] = tr[2]['\\'] = tr[3]['/'] = 1;
    for(i=1;i<n;i++) scanf("%s",o[i]+1);
    for(i=0;i<n;i++) {
        for(j=0;j<m;j++) {
            pos1 = m * i + j;
            for(k=0;k<4;k++) {
                x = i + dx[k];
                y = j + dy[k];
                ix = i + fx[k];
                iy = j + fy[k];
                if(x < 0 || y < 0 || x >= n || y >= m) continue;
                pos2 = m * x + y;
                edge[pos1].push_back(edge_info(pos2, tr[k][o[ix][iy]]));
            }
        }
    }
    for(i=0;i<n*m;i++) ans[i] = 0x7fffffff;
    
    q.push(node(0, 0));
    while(q.size()) {
        node tmp = q.top();
        q.pop();
        if(ans[tmp.pos] <= tmp.val) continue;
        ans[tmp.pos] = tmp.val;
        
        for(i=0;i<edge[tmp.pos].size();i++) {
            edge_info v = edge[tmp.pos][i];
            q.push(node(v.nxt, v.val + tmp.val));
        }
    }
    if(ans[ed] == 0x7fffffff) printf("NO SOLUTION\n");
    else printf("%d\n",ans[ed]);
    return 0;
}