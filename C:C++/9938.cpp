#include <stdio.h>
#include <vector>
using namespace std;
bool getin[300011];
bool cant[300011];
int color_info[300011];
int node_color[300011];
vector<int> node[300011];
int main() {
	int n, m;
	int x, y;
	int e = 0;
	int tmp;
	int e1, e2;
	int i;
	scanf("%d %d", &n, &m);
	for (i = 1; i <= n; i++) {
		scanf("%d %d", &x, &y);
		if (!getin[x]) {
			getin[x] = true;
			if (node_color[x] == 0 && node_color[y] == 0) {
				node_color[x] = node_color[y] = ++e;
				color_info[e] = y;
				node[e].push_back(x);
				node[e].push_back(y);
			}
			else if (node_color[y] != 0 && node_color[x] == 0) {
				node_color[x] = tmp = node_color[y];
				node[tmp].push_back(x);
			}
			else if (node_color[y] == 0 && node_color[x] != 0) {
				node_color[y] = tmp = node_color[x];
				color_info[tmp] = y;
				node[tmp].push_back(y);
			}
			else {
				e1 = node_color[x];
				e2 = node_color[y];
				tmp = node_color[y];
				if (e1 == e2) {
					cant[e1] = true;
					printf("LADICA\n");
					continue;
				}
				if (node[e1].size() > node[e2].size()) {
					if (cant[e2]) cant[e1] = true;
					if (cant[e1]) cant[e2] = true;
					color_info[e1] = color_info[tmp];
					color_info[e2] = -1;
					while (node[e2].size()) {
						tmp = node[e2].back();
						node[e2].pop_back();

						node[e1].push_back(tmp);
						node_color[tmp] = e1;
					}
				}
				else {
					if (cant[e2]) cant[e1] = true;
					if (cant[e1]) cant[e2] = true;
					color_info[e2] = color_info[tmp];
					color_info[e1] = -1;
					while (node[e1].size()) {
						tmp = node[e1].back();
						node[e1].pop_back();

						node[e2].push_back(tmp);
						node_color[tmp] = e2;
					}
				}
			}
			printf("LADICA\n");
		}
		else if (!getin[y]) {
			getin[y] = true;
			if (node_color[y] == 0 && node_color[x] == 0) {
				node_color[y] = node_color[x] = ++e;
				color_info[e] = x;
				node[e].push_back(x);
				node[e].push_back(y);
			}
			else if (node_color[x] != 0 && node_color[y] == 0) {
				node_color[y] = tmp = node_color[x];
				node[tmp].push_back(y);
			}
			else if (node_color[x] == 0 && node_color[y] != 0) {
				node_color[x] = tmp = node_color[y];
				color_info[tmp] = x;
				node[tmp].push_back(x);
			}
			else {
				e1 = node_color[x];
				e2 = node_color[y];
				tmp = node_color[x];
				if (e1 == e2) {
					cant[e1] = true;
					printf("LADICA\n");
					continue;
				}
				if (node[e1].size() > node[e2].size()) {
					if (cant[e2]) cant[e1] = true;
					if (cant[e1]) cant[e2] = true;
					color_info[e1] = color_info[tmp];
					color_info[e2] = -1;
					while (node[e2].size()) {
						tmp = node[e2].back();
						node[e2].pop_back();

						node[e1].push_back(tmp);
						node_color[tmp] = e1;
					}
				}
				else {
					if (cant[e2]) cant[e1] = true;
					if (cant[e1]) cant[e2] = true;
					color_info[e2] = color_info[tmp];
					color_info[e1] = -1;
					while (node[e1].size()) {
						tmp = node[e1].back();
						node[e1].pop_back();

						node[e2].push_back(tmp);
						node_color[tmp] = e2;
					}
				}
			}
			printf("LADICA\n");
		}
		else {
			if (node_color[x] == node_color[y]) {
				if (cant[node_color[x]]) {
					printf("SMECE\n");
					continue;
				}
				else {
					getin[color_info[node_color[x]]] = true;
					cant[node_color[x]] = true;
				}
			}
			else {
				e1 = node_color[x];
				e2 = node_color[y];
				if (cant[e1] && cant[e2]) {
					printf("SMECE\n");
					continue;
				}
				if (node[e1].size() > node[e2].size()) {
					if (cant[e2]) {
						getin[color_info[e1]] = true;
						cant[e1] = true;
					}
					if (cant[e1]) {
						getin[color_info[e2]] = true;
						cant[e2] = true;
					}
					getin[color_info[e1]] = true;
					color_info[e1] = color_info[e2];
					color_info[e2] = -1;
					while (node[e2].size()) {
						tmp = node[e2].back();
						node[e2].pop_back();

						node[e1].push_back(tmp);
						node_color[tmp] = e1;
					}
				}
				else {
					if (cant[e2]) {
						getin[color_info[e1]] = true;
						cant[e1] = true;
					}
					if (cant[e1]) {
						getin[color_info[e2]] = true;
						cant[e2] = true;
					}
					getin[color_info[e1]] = true;
					color_info[e1] = -1;
					while (node[e1].size()) {
						tmp = node[e1].back();
						node[e1].pop_back();

						node[e2].push_back(tmp);
						node_color[tmp] = e2;
					}
				}
			}
			printf("LADICA\n");
		}
	}
	return 0;
}