#include <cstdio>
#include <algorithm>
#include <queue>
#include <vector>
using namespace std;
bool cant[110][110][110];
bool chk[110][110];
struct node {
	int pre;
	int here;
	int cst;
	bool operator< (const node &a) const {
		return this->cst > a.cst;
	}
};
struct dir {
	int nxt;
	int cst;
};
priority_queue<node> q;
vector<dir> edge[110];
int main() {
	int i, j, k, l;
	int n;
	int m, t;
	int s, x;
	int ch;
	int ans;
	node tmp, now;
	dir g;
	scanf("%d", &n);
	for (i = 1; i <= n; i++) {
		scanf("%d %d", &m, &t);
		for (j = 0; j < m; j++) {
			scanf("%d %d", &s, &x);
			for (k = 0; k < s; k++) {
				scanf("%d", &ch);
				cant[i][x][ch] = true;
			}
			g.cst = t;
			g.nxt = x;
			edge[i].push_back(g);
		}
	}

	tmp.cst = 0;
	tmp.here = 1;
	tmp.pre = 1;
	q.push(tmp);
	ans = 0x7fffffff;

	for (i = 2; i <= n; i++) chk[i][1] = true;
	while (q.size()) {
		now = q.top();
		q.pop();
		if (chk[now.pre][now.here]) continue;
		chk[now.pre][now.here] = true;
		if (now.here == n) {
			if (now.cst < ans) ans = now.cst;
			continue;
		}
		for (i = 0; i < edge[now.here].size(); i++) {
			g = edge[now.here][i];
			if (cant[now.here][g.nxt][now.pre]) continue;
			if (chk[now.here][g.nxt]) continue;

			tmp.pre = now.here;
			tmp.here = g.nxt;
			tmp.cst = now.cst + g.cst;
			q.push(tmp);
		}
	}
	if (ans == 0x7fffffff) printf("impossible\n");
	else {
		ans += t;
		printf("%d\n", ans);
	}
	return 0;
}