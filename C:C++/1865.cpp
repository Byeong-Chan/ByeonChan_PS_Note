#include <cstdio>
#include <algorithm>
#include <vector>

using namespace std;

struct edge {
	int start;
	int dest;
	int cost;
};
vector<edge> e;
vector<long long> dist;
const long long LONG_LONG_MAX = (long long)0x7fffffff << 20;
int main() {
	bool update, can;
	int h, i, j;
	int n, m, k;
	int sz;
	int t;
	long long tmp;
	scanf("%d",&t);
	while (t--) {
		scanf("%d %d %d",&n,&m,&k);
		e.resize(2*m+k);
		dist.resize(n+1);
		sz = 0;
		for(i=0;i<m;i++) {
			scanf("%d %d %d",&e[sz].start,&e[sz].dest,&e[sz].cost);
			sz++;
			e[sz] = e[sz-1];
			e[sz].dest = e[sz-1].start;
			e[sz].start = e[sz-1].dest;
			sz++;
		}
		for(i=0;i<k;i++) {
			scanf("%d %d %d",&e[sz].start,&e[sz].dest,&e[sz].cost);
			e[sz].cost *= -1;
			sz++;
		}
		can = false;
		for(i=1;i<=n;i++)  dist[i] = LONG_LONG_MAX;
		for(h=1;h<=n;h++) {
			if(dist[h] != LONG_LONG_MAX) continue;
			dist[h] = 0;
			for(i=0;i<n;i++) {
				update = false;
				for(j=0;j<sz;j++) {
					edge &here = e[j];
					if(dist[here.start] == LONG_LONG_MAX) continue;
					tmp = dist[here.start] + here.cost;
					if(dist[here.dest] > tmp) {
						update = true;
						dist[here.dest] = tmp;
					}
				}
				if(update == false) break;
			}
			if(update == true) can = true;
		}
		if(can == true) printf("YES\n");
		else printf("NO\n");
		e.clear();
		dist.clear();
	}
	return 0;
}