#include <cstdio>
#include <cstring>
#include <stack>
using namespace std;
int main() {
    int i, n;
    stack<int> stk;
    int x;
    char str[10];
    scanf("%d",&n);
    for(i=0;i<n;i++) {
        scanf("%s",str);
        if(strcmp(str, "push") == 0) {
            scanf("%d",&x);
            stk.push(x);
        }
        else if(strcmp(str, "top") == 0) {
            if(stk.empty()) printf("-1\n");
            else printf("%d\n",stk.top());
        }
        else if(strcmp(str, "empty") == 0) printf("%d\n",(int)stk.empty());
        else if(strcmp(str, "size") == 0) printf("%d\n",(int)stk.size());
        else {
            if(stk.empty()) printf("-1\n");
            else {
                printf("%d\n",stk.top());
                stk.pop();
            }
        }
    }
    return 0;
}