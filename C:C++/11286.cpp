#include <cstdio>
#include <queue>
#include <algorithm>
using namespace std;
struct node {
    int x;
    bool operator< (const node &a) const {
        int k = this->x > 0 ? this->x : -this->x;
        int l = a.x > 0 ? a.x : -a.x;
        if(k!=l) return k > l;
        else return this->x > a.x;
    }
};
priority_queue<node> q;
int main() {
    int i, n, x;
    scanf("%d",&n);
    for(i=0;i<n;i++) {
        scanf("%d",&x);
        if(x==0) {
            if(q.size()) {
                printf("%d\n",q.top().x);
                q.pop();
            }
            else printf("0\n");
        }
        else q.push({x});
    }
    return 0;
}