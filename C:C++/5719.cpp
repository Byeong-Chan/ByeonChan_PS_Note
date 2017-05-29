#include <cstdio>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

struct node {
	int pre;
	int pos;
	int d;
	node() {}
	node(int ipre, int ipos, int id) {
		pre = ipre;
		pos = ipos;
		d = id;
	}
	bool operator < (const node &a) const {
		return d > a.d;
	}
};

struct edge {
	int dest;
	int cost;
	edge() {}
	edge(int idest, int icost) {
		dest = idest;
		cost = icost;
	}
};

bool chk[510];
bool block[510][510];
bool change[510][510];
int dist[510];
int al_dist[510];
vector<int> moth[510];
vector<edge> e[510];
priority_queue<node> q;
void dfs(int u) {
	int i, v;
	chk[u] = true;
	for(i=0;i<moth[u].size();i++) {
		v = moth[u][i];
		if(v == -1) break;
		block[v][u] = true;
		if(chk[v]) continue;
		dfs(v);
	}
}
int main() {
	int i, j;
	int n;
	int m;
	int x, y, z;
	int st, ed;
	int tmp;
	node here;
	while(1) {
		scanf("%d %d",&n,&m);
		if (n == 0 && m == 0) break;
		scanf("%d %d", &st, &ed);
		for(i=0;i<m;i++) {
			scanf("%d %d %d",&x,&y,&z);
			e[x].push_back(edge(y,z));
		}
		for(i=0;i<n;i++) dist[i] = 0x7fffffff;
		q.push(node(-1, st, 0));
		while(q.size()) {
			here = q.top();
			q.pop();
			if(here.d > dist[here.pos]) continue;
			moth[here.pos].push_back(here.pre);
			if(here.d == dist[here.pos]) continue;
			dist[here.pos] = here.d;

			for(i=0;i<(int)e[here.pos].size();i++) {
				edge &nxt = e[here.pos][i];
				tmp = nxt.cost + here.d;
				q.push(node(here.pos, nxt.dest, tmp)); 
			}
		}

		dfs(ed);

		for(i=0;i<n;i++) al_dist[i] = 0x7fffffff;
		q.push(node(-1, st, 0));
		while(q.size()) {
			here = q.top();
			q.pop();
			if(here.d >= al_dist[here.pos]) continue;
			al_dist[here.pos] = here.d;

			for(i=0;i<(int)e[here.pos].size();i++) {
				edge &nxt = e[here.pos][i];
				if(block[here.pos][nxt.dest]) continue;
				tmp = nxt.cost + here.d;
				q.push(node(here.pos, nxt.dest, tmp)); 
			}
		}
		if(al_dist[ed] == 0x7fffffff) printf("-1\n");
		else printf("%d\n",al_dist[ed]);

		for(i=0;i<n;i++) {
			moth[i].clear();
			e[i].clear();
			chk[i] = 0;
			for(j=0;j<n;j++) {
				block[i][j] = 0;
			}
		}
	}
	return 0;
}