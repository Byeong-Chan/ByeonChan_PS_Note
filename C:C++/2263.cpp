#include <cstdio>
#include <cstdlib>
struct node {
    int val;
    node *left;
    node *right;
};
int pos[100010];
int p[100010];
int k;
void sub(node *here, int l, int r) {
    if (k == 0) return;
    if (l == r) return;
    
    int d = pos[here->val];
    
    int nxt = pos[p[k]];
    if (nxt > d && nxt < r) {
        here->right = (node *)calloc(1, sizeof(node));
        here->right->val = p[k--];
        sub(here->right, d+1, r);
    }
    
    if(k == 0) return;
    nxt = pos[p[k]];
    if (nxt >= l && nxt < d) {
        here->left = (node *)calloc(1, sizeof(node));
        here->left->val = p[k--];
        sub(here->left, l, d);
    }
}
void clear(node *here) {
    if(here->left != NULL) clear(here->left);
    if(here->right != NULL) clear(here->right);
    free(here);
}
void pre_order(node *here) {
    printf("%d ",here->val);
    if(here->left != NULL) pre_order(here->left);
    if(here->right != NULL) pre_order(here->right);
}
int main() {
    int i, n;
    int x;
    node *root = (node *)calloc(1, sizeof(node));
    scanf("%d",&n);
    for(i=0;i<n;i++) {
        scanf("%d",&x);
        pos[x] = i;
    }
    for(i=1;i<=n;i++) scanf("%d",&p[i]);
    k = n;
    root->val = p[k--];
    sub(root, 0, n);
    pre_order(root);
    printf("\n");
    clear(root);
    return 0;
}