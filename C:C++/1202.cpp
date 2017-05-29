#include <stdio.h>
#include <set>
#include <algorithm>
#include <functional>
using namespace std;
multiset<int> pack;
typedef pair<int, int> pr;
pr o[300001];
int main() {
	int i, n, m;
	int x;
	long long ans = 0;
	scanf("%d %d",&n,&m);
	for(i=0;i<n;i++) scanf("%d %d", &o[i].second, &o[i].first);
	for(i=0;i<m;i++) {
		scanf("%d",&x);
		pack.insert(x);
	}
	sort(o, o+n, greater<pr>() );
	multiset<int>::iterator it;
	for(i=0;i<n;i++) {
		it = pack.lower_bound(o[i].second);
		if(it != pack.end()) {
			ans += o[i].first;
			pack.erase(it);
		}
	}
	printf("%lld",ans);
	return 0;
}