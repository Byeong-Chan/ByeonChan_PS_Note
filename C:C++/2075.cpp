#include <stdio.h>
#include <vector>
#include <queue>
#include <algorithm>
#include <functional>
using namespace std;
priority_queue<int, vector<int>, greater<int> > q;
int main() {
	int i, j, n;
	int x;
	scanf("%d",&n);
	for(i=0;i<n;i++) {
		for(j=0;j<n;j++) {
			scanf("%d",&x);
			if(q.size() < n) {
				q.push(x);
				continue;
			}
			if(q.top() < x) {
				q.pop();
				q.push(x);
			}
		}
	}
	printf("%d",q.top());
	return 0;
}