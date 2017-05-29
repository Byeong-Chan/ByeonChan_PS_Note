#include <cstdio>
#include <vector>
using namespace std;
int ans = 0;
vector<int> son[10010];
vector<int> sonval[10010];
int diameter(int u) {
	int max1 = 0, max2 = 0;
	for(int i = 0; i < son[u].size(); i++) {
		int v = son[u][i];
		int tmp = diameter(v) + sonval[u][i];
		
		if(max1 <= tmp) {
			max2 = max1;
			max1 = tmp;
		}
		else if(max2 < tmp) max2 = tmp;
		
		if(max1 + max2 > ans) ans = max1 + max2;
	}
	return max1;
}
int main() {
	int n, x, y, z;
	scanf("%d",&n);
	for(int i = 0;i<n-1;i++) {
		scanf("%d %d %d",&x,&y,&z);
		son[x].push_back(y);
		sonval[x].push_back(z);
	}
	diameter(1);
	printf("%d\n",ans);
	return 0;
}