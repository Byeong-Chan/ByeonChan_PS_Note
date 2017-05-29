#include <cstdio>
#include <cstring>
int main() {
    int i, n;
    int x;
    int bit = 0;
    char query[11];
    scanf("%d",&n);
    for(i=0;i<n;i++) {
        scanf("%s",query);
        if(strcmp(query, "add") == 0) {
            scanf("%d",&x);
            x--;
            x = 1 << x;
            bit |= x;
        }
        else if(strcmp(query, "remove") == 0) {
            scanf("%d",&x);
            x--;
            x = 1 << x;
            if(bit & x) bit ^= x;
        }
        else if(strcmp(query, "check") == 0) {
            scanf("%d",&x);
            x--;
            x = 1 << x;
            if(bit & x) printf("1\n");
            else printf("0\n");
        }
        else if(strcmp(query, "toggle") == 0) {
            scanf("%d",&x);
            x--;
            x = 1 << x;
            bit ^= x;
        }
        else if(strcmp(query, "all") == 0) bit = (1 << 20) - 1;
        else if(strcmp(query, "empty") == 0) bit = 0;
    }
    return 0;
}