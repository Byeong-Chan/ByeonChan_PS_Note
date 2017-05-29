#include <cstdio>
#include <cstring>
#include <queue>
using namespace std;
int main() {
    int i, n;
    queue<int> q;
    int x;
    char str[10];
    scanf("%d",&n);
    for(i=0;i<n;i++) {
        scanf("%s",str);
        if(strcmp(str, "push") == 0) {
            scanf("%d",&x);
            q.push(x);
        }
        else if(strcmp(str, "front") == 0) {
            if(q.empty()) printf("-1\n");
            else printf("%d\n",q.front());
        }
        else if(strcmp(str, "back") == 0) {
            if(q.empty()) printf("-1\n");
            else printf("%d\n",q.back());
        }
        else if(strcmp(str, "empty") == 0) printf("%d\n",(int)q.empty());
        else if(strcmp(str, "size") == 0) printf("%d\n",(int)q.size());
        else {
            if(q.empty()) printf("-1\n");
            else {
                printf("%d\n",q.front());
                q.pop();
            }
        }
    }
    return 0;
}