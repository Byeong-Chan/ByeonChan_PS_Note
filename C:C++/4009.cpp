#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;
int table[100003][6];
int h[2][2] = {0, 1, 0, -1};
bool chk[100003];
bool pl[100003];
int n, k;
vector<int> conn[100003];
int moth[100003];
int son[100003];
int con[100003];
int que[100003], tail = 0, head = 0;
int que2[100003], tail2 = 0, head2 = 0;
int ans = 0;
void bfs() {
    int i;
    int tmp;
    int ne;
    que[tail++] = 1;
    chk[1] = true;
    while(tail > head) {
        tmp = que[head++];
        for(i=0;i<conn[tmp].size();i++) {
            ne = conn[tmp][i];
            if(chk[ne] == false) {
                que[tail++] = ne;
                moth[ne] = tmp;
                son[tmp]++;

                con[tmp]++;
                con[ne]++;

                chk[ne] = true;
            }
        }
        if(son[tmp] == 0) que2[tail2++] = tmp;
    }
}
void bfs2() {
    int i, j;
    int tmp, ne;
    int sw;
    int min1[6] = {0,};
    while(tail2 > head2) {
        tmp = que2[head2++];
        if(tmp == 1) break;

        ans++;
        sw = con[tmp]&1;
        ne = moth[tmp];
        if(sw) {
            con[ne]++;
            ans++;
        }
        if(--son[ne] == 0) que2[tail2++] = ne;
        for(i=0;i<=4;i++) min1[i] = table[tmp][i];
        for(i=0;i<=4;i++) {
            for(j=0;j<=4-i;j++) {
                if(min1[i+j] > table[tmp][i] + h[sw][(i+j)&1]) min1[i+j] = table[tmp][i] + h[sw][(i+j)&1];
            }
        }
        for(i=0;i<=4;i++) table[tmp][i] = min1[i];

        for(i=0;i<=4;i++) min1[i] = table[ne][i];
        for(i=0;i<=4;i++) {
            for(j=0;j<=4-i;j++) {
                if(min1[i+j] > table[ne][i] + table[tmp][j]) min1[i+j] = table[ne][i] + table[tmp][j];
            }
        }
        for(i=0;i<=4;i++) table[ne][i] = min1[i];
    }
}
int main() {
    int i;
    int x, y;
    scanf("%d %d",&n,&k);
    for(i=0;i<n-1;i++) {
        scanf("%d %d",&x,&y);
        conn[x].push_back(y);
        conn[y].push_back(x);
    }
    bfs();
    bfs2();
    printf("%d",ans+table[1][k*2]+k);
    return 0;
}