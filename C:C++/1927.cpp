#include <stdio.h>
#include <queue>
#include <algorithm>
using namespace std;
priority_queue<int, vector<int>, greater<int> > q;
int main() {
	int n;
	int x;
	scanf("%d",&n);
	while(n--) {
		scanf("%d",&x);
		if(x == 0) {
			if(q.size() == 0) printf("0\n");
			else {
				printf("%d\n",q.top());
				q.pop();
			}
			continue;
		}
		q.push(x);
	}
	return 0;
}