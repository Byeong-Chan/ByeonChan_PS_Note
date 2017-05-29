#include <cstdio>
#include <algorithm>
#include <cstring>
#include <queue>
using namespace std;
int trie[1000030][4];
int trans[222];
int fail[1000030];
bool chk[1000030];
char dna[1000010], mu[110];
struct bung {
	int i;
	int j;
};
queue<bung> q;
int main() {
	trans['A'] = 0; trans['C'] = 1; trans['G'] = 2; trans['T'] = 3;

	int t;
	int i, j, k;
	int d;
	int n, m;
	int nxt;
	int cnt;
	int ans;
	bung tmp;
	bung now;
	scanf("%d", &t);
	fail[0] = -1;
	while (t--) {
		scanf("%d%d\n", &n, &m);
		fgets(dna, 1000010, stdin);
		fgets(mu, 110, stdin);
		memset(trie, 0, sizeof(trie));
		memset(chk, 0, sizeof(chk));
		cnt = 0;
		ans = 0;
		for (i = 0; i < m;i++) {
			for (j = i + 1; j <= m; j++) {
				reverse(mu + i, mu + j);
				d = 0;
				for (k = 0; k < m; k++) {
					nxt = trans[mu[k]];
					if (trie[d][nxt] == 0) d = trie[d][nxt] = ++cnt;
					else d = trie[d][nxt];
				}
				chk[d] = true;
				reverse(mu + i, mu + j);
			}
		}
		tmp.i = -1;
		tmp.j = 0;
		q.push(tmp);
		while (q.size()) {
			now = q.front();
			q.pop();
			for (k = 0; k < 4; k++) {
				tmp = now;
				if (trie[tmp.j][k] == 0) continue;
				while (1) {
					if (tmp.i == -1 || (tmp.i != -1 && trie[tmp.i][k] > 0)) {
						if (tmp.i == -1) tmp.i = 0;
						else tmp.i = trie[tmp.i][k];
						tmp.j = trie[tmp.j][k];
						fail[tmp.j] = tmp.i;
						if (chk[tmp.i] == true) chk[tmp.j] = true;
						q.push(tmp);
						break;
					}
					else tmp.i = fail[tmp.i];
				}
			}
		}
		i = 0;
		j = 0;
		while (1) {
			if (j == n) break;
			nxt = trans[dna[j]];
			if (i == -1 || (i != -1 && trie[i][nxt] > 0)) {
				if (i == -1) i = 0;
				else i = trie[i][nxt];
				j++;
			}
			else i = fail[i];
			if (i != -1 && chk[i]) ans++;
		}
		printf("%d\n", ans);
	}
	return 0;
}