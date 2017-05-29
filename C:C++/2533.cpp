#include <cstdio>
#include <vector>
using namespace std;
int que[1000200];
int moth[1000200];
int son[1000200];
int dt[1000200][2];
vector<int> conn[1000001];
int min1(int x, int y) {
    if(x < y) return x;
    return y;
}
int main() {
    int i;
    int n;
    int x, y;
    int tail, head;
    int tmp;
    int nex;
    int sz;
    scanf("%d", &n);
    for (i = 0; i < n-1; i++) {
        scanf("%d %d", &x, &y);
        conn[x].push_back(y);
        conn[y].push_back(x);
    }
    tail = head = 0;
    que[tail++] = 1;
    moth[1] = -1;
    while (tail > head) {
        tmp = que[head++];
        sz = conn[tmp].size();
        for (i = 0; i < sz; i++) {
            nex = conn[tmp][i];
            if (!moth[nex]) {
                moth[nex] = tmp;
                son[tmp]++;
                que[tail++] = nex;
            }
        }
    }
    tail = head = 0;
    for (i = 1; i <= n; i++) {
        dt[i][1] = 1;
        if (!son[i]) que[tail++] = i;
    }
    while (tail > head) {
        tmp = que[head++];
        nex = moth[tmp];
        if (nex == -1) break;
        if (--son[nex] == 0) que[tail++] = nex;
 
        dt[nex][0] += dt[tmp][1];
        dt[nex][1] += min1(dt[tmp][0], dt[tmp][1]);
    }
    tmp = que[head - 1];
    printf("%d", min1(dt[tmp][0], dt[tmp][1]));
    return 0;
}