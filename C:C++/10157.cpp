#include <stdio.h>
#include <math.h>
int main() {
	bool sw = false;
	int x, k, h;
	int n, m;
	int c;
	int posx, posy;
	int holdy;
	scanf("%d %d", &n, &m);
	scanf("%d", &h);
	if (n*m < h) {
		printf("0\n");
		return 0;
	}
	k = n + m - 1;
	x = (int)sqrt(k*(k + 2) - 4 * h + 1) - 1;

	c = (k - x);
	if (c & 1 || (c*c / 4 + c / 2 + c*x / 2) != h) {
		if (c & 1) c--;
		else c -= 2;

		x = k - c;

		h -= (c*c / 4 + c / 2 + c*x / 2);

		c /= 2;

		holdy = m - c;

		if (c == 0) {
			posx = 1;
			posy = 0;
			sw = true;
		}
		else if (c & 1) {
			posx = n - c / 2;
			posy = m - c / 2;
		}
		else {
			posx = 1 + c / 2;
			posy = 0 + c / 2;
			sw = true;
		}
		if (sw) {
			if (h - holdy <= 0) posy += h;
			else {
				posy += holdy;
				h -= holdy;
				posx += h;
			}
		}
		else {
			if (h - holdy <= 0) posy -= h;
			else {
				posy -= holdy;
				h -= holdy;
				posx -= h;
			}
		}
	}
	else {
		c = c / 2;
		if (c & 1) {
			posx = n - c / 2;
			posy = m - c / 2;
		}
		else {
			posx = 1 + c / 2;
			posy = 0 + c / 2;
		}
	}
	printf("%d %d", posx, posy);
	return 0;
}