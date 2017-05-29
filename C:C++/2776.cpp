#include <stdio.h>
#include <algorithm>
using namespace std;
typedef pair<int, int> pr;
int o[1000002];
pr u[1000002];
bool chk[1000002];
int main() {
	int i;
	int t;
	int n, m;
	int j;
	int x;
	scanf("%d",&t);
	while(t--) {
		scanf("%d",&n);
		for(i=0;i<n;i++) scanf("%d",&o[i]);
		scanf("%d",&m);
		for(i=0;i<m;i++) {
			scanf("%d",&x);
			u[i] = make_pair(x, i);
		}
		sort(o,o+n);
		sort(u,u+n);
		j = 0;
		for(i=0;i<m;i++) {
			while(j < n) {
				if(o[j] < u[i].first) j++;
				else break;
			}
			if(j == n || o[j] != u[i].first) chk[u[i].second] = 0;
			else chk[u[i].second] = 1;
		}
		for(i=0;i<m;i++) printf("%d\n",chk[i]);
	}
	return 0;
}