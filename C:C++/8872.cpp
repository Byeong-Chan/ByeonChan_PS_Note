#include <stdio.h>
#include <queue>
#include <set>
#include <algorithm>
using namespace std;
typedef pair<int, int> pr;
set<pr> o[100001];
priority_queue<pr, vector<pr>, greater<pr> > q;
int p[100001];
int sub[100001];
int e = 0, head = 0, tail = 0;
int n, m, l;
int ans = 0;
bool fsort(int a, int b) {
    return a > b;
}
void bfs() {
    pr nex;
    pr tmp;
    pr inp;
    pr k;
    while(q.size()) {
        tmp = q.top();
        q.pop();
        if(o[tmp.second].size() == 0) {
            sub[e++] = p[tmp.second];
            continue;
        }

        nex = *o[tmp.second].begin();
		if(p[nex.first] + tmp.first > ans) ans = p[nex.first] + tmp.first;
        if(tmp.first > p[nex.first]) {
        	p[nex.first] = tmp.first;
        }

        o[tmp.second].erase(o[tmp.second].find(make_pair(nex.first, nex.second)));
        o[nex.first].erase(o[nex.first].find(make_pair(tmp.second, nex.second)));

        if(o[nex.first].size() == 1) {
            k = *o[nex.first].begin();
            inp = make_pair(p[nex.first]+k.second, nex.first);
            q.push(inp);
        }
    }
}
int main() {
    int i;
    int x, y, z;
    int max1;
    pr tmp;
    scanf("%d %d %d",&n,&m, &l);
    for(i=0;i<m;i++) {
        scanf("%d %d %d",&x,&y,&z);
        o[x].insert(make_pair(y, z));
        o[y].insert(make_pair(x, z));
    }
    for(i=0;i<n;i++) {
        if(o[i].size() == 1) {
            tmp = *o[i].begin();
            q.push(make_pair(tmp.second, i));
        }
        if(o[i].size() == 0) q.push(make_pair(0, i));
    }
    bfs();
    sort(sub, sub+e, fsort);
    for(i=0;i<e-1;i++) {
        if(ans < sub[i] + sub[i+1] + l) ans = sub[i] + sub[i+1] + l;
        max1 = sub[i] > sub[i+1] + l ? sub[i] : sub[i+1] + l;
        sub[i+1] = max1;
    }
    if(ans < sub[i]) ans = sub[i];
    printf("%d",ans);
    return 0;
}