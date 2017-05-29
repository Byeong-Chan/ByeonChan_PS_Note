#include <stdio.h>
#include <string.h>
char br[6] = "<br>";
char hr[6] = "<hr>";
void printhr(int len) {
    if (len > 0) printf("\n");
    for(int i=0;i<80;i++) printf("-");
    return;
}
void solv() {
    char o[86];
    int len, l;
    len = 0;
    while (1) {
        if (scanf("%s", o) == -1) break;
        l = (int)strlen(o);
        if (strcmp(br, o) == 0) {
            len = 0;
            printf("\n");
            continue;
        }
        else if (strcmp(hr, o) == 0) {
            printhr(len);
            len = 0;
            printf("\n");
            continue;
        }
        else if ((len == 0 && len + l > 80) || (len > 0 && len + l + 1 > 80)) {
            len = 0;
            printf("\n");
        }
        
        if (len == 0) {
            printf("%s", o);
            len--;
        }
        else printf(" %s", o);
        
        len += l+1;
    }
    if(len) printf("\n");
}
int main() {
    solv();
    return 0;
}