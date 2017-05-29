#include <cstdio>
#include <queue>
#include <algorithm>
using namespace std;
struct node1 {
    int pos;
    int val;
    bool operator< (const node1 &a) const {
        return this->val > a.val;
    }
};
struct node2 {
    int pos;
    int val;
    bool operator< (const node2 &a) const {
        return this->val < a.val;
    }
};
priority_queue<node1> minh;
priority_queue<node2> maxh;
bool chk[2000010];
int main() {
    int i, n, t;
    char order;
    int x = 0, y = 0;
    int k = 0;
    bool sw;
    scanf("%d",&t);
    while (t--) {
        scanf("%d\n",&n);
        k = 0;
        for(i=0;i<n;i++) {
            scanf("%c %d\n",&order,&x);
            if (order == 'D') {
                if (x == 1) {
                    while (maxh.size()) {
                        node2 tmp = maxh.top();
                        maxh.pop();
                        if(chk[tmp.pos]) continue;
                        chk[tmp.pos] = true;
                        sw = false;
                        break;
                    }
                }
                else {
                    while (minh.size()) {
                        node1 tmp = minh.top();
                        minh.pop();
                        if(chk[tmp.pos]) continue;
                        chk[tmp.pos] = true;
                        break;
                    }
                }
            }
            else {
                k++;
                maxh.push({k, x});
                minh.push({k, x});
            }
        }
        sw = true;
        while(maxh.size()) {
            node2 tmp = maxh.top();
            maxh.pop();
            if(chk[tmp.pos]) continue;
            y = tmp.val;
            sw = false;
        }
        while(minh.size()) {
            node1 tmp = minh.top();
            minh.pop();
            if(chk[tmp.pos]) continue;
            x = tmp.val;
            sw = false;
        }
        for(i=1;i<=k;i++) chk[i] = false;
        if(sw) printf("EMPTY\n");
        else printf("%d %d\n",x,y);
    }
    return 0;
}