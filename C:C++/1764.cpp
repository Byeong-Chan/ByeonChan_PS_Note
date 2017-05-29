#include <stdio.h>
#include <string.h>
#include <map>
#include <vector>
#include <algorithm>
using namespace std;
map<int, int> trie[26];
int n, m;
int e = 0;
struct bung {
	char c[23];
};
bool fsort(bung a, bung b) {
	if(strcmp(a.c, b.c) == 1) return 1;
	return 0;
}
vector<bung> all;
void make_trie() {
	int i, j;
	int d;
	int tmp;
	int l;
	char x[23];
	scanf("%d %d",&n,&m);
	for(i=0;i<n;i++) {
		scanf("%s",x);
		l = strlen(x);
		d = 0;
		for(j=0;j<l;j++) {
			tmp = x[j] - 'a';
			if(!trie[tmp][d]) {
				trie[tmp][d] = ++e;
				d = e;
			}
			else d = trie[tmp][d];
		}
	}
}
void solv() {
	int i, j;
	int d;
	int tmp;
	int l;
	bung x;
	for(i=0;i<m;i++) {
		scanf("%s",x.c);
		l = strlen(x.c);
		d = 0;
		for(j=0;j<l;j++) {
			tmp = x.c[j] - 'a';
			if(!trie[tmp][d]) break;
			d = trie[tmp][d];
		}
		if(j == l) all.push_back(x);
	}
	sort(all.begin(), all.end(), fsort);
}
void _out() {
	printf("%d\n",all.size());
	while(all.size()) {
		printf("%s\n",all.back().c);
		all.pop_back();
	}
}
int main() {
	make_trie();
	solv();
	_out();
	return 0;
}