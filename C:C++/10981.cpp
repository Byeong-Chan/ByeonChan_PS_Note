#include <stdio.h>
#include <algorithm>
#include <string>
#include <map>
using namespace std;
struct bung {
	string univ;
	string team;
	int solv;
	int pe;
}o[100001];
map<string, pair<int, string> > chk;
pair<int, string> ans[110];
bool cmp(bung a, bung b) {
	if (a.solv != b.solv) return a.solv > b.solv;
	return a.pe < b.pe;
}
char tmp[32];
int main() {
	int i;
	int n, k;
	scanf("%d %d", &n, &k);
	for (i = 0; i < n; i++) {
		scanf("%s", tmp);
		o[i].univ = tmp;
		scanf("%s", tmp);
		o[i].team = tmp;
		scanf("%d %d", &o[i].solv, &o[i].pe);
	}
	sort(o, o + n, cmp);
	for (i = 0; i < n; i++) {
		if (chk.find(o[i].univ) == chk.end()) chk[o[i].univ] = make_pair(i, o[i].team);
		if (chk.size() == k) break;
	}
	map<string, pair<int, string> >::iterator it;
	int p = 0;
	for (it = chk.begin(); it != chk.end(); it++) ans[p++] = it->second;
	sort(ans, ans + p);
	for (i = 0; i < p; i++) printf("%s\n", ans[i].second.data());
	return 0;
}