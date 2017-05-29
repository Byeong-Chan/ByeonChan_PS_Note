#include <cstdio>
#include <map>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;
vector<int> phnode[300010];
int ph = 0;
int node[300010];
int num[300010];
int low[300010];
bool chk[300010];
int cnt = 0;
vector<int> edge[300010];
vector<int> trace;
string inp;
map<string, int> tr;
void dfs(int u) {
	chk[u] = true;
	low[u] = ++cnt;
	num[u] = cnt;
	bool isroot = true;
	trace.push_back(u);

	for (int i = 0; i<edge[u].size(); i++) {
		int v = edge[u][i];
		if (!chk[v]) dfs(v);
		if (low[u] > low[v]) {
			low[u] = low[v];
			isroot = false;
		}
	}

	if (isroot) {
		ph++;
		while (true) {
			int x = trace.back();
			trace.pop_back();
			node[num[x]] = ph;
			phnode[ph].push_back(x);
			low[x] = 0x7fffffff;

			if (x == u) break;
		}
	}
}
void scc(int n) {
	for (int i = 1; i <= n; i++) {
		if (chk[i]) continue;
		dfs(i);
	}
}
int main() {
	int i;
	int n = 0, t, x, y;
	char o[23], u[23], cm;
	scanf("%d", &t);
	for (i = 0; i < t; i++) {
		scanf("%s %c %s", o, &cm, u);
		if (tr[o] == 0) tr[o] = ++n;
		if (tr[u] == 0) tr[u] = ++n;

		x = tr[o];
		y = tr[u];

		if (cm == '<') edge[x].push_back(y);
		else edge[y].push_back(x);
	}
	scc(n);

	for (i = 1; i <= ph; i++) if (phnode[i].size() > 1) break;
	if (i <= ph) printf("impossible\n");
	else printf("possible\n");
	return 0;
}