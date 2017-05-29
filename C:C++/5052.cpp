#include <cstdio>
#include <cstdlib>
struct node {
    int val;
    node *nxt[10];
};
void make_node(int m, char *gstr, node *here) {
    for(;gstr[m] != '\0';m++) {
        if(here->nxt[gstr[m] - '0'] == NULL) here->nxt[gstr[m] - '0'] = (node *)calloc(1, sizeof(node));
        here = here->nxt[gstr[m] - '0'];
    }
    here->val = 1;
}
int clear(node *here) {
    int sav = 0;
    for(int i=0;i<10;i++) {
        if(here->nxt[i] == NULL) continue;
        sav |= here->val;
        sav |= clear(here->nxt[i]);
    }
    free(here);
    return sav;
}
int main() {
    int i, t, n;
    char o[11];
    node *trie;
    scanf("%d",&t);
    while(t--) {
        scanf("%d",&n);
        trie = (node *)calloc(1, sizeof(node));
        for(i=0;i<n;i++) {
            scanf("%s",o);
            make_node(0, o, trie);
        }
        printf("%s\n", clear(trie) ? "NO" : "YES");
    }
    return 0;
}