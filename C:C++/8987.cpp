#include <cstdio>
#include <algorithm>
#include <vector>
#include <queue>
#include <set>
using namespace std;
struct bung {
	long long x1;
	long long x2;
	long long h;
	bool operator< (const bung &a) const {
		if(this->h != a.h) return this->h < a.h;
		else return this->x1 < a.x1;
	}
}o[300010];
struct node {
	long long x;
	long long y;
	int pre;
	bool operator< (const node &a) const {
		return this->x < a.x;
	}
};
struct qnode {
	long long water;
	int nxtsib;
	bool operator< (const qnode &a) const {
		return this->water < a.water;
	}
};
int moth[300010];
long long waterh[300010];
int son[300010];
multiset<node> q;
long long water[300010];
bool chk[300010];
int que[300010];
int pos[300010];
vector<int> sib[300010];
priority_queue<qnode> pq;
int main() {
	int i, n, k;
	int x, y;
	int m = 0;
	int prex, prey;
	int d, nxt;
	int cnt = 0;
	int tail, head;
	long long ans;
	node tmp, now;
	qnode pt;
	scanf("%d", &n);
	for (i = 0; i < n; i++) {
		scanf("%d %d", &x, &y);
		if (i > 0 && !(i & 1)) {
			o[m].x1 = prex;
			o[m].x2 = x;
			o[m].h = y;
			m++;
		}
		prex = x;
		prey = y;
	}
	scanf("%d", &k);

	sort(o, o + m);

	tmp.x = 0;
	tmp.y = x;
	tmp.pre = ++cnt;
	q.insert(tmp);
	multiset<node>::iterator it;
	for (i = 0; i < m; i++) {
		tmp.x = o[i].x1;
		tmp.y = o[i].x2;
		it = q.lower_bound(tmp);
		if (it == q.end()) --it;
		else if (it->x > tmp.x) --it;
		now = *it;
		if (!chk[now.pre]) {
			waterh[now.pre] = o[i].h;
			water[now.pre] = (long long)(o[i].h - waterh[moth[now.pre]]) * (now.y - now.x);
			chk[now.pre] = true;
		}

		q.erase(it);

		if (now.x < tmp.x && now.y > tmp.y) {
			tmp.pre = ++cnt;
			moth[cnt] = now.pre;
			son[now.pre]++;
			sib[now.pre].push_back(cnt);

			tmp.x = now.x;
			tmp.y = o[i].x1;
			q.insert(tmp);


			tmp.pre = ++cnt;
			moth[cnt] = now.pre;
			son[now.pre]++;
			sib[now.pre].push_back(cnt);

			tmp.x = o[i].x2;
			tmp.y = now.y;
			q.insert(tmp);
		}
		else if (now.x == tmp.x && now.y > tmp.y) {
			tmp.pre = ++cnt;
			moth[cnt] = now.pre;
			son[now.pre]++;
			sib[now.pre].push_back(cnt);

			tmp.x = o[i].x2;
			tmp.y = now.y;
			q.insert(tmp);
		}
		else if (now.x < tmp.x && now.y == tmp.y) {
			tmp.pre = ++cnt;
			moth[cnt] = now.pre;
			son[now.pre]++;
			sib[now.pre].push_back(cnt);

			tmp.x = now.x;
			tmp.y = o[i].x1;
			q.insert(tmp);
		}
	}
	tail = head = 0;
	for (i = 1; i <= cnt; i++) {
		waterh[i] = water[i];
		water[i] = 0;
		if (son[i] == 0) {
			que[tail++] = i;
			water[i] = waterh[i];
		}
	}
	while (tail > head) {
		d = que[head++];
		nxt = moth[d];
		if (--son[nxt] == 0) que[tail++] = nxt;
		if (water[d] + waterh[nxt] > water[nxt]) {
			water[nxt] = water[d] + waterh[nxt];
			pos[nxt] = d;
		}
	}

	pt.nxtsib = 1;
	pt.water = water[1];
	pq.push(pt);
	ans = 0;
	int sz;
	while (k--) {
		if (pq.size() == 0) break;
		pt = pq.top();
		pq.pop();
		ans += pt.water;
		d = pt.nxtsib;
		while (d) {
			nxt = pos[d];
			sz = sib[d].size();
			for (i = 0; i < sz; i++) {
				if (sib[d][i] != nxt) {
					pt.nxtsib = sib[d][i];
					pt.water = water[pt.nxtsib];
					pq.push(pt);
				}
			}
			water[d] = 0;
			d = nxt;
		}
	}
	printf("%lld", ans);
	return 0;
}