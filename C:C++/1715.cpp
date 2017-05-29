#include <stdio.h>
#include <algorithm>
#include <queue>
using namespace std;
priority_queue<int, vector<int>, greater<int> > q;
int main() {
	int n;
	int i;
	int x;
	int tmp;
	int ans = 0;
	scanf("%d",&n);
	for(i=0;i<n;i++) {
		scanf("%d",&x);
		q.push(x);
	}
	while(q.size() > 1) {
		tmp = q.top();
		q.pop();
		tmp += q.top();
		q.pop();
		ans += tmp;
		q.push(tmp);
	}
	printf("%d",ans);
	return 0;
}