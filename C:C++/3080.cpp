#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <queue>
#include <algorithm>

#define mod 1000000007

using namespace std;

struct bung {
	char str[3110];
	bool operator< (const bung &a) const {
		if (strcmp(this->str, a.str) < 0) return true;
		else return false;
	}
}o[3010];
struct node {
	short num;
	short sum;
	short cnt;
	short son;
	node *moth;
	node *nxt[26];
};
void create(node *v, int ch) {
	v->nxt[ch] = (node *)calloc(1, sizeof(node));
	v->nxt[ch]->num = v->nxt[ch]->sum = 1;
	v->nxt[ch]->moth = v;
}
queue<node *> q;
void dfs(node *v) {
	bool sw = true;
	for (int i = 0; i < 26; i++) {
		if (v->nxt[i] == NULL) continue;
		sw = false;
		dfs(v->nxt[i]);
	}
	if (sw) q.push(v);
}
char *ss[3010];
int howl[3010];
int main() {
	int i;
	int n, tmp;
	char *k, *j1, *j2;
	long long h[3010];
	long long ans = 1;
	node *root = (node *)calloc(1, sizeof(node)), *d, *anc;
	scanf("%d", &n);
	h[0] = 1;
	for (i = 1; i <= 3000; i++) {
		h[i] = 1;
		h[i] *= h[i - 1];
		h[i] %= mod;
		h[i] *= i;
		h[i] %= mod;
	}
	for (i = 0; i < n; i++) scanf("%s", o[i].str);
	sort(o, o + n);
	for (i = 0; i < n - 1; i++) {
		for (j1 = o[i].str, j2 = o[i + 1].str;; j1++, j2++) {
			howl[i]++;
			if (*j1 == '\0' || *j2 == '\0') break;
			if (*j1 != *j2) break;
		}
		ss[i] = j1 + 2;
		if (i > 0) {
			if (howl[i] < howl[i - 1]) ss[i] = j1 + 2 + (howl[i - 1] - howl[i]);
		}
	}
	for (i = 0; i < n - 1; i++) *(ss[i]) = '\0';
	for (i = 0; i < n;i++) {
		d = root;
		root->sum++;
		root->num++;
		for (k = o[i].str; ; k++) {
			if (*k == '\0') break;
			tmp = *k - 65;
			if (d->nxt[tmp] == NULL) {
				d->son++;
				create(d, tmp);
				d = d->nxt[tmp];
			}
			else {
				d = d->nxt[tmp];
				d->sum++;
				d->num++;
			}
		}
	}
	dfs(root);
	while (q.size()) {
		d = q.front();
		q.pop();
		if (d == root) {
			ans *= h[d->sum + d->cnt];
			ans %= mod;
			break;
		}
		anc = d->moth;
		if (anc->son-- == 1) q.push(anc);
		ans *= h[d->sum + d->cnt];
		ans %= mod;
		anc->sum -= d->num;
		anc->cnt++;
		free(d);
	}
	printf("%lld", ans);
	free(root);
	return 0;
}