#include <stdio.h>
#include <algorithm>
using namespace std;
int main() {
	int i;
	int n, m;
	int x, y;
	int o[110];
	scanf("%d %d",&n,&m);
	for(i=0;i<n;i++) o[i] = i+1;
	for(i=0;i<m;i++) {
		scanf("%d %d",&x,&y);
		swap(o[x-1],o[y-1]);
	}
	for(i=0;i<n;i++) printf("%d ",o[i]);
	return 0;
}