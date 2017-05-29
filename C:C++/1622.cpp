#include <stdio.h>
#include <string.h>
int o[30], u[30];
char x1[10005], x2[10005];
int n, m;
int main() {
    int i, j;
    int k;
    while(gets(x1) != NULL) {
        gets(x2);

        n = strlen(x1);
        m = strlen(x2);
        memset(o, 0, sizeof(o));
        memset(u, 0, sizeof(u));
        for(i=0;i<n;i++) if(x1[i] >= 'a' && x1[i] <='z') o[x1[i]-'a']++;
        for(i=0;i<m;i++) if(x2[i] >= 'a' && x2[i] <='z') u[x2[i]-'a']++;
        for(i=0;i<26;i++) {
            k = o[i] < u[i] ? o[i] : u[i];
            for(j=0;j<k;j++) printf("%c",'a'+i);
        }
        printf("\n");
    }
    return 0;
}