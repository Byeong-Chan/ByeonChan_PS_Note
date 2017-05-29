#include <stdio.h>
#include <vector>
#include <queue>
#include <algorithm>
#include <functional>
using namespace std;
typedef pair<int, int> pr;
int moth[50001], mothcst[50001];
struct bung {
	int x;
	int y;
	int cst;
}o[200001];
struct fsort {
	bool operator() (pr a, pr b) {
		return o[a.second].cst > o[b.second].cst;
	}
};
vector<pr> edge[50001];
priority_queue<pr, vector<pr>, fsort > q;
int n, m;
int chk[50001];
bool use[200001];
int secondmin = 0x7fffffff;
int ans = 0;
bool sw = false;
void mst() {
	int i;
    int s = 1;
	pr tmp, nex;
	for (i = 0; i < (int)edge[1].size(); i++) q.push(edge[1][i]);
	moth[1] = -1;
	while (q.size()) {
		tmp = q.top();
		q.pop();
		if (moth[tmp.first] != 0) continue;
        s++;
		use[tmp.second] = true;
		ans += (mothcst[tmp.first] = o[tmp.second].cst);
		if (tmp.first == o[tmp.second].x) moth[tmp.first] = o[tmp.second].y;
		else moth[tmp.first] = o[tmp.second].x;
		for (i = 0; i < (int)edge[tmp.first].size(); i++) q.push(edge[tmp.first][i]);
	}
    if(s < n) sw = true;
}
void union_find(int x, int y, int k, int ncst) {
	int lca;
	int tmpx = x, tmpy = y;
	while (1) {
		if (x == y) {
			lca = x;
			break;
		}
		if (moth[x] != -1 && chk[moth[x]] == k) {
			lca = moth[x];
			break;
		}
		if (moth[y] != -1 && chk[moth[y]] == k) {
			lca = moth[y];
			break;
		}
		chk[x] = k;
		chk[y] = k;
		if (moth[x] != -1) x = moth[x];
		if (moth[y] != -1) y = moth[y];
	}

	int tmpcst;
	int nex;
	while (lca != tmpx) {
		tmpcst = ncst - mothcst[tmpx];
		if (secondmin > tmpcst && tmpcst > 0) secondmin = tmpcst;
		nex = moth[tmpx];
		moth[tmpx] = lca;
		tmpx = nex;
	}
	while (lca != tmpy) {
		tmpcst = ncst - mothcst[tmpy];
		if (secondmin > tmpcst && tmpcst > 0) secondmin = tmpcst;
		nex = moth[tmpy];
		moth[tmpy] = lca;
		tmpy = nex;
	}
}
int main() {
	int i;
	int x, y, z;
	scanf("%d %d", &n, &m);
	for (i = 0; i < m; i++) {
		scanf("%d %d %d", &x, &y, &z);
		o[i].x = x;
		o[i].y = y;
		o[i].cst = z;

		edge[x].push_back(make_pair(y, i));
		edge[y].push_back(make_pair(x, i));
	}
	mst();
    if(sw == true) {
        printf("-1");
        return 0;
    }
	for (i = 0; i < m; i++) if (!use[i]) q.push(make_pair(0, i));
	i = 0;
	while (q.size()) {
		i++;
		pr tmp = q.top();
		q.pop();
		union_find(o[tmp.second].x, o[tmp.second].y, i, o[tmp.second].cst);
	}
	if (secondmin == 0x7fffffff) printf("-1");
	else printf("%d", ans + secondmin);
	return 0;
}