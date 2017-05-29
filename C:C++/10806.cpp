#include <stdio.h>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;
typedef pair<int, int> ci;
vector<int> cn[100002];
vector<int> sav;
vector<int> cl;
vector<pair<int, int> > scon[100002];
queue<int> q;
int n, m;
int moth[100002];
int son[100002];
int p[100002];
bool nbridge[100002];
bool chk[100002];
void bfs() {
	int tmp;
	int _next;
	int e;
	q.push(1);
	chk[1] = true;
	moth[1] = -1;
	while (q.size()) {
		tmp = q.front();
		q.pop();
		e = 0;

		while (cn[tmp].size()) {
			_next = cn[tmp].back();
			cn[tmp].pop_back();
			if (moth[tmp] != _next || e > 0) {
				if (chk[_next]) sav.push_back(_next);
				else {
					moth[_next] = tmp;
					son[tmp]++;
					q.push(_next);
					chk[_next] = true;
				}
			}
			else e++;
		}
		while (sav.size()) {
			cn[tmp].push_back(sav.back());
			sav.pop_back();
		}
	}
}
void union_find(int d1, int d2, int key) {
	int tmp1 = d1, tmp2 = d2;
	int lca;
	p[tmp1] = key;
	p[tmp2] = key;
	while (1) {
		if (moth[tmp1] != -1) tmp1 = moth[tmp1];
		if (moth[tmp2] != -1) tmp2 = moth[tmp2];
		if (p[tmp2] == key) {
			lca = tmp2;
			break;
		}
		if (p[tmp1] == key) {
			lca = tmp1;
			break;
		}
		if (tmp1 == tmp2) {
			lca = tmp1;
			break;
		}
		if (tmp1 != 1) p[tmp1] = key;
		if (tmp2 != 1) p[tmp2] = key;
	}
	int _next;
	tmp1 = d1;
	while (tmp1 != lca) {
		_next = moth[tmp1];
		son[_next]--;
		moth[tmp1] = lca;
		son[lca]++;
		nbridge[tmp1] = true;
		tmp1 = _next;
	}
	tmp2 = d2;
	while (tmp2 != lca) {
		_next = moth[tmp2];
		son[_next]--;
		moth[tmp2] = lca;
		son[lca]++;
		nbridge[tmp2] = true;
		tmp2 = _next;
	}
}
int color[100010];
ci gr[100010];
void greedy() {
	int i;
	int now;
	int nex;
	ci tmp1, tmp2;
	int tmpcol;
	int precol;
	for (i = 1; i <= n; i++) {
		gr[i] = make_pair(-1, -1);
		color[i] = i;
		if (son[i] == 0) {
			q.push(i);
			if (!nbridge[i]) gr[i] = make_pair(i, -1);
		}
	}
	vector<pair<int, int> > savs;
	while (q.size()) {
		now = q.front();
		q.pop();
		if (now == 1) break;

		nex = moth[now];
		if (--son[nex] == 0) q.push(nex);
		if (gr[now].first == -1 && !nbridge[now]) {
			if(scon[color[now]].size() > 0) gr[now] = make_pair(now, 1);
			else gr[now] = make_pair(now, -1);
		}

		if (gr[nex].first != -1 && gr[now].first != -1) {
			if (scon[color[nex]].size() == 0) {
				tmpcol = color[nex] = color[now];
				if (gr[nex].second == -1 && gr[now].second == -1) {
					scon[tmpcol].push_back(make_pair(gr[now].first, gr[nex].first));
					gr[nex].first = -1;
				}
				else {
					tmp1 = scon[tmpcol].back();
					scon[tmpcol].pop_back();
					scon[tmpcol].push_back(make_pair(tmp1.first, gr[nex].first));
					gr[nex].first = tmp1.second;
					gr[nex].second = -1;
				}
			}
			else if (scon[color[now]].size() == 0) {
				tmpcol = color[now] = color[nex];
				if (gr[nex].second == -1 && gr[now].second == -1) {
					scon[tmpcol].push_back(make_pair(gr[now].first, gr[nex].first));
					gr[nex].first = -1;
				}
				else {
					tmp1 = scon[tmpcol].back();
					scon[tmpcol].pop_back();
					scon[tmpcol].push_back(make_pair(tmp1.first, gr[now].first));
					gr[nex].first = tmp1.second;
					gr[nex].second = -1;
				}
			}
			else {
				if(gr[nex].second == -1 && gr[now].second == -1) {
					scon[color[now]].push_back(make_pair(gr[now].first, gr[nex].first));
					gr[nex].first = -1;
				}
				else if (gr[nex].second == -1) {
					tmpcol = color[now];
					tmp1 = scon[tmpcol].back();
					scon[tmpcol].pop_back();
					savs.push_back(make_pair(tmp1.first, gr[nex].first));
					gr[nex].first = tmp1.second;
					gr[nex].second = -1;
				}
				else if (gr[now].second == -1) {
					tmpcol = color[nex];
					tmp1 = scon[tmpcol].back();
					scon[tmpcol].pop_back();
					savs.push_back(make_pair(tmp1.first, gr[now].first));
					gr[nex].first = tmp1.second;
					gr[nex].second = -1;
				}
				else {
					gr[nex].first = -1;
					gr[nex].second = -1;
				}

				if (scon[color[now]].size() < scon[color[nex]].size()) {
					precol = color[now];
					tmpcol = color[now] = color[nex];
				}
				else {
					precol = color[nex];
					tmpcol = color[nex] = color[now];
				}
				while (scon[precol].size()) {
					tmp1 = scon[tmpcol].back();
					tmp2 = scon[precol].back();
					savs.push_back(make_pair(tmp1.first, tmp2.first));
					savs.push_back(make_pair(tmp1.second, tmp2.second));
					scon[precol].pop_back();
					scon[tmpcol].pop_back();
				}
				while (savs.size()) {
					scon[tmpcol].push_back(savs.back());
					savs.pop_back();
				}
			}
		}
		else {
			if (scon[color[now]].size() > 0 && scon[color[nex]].size() > 0) {
				if (scon[color[now]].size() < scon[color[nex]].size()) {
					precol = color[now];
					tmpcol = color[now] = color[nex];
				}
				else {
					precol = color[nex];
					tmpcol = color[nex] = color[now];
				}
				while (scon[precol].size()) {
					tmp1 = scon[tmpcol].back();
					tmp2 = scon[precol].back();
					savs.push_back(make_pair(tmp1.first, tmp2.first));
					savs.push_back(make_pair(tmp1.second, tmp2.second));
					scon[precol].pop_back();
					scon[tmpcol].pop_back();
				}
				while (savs.size()) {
					scon[tmpcol].push_back(savs.back());
					savs.pop_back();
				}
				if (gr[nex].second == 1) gr[nex] = make_pair(-1, -1);
				if (gr[now].first != -1) {
					if(gr[now].second == -1) gr[nex] = gr[now];
					else gr[nex] = make_pair(-1, -1);
				}
			}
			else {
				if (scon[color[now]].size() < scon[color[nex]].size()) color[now] = color[nex];
				else color[nex] = color[now];
				if (gr[now].first != -1) gr[nex] = gr[now];
			}
		}
	}
}
int main() {
	int i;
	int x, y;
	int key = 0;
	scanf("%d %d", &n, &m);
	for (i = 0; i<m; i++) {
		scanf("%d %d", &x, &y);
		cn[x].push_back(y);
		cn[y].push_back(x);
	}
	bfs();
	for (i = 1; i <= n; i++) {
		while (cn[i].size()) {
			key++;
			x = i;
			y = cn[i].back();
			cn[i].pop_back();

			union_find(x, y, key);
		}
	}
	greedy();
	int tmpcol = color[1];
	if (gr[1].first != -1) {
		printf("%d\n", scon[tmpcol].size() + 1);
		printf("1 %d\n", gr[1].first);
	}
	else printf("%d\n", scon[tmpcol].size());
	ci tmp;
	while (scon[tmpcol].size()) {
		tmp = scon[tmpcol].back();
		printf("%d %d\n", tmp.first, tmp.second);
		scon[tmpcol].pop_back();
	}
	return 0;
}