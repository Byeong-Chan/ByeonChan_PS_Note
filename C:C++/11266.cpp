#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
int cnt = 0;
int order[10010], low[10010];
bool chk[10010];
bool cutv[10010];
vector<int> edge[10010];
void dfs(int u, int pre) {
	int child = 0;
	int v, sz = edge[u].size();
	chk[u] = true;
	order[u] = low[u] = ++cnt;
	for (int i = 0; i < sz; i++) {
		v = edge[u][i];
		if (pre == v) continue;

		if (chk[v]) low[u] = min(low[u], order[v]);
		else {
			child++;
			dfs(v, u);
			low[u] = min(low[u], low[v]);
			if (!pre && child >= 2) cutv[u] = true;
			if (pre && low[v] >= order[u]) cutv[u] = true;
		}
	}
}
int main() {
	int i;
	int x, y;
	int n, m;
	int ans = 0;
	scanf("%d %d", &n, &m);
	for (i = 0; i < m; i++) {
		scanf("%d %d", &x, &y);
		edge[x].push_back(y);
		edge[y].push_back(x);
	}

	for (i = 1; i <= n;i++) if(!chk[i]) dfs(i, 0);

	for (i = 1; i <= n; i++) if (cutv[i]) ans++;
	printf("%d\n", ans);
	for (i = 1; i <= n; i++) if(cutv[i]) printf("%d ", i);
	return 0;
}