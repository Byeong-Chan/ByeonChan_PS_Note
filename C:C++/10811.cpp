#include <stdio.h>
#include <algorithm>
using namespace std;
int main() {
	int i, n, m;
	int o[110];
	int x, y;
	scanf("%d %d",&n,&m);
	for(i=0;i<n;i++) o[i] = i+1;
	for(i=0;i<m;i++) {
		scanf("%d %d",&x,&y);
		reverse(o+x-1,o+y);
	}
	for(i=0;i<n;i++) printf("%d ",o[i]);
	return 0;
}