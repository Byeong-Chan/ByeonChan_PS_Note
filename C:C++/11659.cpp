#include <cstdio>
#include <algorithm>
using namespace std;
int BLOCK_SIZE = 500;
struct bung {
	int l;
	int r;
	int order;
	bool operator< (const bung &a) const {
		if (this->l / BLOCK_SIZE != a.l / BLOCK_SIZE) return this->l / BLOCK_SIZE < a.l / BLOCK_SIZE;
		if (this->r != a.r) return this->r < a.r;
		return this->l < a.l;
	}
}q[100010];
int fast_sqrt(int num) {
	int st = 1;
	int ed = num;
	int mid;
	while (st < ed) {
		mid = (st + ed) >> 1;
		if (mid * mid > num) ed = mid;
		else st = mid + 1;
	}
	return st - 1;
}
int o[100010];
int ans[100010];
int main() {
	int i;
	int n, Q;
	int hap = 0;
	int mo_left = 0, mo_right = -1;
	bung tmpq;
	scanf("%d %d", &n, &Q);
	//BLOCK_SIZE = fast_sqrt(n);
	for (i = 0; i < n; i++) scanf("%d", o + i);
	for (i = 0; i < Q; i++) {
		scanf("%d %d", &q[i].l, &q[i].r);
		q[i].order = i;
		q[i].l--;
		q[i].r--;
	}
	sort(q, q + Q);
	for (i = 0; i < Q; i++) {
		tmpq = q[i];
		while (tmpq.l < mo_left) hap += o[--mo_left];
		while (tmpq.l > mo_left) hap -= o[mo_left++];
		while (tmpq.r < mo_right) hap -= o[mo_right--];
		while (tmpq.r > mo_right) hap += o[++mo_right];
		ans[tmpq.order] = hap;
	}
	for (i = 0; i < Q; i++) printf("%d\n", ans[i]);
	return 0;
}