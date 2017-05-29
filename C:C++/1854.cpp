#include <cstdio>
#include <queue>
#include <algorithm>

using namespace std;

struct node {
	int pos;
	long long d;
	node(int ipos, int id) {
		pos = ipos;
		d = id;
	}
	node() {
		pos = 0;
		d = 0;
	}
	bool operator < (const node a) const {
		return d > a.d;
	}
};

struct edge {
	int dest;
	int cost;
	edge(int idest, int icost) {
		dest = idest;
		cost = icost;
	}
	edge() {
	}
};

vector<edge> e[1010];
priority_queue<long long> pq[1010];
priority_queue<node> q;

int main() {
	int i;
	int x, y, z;
	int n, m, k;
	node here;
	node nxt;
	scanf("%d %d %d",&n,&m,&k);
	for(i=0;i<m;i++) {
		scanf("%d %d %d",&x,&y,&z);
		e[x].push_back(edge(y, z));
	}
	pq[1].push(0);
	q.push(node(1, 0));
	while(q.size()) {
		here = q.top();
		q.pop();
		for(i=0;i<(int)e[here.pos].size();i++) {
			nxt.pos = e[here.pos][i].dest;
			nxt.d = here.d + e[here.pos][i].cost;
			if(pq[nxt.pos].size() < k) {
				pq[nxt.pos].push(nxt.d);
				q.push(nxt);
			}
			else if (pq[nxt.pos].top() > nxt.d) {
				pq[nxt.pos].pop();
				pq[nxt.pos].push(nxt.d);
				q.push(nxt);
			}
		}
	}
	for(i=1;i<=n;i++) {
		if(pq[i].size() == k) printf("%lld\n",pq[i].top());
		else printf("-1\n");
	}
	return 0;
}