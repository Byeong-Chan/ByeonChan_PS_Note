#include <iostream>
#include <algorithm>
using namespace std;
int memo[10001];
int coin[101];

int main() {
	int i, j;
	int n, k;
	int tmp;
	scanf("%d %d",&n, &k);
	for(i=0;i<n;i++) scanf("%d",&coin[i]);
	
	for(i=1;i<=k;i++) memo[i] = 0x7fffffff;
	for(i=1;i<=k;i++) {
		int min1 = 0x7fffffff;
		for(j=0;j<n;j++) {
			if(i-coin[j] < 0) continue;
			min1 = min(min1, memo[i-coin[j]]);
		}
		if(min1 != 0x7fffffff) memo[i] = min1 + 1;
	}
	if(memo[k] == 0x7fffffff) printf("-1\n");
	else printf("%d\n",memo[k]);
	return 0;
}