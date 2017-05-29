#include <stdio.h>
#include <algorithm>
using namespace std;
int main() {
	int i, n, m;
	int x, y, z;
	int d;
	int o[110];
	scanf("%d %d",&n,&m);
	for(i=0;i<n;i++) o[i] = i+1;
	for(i=0;i<m;i++) {
		scanf("%d %d %d",&x,&y,&z);
		d = y - z;
		reverse(o+x-1,o+y);
		reverse(o+x-1,o+x+d);
		reverse(o+x+d,o+y);
	}
	for(i=0;i<n;i++) printf("%d ",o[i]);
	return 0;
}