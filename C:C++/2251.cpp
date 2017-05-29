#include <cstdio>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;
struct node {
    int x;
    int y;
    int z;
    void inp(int a, int b, int c) {
        this->x = a;
        this->y = b;
        this->z = c;
    }
};
queue<node> q;
bool chk[210][210][210];
vector<int> ans;
void sub(int x, int y, int z, int *b1, int *b2, int *b3, int a, int b, int c) {
    *b1 = x;
    *b2 = y;
    *b3 = z;
    if (x > 0) {
        if (y < b) {
            if (x + y <= b) {
                *b1 = 0;
                *b2 = x + y;
                *b3 = z;
            }
            else {
                *b1 = x + y - b;
                *b2 = b;
                *b3 = z;
            }
        }
    }
}
void sub2(int x, int y, int z, int *b1, int *b2, int *b3, int a, int b, int c) {
    *b1 = x;
    *b2 = y;
    *b3 = z;
    if (x > 0) {
        if (z < c) {
            if (x + z <= c) {
                *b1 = 0;
                *b2 = y;
                *b3 = x + z;
            }
            else {
                *b1 = x + z - c;
                *b2 = y;
                *b3 = c;
            }
        }
    }
}
int main() {
    int a, b, c;
    int x, y, z;
    node tmp, nxt;
    scanf("%d %d %d",&a,&b,&c);
    tmp.inp(0, 0, c);
    q.push(tmp);
    chk[0][0][c] = true;
    while(q.size()) {
        tmp = q.front();
        q.pop();
        if (tmp.x == 0) ans.push_back(tmp.z);
        
        sub(tmp.x, tmp.y, tmp.z, &x, &y, &z, a, b, c);
        nxt.inp(x, y, z);
        if (!chk[x][y][z]) {
            chk[x][y][z] = true;
            q.push(nxt);
        }
        
        sub(tmp.y, tmp.x, tmp.z, &y, &x, &z, b, a, c);
        nxt.inp(x, y, z);
        if (!chk[x][y][z]) {
            chk[x][y][z] = true;
            q.push(nxt);
        }
        
        sub(tmp.z, tmp.x, tmp.y, &z, &x, &y, c, a, b);
        nxt.inp(x, y, z);
        if (!chk[x][y][z]) {
            chk[x][y][z] = true;
            q.push(nxt);
        }
        
        sub2(tmp.x, tmp.y, tmp.z, &x, &y, &z, a, b, c);
        nxt.inp(x, y, z);
        if (!chk[x][y][z]) {
            chk[x][y][z] = true;
            q.push(nxt);
        }
        
        sub2(tmp.y, tmp.x, tmp.z, &y, &x, &z, b, a, c);
        nxt.inp(x, y, z);
        if (!chk[x][y][z]) {
            chk[x][y][z] = true;
            q.push(nxt);
        }
        
        sub2(tmp.z, tmp.x, tmp.y, &z, &x, &y, c, a, b);
        nxt.inp(x, y, z);
        if (!chk[x][y][z]) {
            chk[x][y][z] = true;
            q.push(nxt);
        }
    }
    sort(ans.begin(), ans.end());
    for(int i=0;i<ans.size();i++) printf("%d ",ans[i]);
    printf("\n");
    return 0;
}