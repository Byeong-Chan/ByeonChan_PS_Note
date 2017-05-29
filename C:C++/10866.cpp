#include <stdio.h>
#include <list>
#include <algorithm>
#include <string>
using namespace std;
string s;
char tmp[20];
list<int> deq;
int main() {
	int n;
	int x;
	scanf("%d",&n);
	while(n--) {
		scanf("%s",tmp);
		s = tmp;
		if(s == "push_front") {
			scanf("%d",&x);
			deq.push_front(x);
		}
		if(s == "push_back") {
			scanf("%d",&x);
			deq.push_back(x);
		}
		if(s == "pop_front") {
			if(deq.size() == 0) printf("-1\n");
			else {
				printf("%d\n",deq.front());
				deq.pop_front();
			}
		}
		if(s == "pop_back") {
			if(deq.size() == 0) printf("-1\n");
			else {
				printf("%d\n",deq.back());
				deq.pop_back();
			}
		}
		if(s == "front") {
			if(deq.size() == 0) printf("-1\n");
			else printf("%d\n",deq.front());
		}
		if(s == "back") {
			if(deq.size() == 0) printf("-1\n");
			else printf("%d\n",deq.back());
		}
		if(s == "size") printf("%d\n",deq.size());
		if(s == "empty") {
			if(deq.size() == 0) printf("1\n");
			else printf("0\n");
		}
	}
}