#include <cstdio>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;
struct bung {
	int x;
	int y;
}o[250010], u[250010];
int chk[510][510];
struct node {
	int pos;
	int cst;
	int pre;
	bool operator< (const node &a) const {
		return this->cst > a.cst;
	}
};
priority_queue<node> q;
vector<node> edge[250010];
int ans[250010];
int main() {
	int i, n;
	int m;
	int front, back;
	int left, right;
	int x, y;
	int cntx = 0;
	int cnty = -1;
	node here, nxt;
	scanf("%d", &n);
	m = n*n - n / 2;
	for (i = 1; i <= m; i++) {
		cnty++;
		if (cntx & 1) {
			if (cnty == n - 1) {
				cntx++;
				cnty = 0;
			}
		}
		else {
			if (cnty == n) {
				cntx++;
				cnty = 0;
			}
		}
		chk[cntx][cnty] = i;

		scanf("%d %d", &x, &y);
		o[i].x = x;
		o[i].y = y;

		if (cntx & 1) {
			front = cntx - 1 < 0 ? -1 : chk[cntx - 1][cnty];
			back = cntx - 1 < 0 ? -1 : chk[cntx - 1][cnty + 1];
			left = cnty - 1 < 0 ? -1 : chk[cntx][cnty - 1];
			right = cnty + 1 >= n - 1 ? -1 : chk[cntx][cnty + 1];
		}
		else {
			front = cntx - 1 < 0 && cnty - 1 < 0 ? -1 : chk[cntx - 1][cnty - 1];
			back = cntx - 1 < 0 ? -1 : chk[cntx - 1][cnty];
			left = cnty - 1 < 0 ? -1 : chk[cntx][cnty - 1];
			right = cnty + 1 >= n ? -1 : chk[cntx][cnty + 1];
		}

		if (front != -1) {
			if (o[i].x == o[front].y) {
				edge[i].push_back({ front, 1 , -1 });
				edge[front].push_back({ i, 1, -1 });
			}
		}
		if (left != -1) {
			if (o[i].x == o[left].y) {
				edge[i].push_back({ left, 1 , -1 });
				edge[left].push_back({ i, 1, -1 });
			}
		}
		if (right != -1) {
			if (o[i].y == o[right].x) {
				edge[i].push_back({ right, 1 , -1 });
				edge[right].push_back({ i, 1, -1 });
			}
		}
		if (back != -1) {
			if (o[i].y == o[back].x) {
				edge[i].push_back({ back, 1, -1 });
				edge[back].push_back({ i, 1, -1 });
			}
		}
	}
	q.push({ 1, 1, -1 });
	while (q.size()) {
		here = q.top();
		q.pop();
		if (u[here.pos].x != 0) continue;
		u[here.pos].x = here.cst;
		u[here.pos].y = here.pre;
		for (i = 0; i < (int)edge[here.pos].size(); i++) {
			nxt = edge[here.pos][i];
			q.push({ nxt.pos, here.cst + nxt.cst, here.pos });
		}
	}
	for (i = m; i >= 1; i--) {
		if (u[i].x == 0) continue;
		break;
	}
	int sz = 0;
	while (1) {
		if (i == -1) break;
		ans[sz++] = i;
		i = u[i].y;
	}
	printf("%d\n", sz);
	for (i = sz - 1; i >= 0; i--) printf("%d ", ans[i]);
	printf("\n");
	return 0;
}