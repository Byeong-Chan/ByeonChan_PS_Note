#include <cstdio>
#include <cstdlib>
#include <cstring>
struct node {
	bool chk;
	node *nxt[26];
};
void clear(node *pos) {
	int i;
	for (i = 0; i < 26; i++) if (pos->nxt[i] != NULL) clear(pos->nxt[i]);
	free(pos);
}
node *create(node *pos) {
	node *tmp = (node *)calloc(1, sizeof(node));
	return tmp;
}
char p[300];
char s[10100];
char ans[300];
int main() {
	int i;
	int t;
	int cnt, tmp;
	int len;
	char *k;
	node *trie;
	node *now;
	scanf("%d\n", &t);
	while (t--) {
		trie = (node *)calloc(1, sizeof(node));
		scanf("%[^\n]\n", s);
		while (1) {
			scanf("%[^\n]\n", p);
			if (strcmp(p, "what does the fox say?") == 0) {
				now = trie;
				len = 0;
				for (k = s; (*k) != NULL; k++) {
					if ((*k) == ' ') {
						ans[len] = NULL;
						if(now == NULL || (now != NULL && !(now->chk))) printf("%s ", ans);
						len = 0;
						now = trie;
					}
					else {
						ans[len++] = *k;
						tmp = (*k) - 'a';
						if (now != NULL) now = now->nxt[tmp];
					}
				}
				ans[len] = NULL;
				if(now == NULL || (now != NULL && !(now->chk))) printf("%s", ans);

				break;
			}
			cnt = 0;
			now = trie;
			for (k = p; (*k) != NULL; k++) {
				if (cnt == 2) {
					tmp = (*k) - 'a';
					if (now->nxt[tmp] == NULL) now = ((now->nxt[tmp]) = create(now));
					else now = (now->nxt[tmp]);
				}
				if (*k == ' ') cnt++;
			}
			now->chk = true;
		}
		printf("\n");
		clear(trie);
	}
	return 0;
}