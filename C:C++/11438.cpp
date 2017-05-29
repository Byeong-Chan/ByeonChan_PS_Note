#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <queue>

#include <cstring>

using namespace std;

const int MAX_N = 100010;
const int MAX_log = 20;

struct HLD { // for bidirected graph, and it must be tree.
    int root;
    int n; // 1 ~ n
    int cnt;
    int dptcnt;
    int segcnt;
    int power_num[MAX_log];
    int depth[MAX_N];
    int order[MAX_N];
    int tr_order[MAX_N];
    int range[MAX_N];
    int weight[MAX_N];
    int path[MAX_N];
    int dec_pos[MAX_N];
    int mothvalue[MAX_N];
    int HLDup[MAX_N];
    int rep_moth[MAX_log][MAX_N];
    vector<int> son[MAX_N];
    vector<int> dep_ord[MAX_N];
    vector<int> edge[MAX_N];
    vector<int> edgevalue[MAX_N];
    
    
    int first[MAX_N];
    int last[MAX_N];
        
    struct node {
        int value;
        node *left;
        node *right;
    };
    
    node *segtree[MAX_N];
        
    node *make_node() {
        return (node *)calloc(1, sizeof(node));
    }
        
    void seg_init(int st, int ed, node *here) {
        here->value = 0;
        if(st == ed) return;
            
        int mid = (st + ed) / 2;
            
        here->left = make_node();
        seg_init(st, mid, here->left);
        
        here->right = make_node();
        seg_init(mid+1, ed, here->right);
    }
        
    void seg_update(int st, int ed, int pos, int ch, node *here) {
        if (st == ed) {
            here->value = ch;
            return;
        }
        
        int mid = (st + ed) / 2;
        node *tmpl = here->left, *tmpr = here->right;
        if (mid >= pos) seg_update(st, mid, pos, ch, tmpl);
        else seg_update(mid + 1, ed, pos, ch, tmpr);
        
        here->value = max(tmpl->value, tmpr->value);
    }
    
    int seg_query(int st, int ed, int x, int y, node *here) {
        if (y < st || x > st) return 0;
        if (x <= st && y >= ed) return here->value;
        
        int mid = (st + ed) / 2;
        return max(seg_query(st, mid, x, y, here->left), seg_query(mid+1, ed, x, y, here->right));
    }
    
    void seg_clear(node *here) { // parameter will input root.
        if(here->left != NULL) seg_clear(here->left);
        if(here->right != NULL) seg_clear(here->right);
        free(here);
    }
    
    void init(int iN, int iroot) {
        n = iN;
        root = iroot;
        cnt = 0;
        segcnt = 0;
        dptcnt = 0;
        
        int i, t;
        for(i=0,t=1;i<MAX_log;i++,t<<=1) power_num[i] = t;
    }
    
    void add_edge(int x, int y, int val) {
        edge[x].push_back(y);
        edge[y].push_back(x);
        
        edgevalue[x].push_back(val);
        edgevalue[y].push_back(val);
    }
    
    int dfs_ordering(int u) {
        int i, v, maxv;
        depth[u] = dptcnt;
        order[u] = ++cnt;
        tr_order[cnt] = u;
        dep_ord[dptcnt].push_back(cnt);
        maxv = cnt;
        for (i=0;i<edge[u].size();i++) {
            v = edge[u][i];
            if (order[v] != 0) continue;
            son[u].push_back(v);
            dptcnt++;
            mothvalue[v] = edgevalue[u][i];
            maxv = dfs_ordering(v);
            dptcnt--;
            weight[u] += weight[v];
        }
        range[u] = maxv;
        weight[u]++;
        return maxv;
    }
    
    void make_dp() {
        int i, j;
        int k, l;
        int u;
        int st, ed;
        int tro;
        vector<int>::iterator it1, it2;
        for (i=0;i<n;i++) {
            for(j=0;j<dep_ord[i].size();j++) {
                u = tr_order[dep_ord[i][j]];
                for (k=0,l=1;i+l<n;k++,l<<=1) {
                    st = order[u];
                    ed = range[u];
                    it1 = lower_bound(dep_ord[i+l].begin(), dep_ord[i+l].end(), st);
                    it2 = upper_bound(dep_ord[i+l].begin(), dep_ord[i+l].end(), ed);
                    for(;it1 != it2; it1++) {
                        tro = tr_order[*it1];
                        rep_moth[k][tro] = u;
                    }
                }
            }
        }
    }
    
    void decomposition() {
        int i;
        int u;
        int v;
        int tmp, goal;
        int dec_number;
        bool sw;
        queue<int> q;
        q.push(root);
        while(q.size()) {
            u = q.front();
            q.pop();
            sw = true;
            for(i=0;i<son[u].size();i++) {
                v = son[u][i];
                if (weight[u] <= weight[v] * 2) {
                    path[v] = path[u] + 1;
                    sw = false;
                }
                q.push(v);
            }
            if (path[u] > 1 && sw) {
                dec_number = ++segcnt;
                first[segcnt-1] = 1;
                last[segcnt-1] = path[u];
                segtree[segcnt-1] = make_node();
                seg_init(1, path[u], segtree[segcnt-1]);
                
                goal = u;
                while(path[goal]) goal = rep_moth[0][goal];
                
                tmp = u;
                while(path[tmp]) {
                    HLDup[tmp] = goal;
                    dec_pos[tmp] = dec_number;
                    seg_update(1, path[u], path[tmp], mothvalue[tmp], segtree[segcnt-1]);
                    tmp = rep_moth[0][tmp];
                }
            }
        }
    }
    
    int get_lca(int x, int y) {
        if (depth[x] > depth[y]) swap(x, y);
        
        int i;
        int depx = depth[x], depy = depth[y];
        int gap;
        
        gap = depy - depx;
        for(i=MAX_log-1;i>=0;i--) {
            if (gap - power_num[i] < 0) continue;
            gap -= power_num[i];
            y = rep_moth[i][y];
        }
        depy = depth[y];
        
        if (x != y) {
            for(i=MAX_log-1;i>=0;i--) {
                if(depx - power_num[i] < 0) continue;
                if (rep_moth[i][x] == rep_moth[i][y]) continue;
                x = rep_moth[i][x];
                y = rep_moth[i][y];
            }
        }
        else return x;
        
        return rep_moth[0][x];
    }
    
    void edge_update(int x, int y, int val) {
        int tmp;
        if (rep_moth[0][y] == x) swap(x, y);
        
        mothvalue[x] = val;
        if (dec_pos[x] != 0) {
            tmp = dec_pos[x] - 1;
            seg_update(first[tmp], last[tmp], path[x], val, segtree[tmp]);
        }
    }
    int query_up(int goal, int x) {
        int tmp;
        int maxv = 0, val;
        while (x != goal) {
            if (dec_pos[x] != 0 && dec_pos[x] == dec_pos[goal]) {
                tmp = dec_pos[x] - 1;
                val = seg_query(first[tmp], last[tmp], path[goal] + 1, path[x], segtree[tmp]);
                if(maxv < val) maxv = val;
                x = goal;
                continue;
            }
            if (dec_pos[x] != 0) {
                tmp = dec_pos[x] - 1;
                val = seg_query(first[tmp], last[tmp], 1, path[x], segtree[tmp]);
                if (maxv < val) maxv = val;
                x = HLDup[x];
                continue;
            }
            if (maxv < mothvalue[x]) maxv = mothvalue[x];
            x = rep_moth[0][x];
        }
        return maxv;
    }
    int HLD_Query(int x, int y) {
        int goal = get_lca(x, y);
        return max(query_up(goal, x), query_up(goal, y));
    }
    
    void clear() {
        int i, j;
        for(i=0;i<segcnt;i++) {
            seg_clear(segtree[i]);
            first[i] = last[i] = 0;
        }
        segcnt = 0;
        cnt = 0;
        dptcnt = 0;
        
        for(i=0;i<n+3;i++) {
            path[i] = 0;
            range[i] = 0;
            mothvalue[i] = 0;
            depth[i] = 0;
            weight[i] = 0;
            order[i] = 0;
            tr_order[i] = 0;
            dec_pos[i] = 0;
            HLDup[i] = 0;
            dep_ord[i].clear();
            edge[i].clear();
            son[i].clear();
            edgevalue[i].clear();
            for(j=0;j<MAX_log;j++) rep_moth[j][i] = 0;
        }
    }
};


HLD dec;
int arr[MAX_N];

void solve() {
    int N, Q;
    int Root = 1;
    int i;
    int x, y, z;
    scanf("%d",&N);
    for(i=1;i<=N;i++) {
        scanf("%d",&arr[i]);
        arr[i]++;
    }
    dec.init(N, Root);
    for(i=1;i<=N;i++) {
        if(!arr[i]) continue;
        dec.add_edge(i, arr[i], 1);
    }
    dec.dfs_ordering(dec.root);
    dec.make_dp();
    dec.decomposition();
    
    char inp[20];
    int ans = 0;
    scanf("%d",&Q);
    for(i=0;i<Q;i++) {
        scanf("%s",inp);
        if (strcmp(inp, "update") == 0) {
            scanf("%d %d %d",&x,&y,&z);
            x++;
            y++;
            dec.edge_update(x,y,z);
        }
        else {
            scanf("%d %d",&x,&y);
            x++;
            y++;
            ans ^= dec.HLD_Query(x, y);
        }
    }
    dec.clear();
    printf("%d\n",ans);
}

int main() {
    int n, Q;
    int i;
    int x, y;
    scanf("%d",&n);
    for(i=0;i<n-1;i++) {
        scanf("%d %d",&x,&y);
        dec.add_edge(x, y, 1);
    }
    dec.init(n, 1);
    dec.dfs_ordering(dec.root);
    dec.make_dp();
    scanf("%d",&Q);
    for(i=0;i<Q;i++) {
        scanf("%d %d",&x,&y);
        printf("%d\n",dec.get_lca(x, y));
    }
    return 0;
}