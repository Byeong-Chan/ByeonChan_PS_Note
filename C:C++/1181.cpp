#include <stdio.h>
#include <string>
#include <algorithm>
#include <set>
using namespace std;
struct cmp {
	bool operator() (string a, string b) {
		if(a.size() != b.size()) return a.size() < b.size();
		return a < b;
	}
};
set<string, cmp> o;
int main() {
	int i, n;
	char tmp[52];
	scanf("%d",&n);
	for(i=0;i<n;i++) {
		scanf("%s",tmp);
		o.insert(tmp);
	}
	set<string, cmp>::iterator it;
	for(it=o.begin();it!=o.end();it++) printf("%s\n",it->data());
	return 0;
}