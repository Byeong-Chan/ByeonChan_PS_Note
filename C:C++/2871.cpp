#include <cstdio>
#include <cstring>
#include <queue>
#include <algorithm>
using namespace std;
priority_queue<int> q[26];
char o[100010];
char h[50010];
char s[50010];
int main() {
	int i;
	int n;
	int m;
	int tmp;
	int e = 0, t = 0;
	int sw;
	scanf("%d", &n);
	scanf("%s", o);
	for (i = 0; i < n; i++) q[o[i] - 'a'].push(i);
	m = n;
	for (sw = n >> 1; sw >= 0; sw--) {
		while (m) {
			tmp = o[--m] - 'a';

			if (q[tmp].size() == 0) continue;
			if (q[tmp].top() == m) {
				s[e++] = tmp + 'a';
				q[tmp].pop();
				break;
			}
		}
		for (i = 0; i < 26; i++) {
			if (q[i].size()) {
				h[t++] = i + 'a';
				q[i].pop();
				break;
			}
		}
	}
	if (strcmp(h, s) < 0) printf("DA\n");
	else printf("NE\n");
	printf("%s", h);
	return 0;
}