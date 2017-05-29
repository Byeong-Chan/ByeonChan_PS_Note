#include <cstdio>
#include <queue>
#include <cstdlib>
#include <cstring>
#include <algorithm>
using namespace std;
queue<int> q;
struct bung {
    int moth;
    int k;
}visit[10010];
bool chk[10010];
int ch(int num, int func) {
    if (func == 0) {
        num *= 2;
        num %= 10000;
        return num;
    }
    if (func == 1) {
        num --;
        if(num == -1) num += 10000;
        return num;
    }
    if (func == 2) {
        int tmp = 0;
        tmp += (num % 10) * 10;
        num /= 10;
        tmp += (num % 10) * 100;
        num /= 10;
        tmp += (num % 10) * 1000;
        num /= 10;
        tmp += (num % 10);
        num /= 10;
        return tmp;
    }
    int tmp = 0;
    tmp += (num % 10) * 1000;
    num /= 10;
    tmp += (num % 10);
    num /= 10;
    tmp += (num % 10) * 10;
    num /= 10;
    tmp += (num % 10) * 100;
    num /= 10;
    return tmp;
}
char ans[10010];
int main() {
    int t;
    int i, x, y;
    int here;
    int nxt;
    int sz = 0;
    char p[5] = "DSLR";
    scanf("%d",&t);
    while (t--) {
        memset(ans, 0, sizeof(ans));
        scanf("%d %d",&x,&y);
        visit[x].moth = -1;
        chk[x] = true;
        q.push(x);
        while (q.size()) {
            here = q.front();
            q.pop();
            if (here == y) break;
            
            for(i=0;i<4;i++) {
                nxt = ch(here, i);
                if (chk[nxt]) continue;
                chk[nxt] = true;
                visit[nxt].moth = here;
                visit[nxt].k = i;
                q.push(nxt);
            }
        }
        while (q.size()) q.pop();
        here = y;
        sz = 0;
        while (1) {
            if (here == x) break;
            ans[sz++] = p[visit[here].k];
            here = visit[here].moth;
        }
        reverse(ans, ans+sz);
        printf("%s\n",ans);
        for (i=0;i<=9999;i++) {
            visit[i].moth = 0;
            visit[i].k = 0;
            chk[i] = false;
        }
    }
    return 0;
}