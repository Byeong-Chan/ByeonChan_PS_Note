#include <stdio.h>
#include <algorithm>
#include <string>
using namespace std;

#define min(x, y) ((x) < (y) ? (x) : (y))

int n, m;
string o[51];
int table[110];
int a1[110];
int b1[110];
bool chk(string a, string b, int len) {
	for(int i=0;i<len;i++) if(a[i] != b[b.size() - i - 1]) return false;
	return true;
}
void pal(string p, int len, bool sw) {
	if(p == "") {
		b1[len/2] ++;
		return;
	}
	if(p.size() > 0 && chk(p, p, p.size())) {
		table[len] ++;
		a1[len]++;
		b1[len]--;
	}
	int i;
	if(!sw) for(i=0;i<n;i++) {
		if(o[i].size() + len > m) continue;
		int mn = min(o[i].size(), p.size());
		if(chk(p, o[i], mn)) {
			if(o[i].size() <= p.size()) pal(p.substr(mn, p.size() - mn), len + o[i].size(), false);
			else pal(o[i].substr(0, o[i].size() - mn), len + o[i].size(), true);
		}
	}
	if(sw) for(i=0;i<n;i++) {
		if(o[i].size() + len > m) continue;
		int mn = min(o[i].size(), p.size());
		if(chk(o[i], p, mn)) {
			if(o[i].size() < p.size()) pal(p.substr(0, p.size() - mn), len + o[i].size(), true);
			else pal(o[i].substr(mn, o[i].size() - mn), len + o[i].size(), false);
		}
	}
}
int main() {
	int i;
	int j;
	scanf("%d",&n);
	scanf("%d",&m);
	for(i=0;i<n;i++) {
		char tmp[50];
		scanf("%s",tmp);
		o[i] = tmp;
	}
	for(i=0;i<n;i++) if(o[i].size() <= m) {
		pal(o[i], o[i].size(), false);
	}
	table[0] = 1;
	for(i=0;i<m;i++) {
		for(j=1;j<=m/2;j++) {
			if(a1[j] < 0) continue;
			table[i + (j << 1)] += table[i] * a1[j];
			table[i + (j << 1)] += table[i] * b1[j];
		}
	}
	printf("%d",table[m]);
	return 0;
}