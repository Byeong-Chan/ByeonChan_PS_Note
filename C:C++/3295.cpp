#include <cstdio>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;
class Bipartite {
public:
    void init(int n, int m) {
        this->n = n;
        this->m = m;
        last.resize(n+1);
        match.resize(m+1);
        level.resize(n+1);
        use.resize(n+1);
        chk.resize(n+1);
        fill(last.begin(), last.end(), -1);
        fill(match.begin(), match.end(), -1);
        chknum = 0;
    }
    void add_edge(int x, int y) {
        pre.push_back(last[x]);
        last[x] = (int)edge.size();
        edge.push_back(y);
    }
    bool bfs() {
        bool flag = false;
        fill(level.begin(), level.end(), -1);
        queue<int> q;
        for(int i=1;i<=n;i++) if(!use[i]) q.push(i), level[i] = 0;
        while(q.size()) {
            int here = q.front();
            q.pop();
            for(int i=last[here];i>=0;i=pre[i]) {
                int &v = edge[i];
                if(!(match[v] + 1)) {
                    flag = true;
                    continue;
                }
                if(level[match[v]] + 1) continue;
                level[match[v]] = level[here] + 1;
                q.push(match[v]);
            }
        }
        return flag;
    }
    bool dfs(int u) {
        chk[u] = chknum;
        for(int i=last[u];i>=0;i=pre[i]) {
            int &v = edge[i];
            if(match[v] + 1 && level[u] + 1 != level[match[v]]) continue;
            if(chk[match[v]] != chknum && (match[v] == -1 || dfs(match[v]))) {
                use[u] = true;
                match[v] = u;
                return true;
            }
        }
        return false;
    }
    int max_match() {
        int ans = 0, tmp;
        while(bfs()) {
            tmp = ans;
            chknum++;
            for(int i=1;i<=n;i++) if(!use[i] && chk[i] != chknum && dfs(i)) ans++;
            if(tmp == ans) break;
        }
        return ans;
    }
    void clear() {
        n = m = chknum = 0;
        use.clear();
        chk.clear();
        last.clear();
        pre.clear();
        edge.clear();
        match.clear();
        level.clear();
    }
private:
    int n;
    int m;
    int chknum;
    vector<bool> use;
    vector<int> chk;
    vector<int> last;
    vector<int> pre;
    vector<int> edge;
    vector<int> match;
    vector<int> level;
};

int main() {
    int i, n, m;
    int t;
    Bipartite dec;
    scanf("%d",&t);
    while(t--) {
        scanf("%d %d",&n,&m);
        dec.clear();
        dec.init(n, n);
        for(i=0;i<m;i++) {
            int x, y;
            scanf("%d %d",&x,&y);
            dec.add_edge(x+1, y+1);
        }
        printf("%d\n",dec.max_match());
    }
    return 0;
}