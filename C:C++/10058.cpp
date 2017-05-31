#include <cstdio>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
struct point {
    int x;
    int y;
};
struct fastmatch {
public:
    fastmatch(vector<vector<int> > &idist, int id): dist(idist), d(id) {}
    void clear() {
        v1.clear();
        v2.clear();
        level.clear();
        visit.clear();
        match.clear();
        matched.clear();
    }
    void add_point1(int u) {
        v1.push_back(u);
    }
    void add_point2(int v) {
        v2.push_back(v);
    }
    void init() {
        level.resize(v1.size());
        visit.resize(v1.size());
        matched.resize(v1.size(), -1);
        match.resize(v2.size(), -1);
    }
    void bfs() {
        fill(level.begin(), level.end(), -1);
        queue<int> q;
        for(int u = 0; u < v1.size(); u++) {
            if(matched[u] != -1) continue;
            q.push(u);
            level[u] = 0;
        }
        while(q.size()) {
            int u = q.front();
            q.pop();
            
            for(int v = 0; v < v2.size(); v++) {
                if(dist[v1[u]][v2[v]] <= d) continue;
                if(match[v] == -1) continue;
                if(level[match[v]] == -1) continue;
                level[match[v]] = level[u] + 1;
                q.push(match[v]);
            }
        }
    }
    bool dfs(int u) {
        if(visit[u]) return false;
        visit[u] = true;
        for(int v = 0; v < v2.size(); v++) {
            if(dist[v1[u]][v2[v]] <= d) continue;
            if(match[v] != -1 && level[match[v]] != level[u] + 1) continue;
            if(match[v] == -1 || dfs(match[v])) {
                matched[u] = v;
                match[v] = u;
                return true;
            }
        }
        return false;
    }
    int max_matching() {
        int ans = 0;
        while(1) {
            bfs();
            fill(visit.begin(), visit.end(), false);
            bool flag = false;
            for(int u = 0; u < v1.size(); u++) {
                if(matched[u] == -1 && dfs(u)) {
                    flag = true;
                    ans++;
                }
            }
            if(!flag) break;
        }
        return ans;
    }
    void get_delv(int v) {
        if(delv[v]) return;
        delv[v] = true;
        int u = match[v];
        for(int vn = 0; vn < v2.size(); vn++) {
            if(match[vn] == -1) continue;
            if(dist[v1[u]][v2[vn]] <= d) continue;
            get_delv(vn);
        }
    }
    void get_delu(int u) {
        if(delu[u]) return;
        delu[u] = true;
        int v = matched[u];
        for(int un = 0; un < v1.size(); un++) {
            if(matched[un] == -1) continue;
            if(dist[v1[un]][v2[v]] <= d) continue;
            get_delu(un);
        }
    }
    vector<int> find_vertex_cover() {
        delu.clear();
        delu.resize(v1.size(), 0);
        delv.clear();
        delv.resize(v2.size(), 0);
        for(int u = 0; u < v1.size(); u++) {
            if(matched[u] != -1) continue;
            for(int v = 0; v < v2.size(); v++) {
                if(match[v] == -1) continue;
                if(dist[v1[u]][v2[v]] <= d) continue;
                get_delv(v);
            }
        }
        for(int v = 0; v < v2.size(); v++) {
            if(match[v] != -1) continue;
            for(int u = 0; u < v1.size(); u++) {
                if(matched[u] == -1) continue;
                if(dist[v1[u]][v2[v]] <= d) continue;
                get_delu(u);
            }
        }
        for(int u = 0; u < v1.size(); u++) {
            if(matched[u] == -1) continue;
            if(delu[u]) continue;
            if(delv[matched[u]]) continue;
            delu[u] = true;
        }
        vector<int> net;
        for(int u = 0; u < v1.size(); u++) {
            if(delu[u]) continue;
            net.push_back(v1[u]);
        }
        for(int v = 0; v < v2.size(); v++) {
            if(delv[v]) continue;
            net.push_back(v2[v]);
        }
        return net;
    }
private:
    vector<int> v1;
    vector<int> v2;
    vector<int> level;
    vector<int> match;
    vector<int> matched;
    vector<int> visit;
    
    vector<int> delu;
    vector<int> delv;
    
    const int d;
    const vector<vector<int> > &dist;
};
int main() {
    int n, d;
    scanf("%d %d", &n, &d);
    d *= d;
    vector<point> o(n);
    vector<vector<int> > dist(n, vector<int>(n));
    fastmatch dec(dist, d);
    for(int i=0;i<n;i++) scanf("%d %d",&o[i].x,&o[i].y);
    for(int i=0;i<n;i++) {
        for(int j=0;j<n;j++) {
            dist[i][j] = (o[i].x - o[j].x) * (o[i].x - o[j].x) + (o[i].y - o[j].y) * (o[i].y - o[j].y);
        }
    }
    vector<int> ans;
    for(int i=0;i<n;i++) {
        for(int j=i+1;j<n;j++) {
            if(dist[i][j] > d) continue;
            dec.clear();
            for(int k=0;k<n;k++) {
                if(i == k || j == k) continue;
                if(dist[i][k] <= dist[i][j] &&  dist[j][k] <= dist[i][j]) {
                    if((o[j].x - o[i].x) * (o[k].y - o[i].y)
                       - (o[k].x - o[i].x) * (o[j].y - o[i].y) >= 0) dec.add_point1(k);
                    else dec.add_point2(k);
                }
            }
            dec.init();
            dec.max_matching();
            vector<int> p = dec.find_vertex_cover();
            p.push_back(i);
            p.push_back(j);
            if(ans.size() < p.size()) ans = p;
        }
    }
    if(ans.size() == 0) {
        printf("1\n1\n");
        return 0;
    }
    printf("%d\n", (int)ans.size());
    sort(ans.begin(), ans.end());
    for(auto &c : ans) printf("%d ",c + 1);
    printf("\n");
    return 0;
}
