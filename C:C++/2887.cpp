#include <cstdio>
#include <algorithm>
#include <queue>
#include <functional>
#include <vector>
using namespace std;
typedef pair<int, int> pr;
typedef pair<int, pr > dpr;

#define mp(p, q) make_pair(p, q)

struct bung {
	int c;
	int num;
}x[100010], y[100010], z[100010];
bool cmp(bung a, bung b) {
	return a.c < b.c;
}
priority_queue<dpr, vector<dpr >, greater<dpr > > con;
int chk[100001];
vector<int> pos[100010];
int main() {
	int i;
	int n;
	long long ans = 0;
	int t = 0;
	scanf("%d",&n);
	for(i=0;i<n;i++) {
		scanf("%d %d %d",&x[i].c, &y[i].c, &z[i].c);
		x[i].num = y[i].num = z[i].num = i;
	}
	sort(x, x+n, cmp);
	sort(y, y+n, cmp);
	sort(z, z+n, cmp);
	for(i=0;i<n-1;i++) {
		con.push(mp(x[i+1].c-x[i].c, mp(x[i+1].num, x[i].num)));
		con.push(mp(y[i+1].c-y[i].c, mp(y[i+1].num, y[i].num)));
		con.push(mp(z[i+1].c-z[i].c, mp(z[i+1].num, z[i].num)));
	}
	dpr dtmp;
	pr tmp;
	int r, l;
	while(con.size()) {
		dtmp = con.top();
		tmp = dtmp.second;
		con.pop();

		ans += dtmp.first;
		if(!chk[tmp.first] && !chk[tmp.second]) {
			chk[tmp.first] = chk[tmp.second] = ++t;
			pos[t].push_back(tmp.first);
			pos[t].push_back(tmp.second);
		}
		else if(!chk[tmp.first]) {
			chk[tmp.first] = chk[tmp.second];
			pos[chk[tmp.second]].push_back(tmp.first);
		}
		else if(!chk[tmp.second]) {
			chk[tmp.second] = chk[tmp.first];
			pos[chk[tmp.first]].push_back(tmp.second);
		}
		else {
			if(chk[tmp.first] == chk[tmp.second]) ans -= dtmp.first;
			else {
				r = chk[tmp.first];
				l = chk[tmp.second];
				if(pos[r].size() > pos[l].size()) {
					while(pos[l].size()) {
						pos[r].push_back(pos[l].back());
						chk[pos[l].back()] = r;
						pos[l].pop_back();
					}
				}
				else {
					while(pos[r].size()) {
						pos[l].push_back(pos[r].back());
						chk[pos[r].back()] = l;
						pos[r].pop_back();
					}
				}
			}
		}
	}
	printf("%lld",ans);
	return 0;
}