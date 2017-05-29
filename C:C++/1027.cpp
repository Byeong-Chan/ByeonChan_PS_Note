#include <stdio.h>
#include <vector>
using namespace std;
typedef long long ll;
ll o[51];
int all[51];
bool ccw(ll x1, ll y1, ll x2, ll y2, ll x3, ll y3) {
	ll a = (x1*y2) + (x2*y3) + (x3*y1);
	ll b = (x2*y1) + (x3*y2) + (x1*y3);

	return ((a-b) >= 0 ? true : false);
}
int main() {
	int i, j, k, max1 = 0, n;
	scanf("%d",&n);
	for(i=0;i<n;i++) scanf("%lld",&o[i]);
	for(i=0;i<n;i++) {
		for(j=i+1;j<n;j++) {
			for(k = i+1; k < j; k ++) if(ccw(i, o[i], j, o[j], k, o[k])) break;
			if(k == j) {
				all[i]++;
				all[j]++;
			}
		}
	}
	for(i=0;i<n;i++) if(max1 < all[i]) max1 = all[i];
	printf("%d\n",max1);
	return 0;
}