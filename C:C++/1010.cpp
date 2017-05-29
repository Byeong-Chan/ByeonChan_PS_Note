#include <stdio.h>
#include <algorithm>
using namespace std;
unsigned long long c;
int main() {
	int t;
	int n, m;
	int e;
	scanf("%d",&t);
	while(t--) {
		scanf("%d %d",&n,&m);
		if(n < m) swap(n, m);
		c = 1;
		e = 0;
		while(m--) {
			c *= n--;
			e++;
			c /= e;
		}
		printf("%lld\n",c);
	}
	return 0;
}