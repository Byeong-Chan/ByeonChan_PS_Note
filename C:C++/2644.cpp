#include <cstdio>
#include <vector>
#include <queue>
using namespace std;
vector<int> edge[110];
queue<int> q;
int chk[110];
int main() {
    int i;
    int n, m;
    int x, y;
    int st, ed;
    scanf("%d",&n);
    scanf("%d %d",&st, &ed);
    scanf("%d",&m);
    for(i=0;i<m;i++) {
        scanf("%d %d",&x,&y);
        edge[x].push_back(y);
        edge[y].push_back(x);
    }
    chk[st] = 1;
    q.push(st);
    while(q.size()) {
        x = q.front();
        q.pop();
        for(i=0;i<edge[x].size();i++) {
            y = edge[x][i];
            if(chk[y]) continue;
            chk[y] = chk[x] + 1;
            q.push(y);
        }
    }
    printf("%d\n",chk[ed]-1);
    return 0;
}