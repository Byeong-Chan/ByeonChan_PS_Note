#include <cstdio>
#include <cstdlib>
struct node {
    node *nxt[26];
};
void make_node(int m, char *gstr, node *here) {
    for(;gstr[m] != '\0'; m++) {
        if(here->nxt[gstr[m]-'a'] == NULL) here->nxt[gstr[m]-'a'] = (node *)calloc(1,sizeof(node));
        here = here->nxt[gstr[m] - 'a'];
    }
}
bool find(int m, char *gstr, node *here) {
    for(;gstr[m] != '\0' && here != NULL; m++) here = here->nxt[gstr[m] - 'a'];
    if(here == NULL) return false;
    else return true;
}
void clear(node *here) {
    for(int i=0;i<26;i++) {
        if(here->nxt[i] == NULL) continue;
        clear(here->nxt[i]);
    }
    free(here);
}
int main() {
    int i;
    int n, m;
    int ans = 0;
    char o[510];
    node *trie = (node *)calloc(1, sizeof(node));
    scanf("%d %d",&n,&m);
    for(i=0;i<n;i++) {
        scanf("%s",o);
        make_node(0, o, trie);
    }
    for(i=0;i<m;i++) {
        scanf("%s",o);
        if(find(0, o, trie)) ans++;
    }
    printf("%d\n",ans);
    clear(trie);
    return 0;
}