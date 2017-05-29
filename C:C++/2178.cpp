#include <cstdio>
#include <queue>
using namespace std;
struct node {
    int x;
    int y;
    int d;
    node() {}
    node(int x, int y, int d) {
        this->x = x;
        this->y = y;
        this->d = d;
    }
};
int o[101][101];
int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};
int main() {
    int i, j;
    int x, y;
    int n, m;
    scanf("%d %d",&n,&m);
    for(i=0;i<n;i++) for(j=0;j<m;j++) scanf("%1d",&o[i][j]);
    queue<node> q;
    q.push(node(0, 0, 1));
    o[0][0] = 0;
    while(q.size()) {
        node tmp = q.front();
        q.pop();
        if(tmp.x == n-1 && tmp.y == m-1) printf("%d\n",tmp.d);
        
        for(i=0;i<4;i++) {
            x = tmp.x + dx[i];
            y = tmp.y + dy[i];
            if(x < 0 || y < 0 || x >= n || y >= m) continue;
            if(o[x][y] == 0) continue;
            o[x][y] = 0;
            q.push(node(x, y, tmp.d + 1));
        }
    }
    return 0;
}