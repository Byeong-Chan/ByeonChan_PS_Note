#include <iostream>
#include <algorithm>
using namespace std;
int memo[10001];
int coin[101];
bool visit[10001];

int main() {
	int i, j;
	int n, k;
	int tmp;
	scanf("%d %d",&n, &k);
	for(i=0;i<n;i++) scanf("%d",&coin[i]);
	
	memo[0] = 1;
	for(i=0;i<n;i++) {
		for(j=coin[i];j<=k;j++) {
			memo[j] += memo[j-coin[i]];
		}
	}
	printf("%d\n",memo[k]);
	return 0;
}