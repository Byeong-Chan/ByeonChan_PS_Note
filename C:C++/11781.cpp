#include <stdio.h>
#include <algorithm>
#include <queue>
#include <vector>
using namespace std;
typedef pair<int, int> conn;
typedef pair<long double, conn> pr;
bool chk[5002][5002];
int n, m;
long double st, ed;
long double minlen[5002];
priority_queue<pr, vector<pr>, greater<pr> > d;
vector<pr> o[5002];
long double calc(long double now, long double l) {
	if(l >= (ed - now)/2) return (ed - now) + (l - (ed - now) / 2);
	else return l*2;
}
int main() {
	int i;
	int x, y;
	int _size;
	long double c;
	long double max;
	int t1, t2;
	conn path, inpath;
	pr tmp, intmp;
	scanf("%d %d %Lf %Lf",&n,&m,&st,&ed);
	for(i=0;i<m;i++) {
		scanf("%d %d %Lf", &x, &y, &c);
		scanf("%d %d", &t1, &t2);
		chk[x][y] = t1;
		chk[y][x] = t2;

		inpath = make_pair(x, y);
		intmp = make_pair(c, inpath);
		o[x].push_back(intmp);
		if(x == 1) {
			if(chk[x][y] && c > st) intmp.first = st + calc(st, c - st);
			d.push(intmp);
		}

		inpath = make_pair(y, x);
		intmp = make_pair(c, inpath);
		o[y].push_back(intmp);
		if(y == 1) {
			if(chk[y][x] && c > st) intmp.first = st + calc(st, c - st);
			d.push(intmp);
		}
	}
	minlen[1] = -1;
	while(d.size()) {
		tmp = d.top();
		path = tmp.second;
		d.pop();
		if(minlen[path.second] != 0 && minlen[path.second] < tmp.first) continue;

		minlen[path.second] = tmp.first;
		_size = (int)o[path.second].size();
		for(i=0;i<_size;i++) {
			intmp = o[path.second][i];
			inpath = intmp.second;
			if(inpath.second == 1) continue;

			if(chk[inpath.first][inpath.second]) {
				if(tmp.first >= st && tmp.first < ed) intmp.first = calc(tmp.first, intmp.first);
				else if(tmp.first + intmp.first > st  && tmp.first + intmp.first <= ed) intmp.first = (st - tmp.first) + calc(st, intmp.first - st + tmp.first);
				else if(tmp.first < st && tmp.first + intmp.first > ed) intmp.first = (st-tmp.first) +  calc(st, intmp.first - st + tmp.first);
			}
			intmp.first += tmp.first;

			if(minlen[inpath.second] == 0 || (minlen[inpath.second] != 0 && minlen[inpath.second] > intmp.first)) d.push(intmp);
		}
	}
	max = 0.0;
	for(i=1;i<=n;i++) if(minlen[i] > max) max = minlen[i];
	if((long long)max == max) printf("%.0Lf",max);
	else printf("%.1Lf",max);
	return 0;
}