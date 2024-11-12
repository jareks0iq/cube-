#include <stdio.h>
#include <locale.h>
int field[30][20][35], count = 0; // z x y
int input(max) {
	char xx[100];
	int flag = 0, x1 = 0;
	gets(xx);
	for (int i = 0; i < strlen(xx); i++) {
		if (isdigit(xx[i])) {
			flag = 0;
			continue;
		}
		else {
			flag = 1;
			break;
		}
	}
	if (flag == 0 && strlen(xx) <= 2 && strlen(xx) > 0) {
		sscanf_s(xx, "%d", &x1);
		if (x1 <= max && x1 >= 1) { return x1; }
		else { return -1; }
	}
	else { return -1; }
}
int godrecursion(x1, y1, z1, x, y, z) {
	int ret = 0;
	if (x1 == x && y1 == y && z1 == z) { return 1; }
	if (x > x1) {
		ret = godrecursion(x1 + 1, y1, z1, x, y, z);
		if (ret == 1) {
			count++;
		}
	}
	if (x != x1 && x < x1 && ret == 0) {
		ret = godrecursion(x1 - 1, y1, z1, x, y, z);
		if (ret == 1) {
			count++;
		}
	}
	if (y != y1 && y > y1 && ret == 0) {
		ret = godrecursion(x1, y1 + 1, z1, x, y, z);
		if (ret == 1) {
			count++;
		}
	}
	if (y != y1 && y < x1 && ret == 0) {
		ret = godrecursion(x1, y1 - 1, z1, x, y, z);
		if (ret == 1) {
			count++;
		}
	}
	if (z != z1 && z > z1 && ret == 0) {
		ret = godrecursion(x1, y1, z1 + 1, x, y, z);
		if (ret == 1) {
			count++;
		}
	}
	if (z != z1 && z < z1 && ret == 0) {
		ret = godrecursion(x1, y1, z1 - 1, x, y, z);
		if (ret == 1) {
			count++;
		}
	}
	return ret;
}
void decision(x1, y1, z1, x2, y2, z2, x, y, z) {
	int k1 = 0, k2 = 0;
	godrecursion(x1, y1, z1, x, y, z);
	k1 = count;
	count = 0;
	godrecursion(x2, y2, z2, x, y, z);
	k2 = count;
	//k1 = abs(x - x1) + abs(y - y1) + abs(z - z1);
	//k2 = abs(x - x2) + abs(y - y2) + abs(z - z2);
	if (k1 < k2) {
		field[z][x-1][y-1] = k1;
	}
	else if (k2 < k1) {
		field[z][x-1][y-1] = k2;
	}
	else {
		field[z][x-1][y-1] = k1;
	}
}
void printarr(z, x, y) {
	for (int i = 0; i < x; i++) {
		for (int j = 0; j < y; j++) {
			printf("%3d", field[z][i][j]);
		}
		printf("\n");
	}
}
int main() {
	memset(field, -1, sizeof(field));
	setlocale(LC_ALL, "RUS");
	int x = 0, y = 0, z = 0, x1 = 0, y1 = 0, z1 = 0, x2 = 0, y2 = 0, z2 = 0;
	printf("¬ведит координаты параллелепипеда: \n");
	printf("X (1 - 20): ");
	x = input(20);
	printf("Y (1 - 35): ");
	y = input(35);
	printf("Z (1 - 30): ");
	z = input(30);
	printf("¬ведит координаты первой точки: \n");
	printf("X (1 - %d): ", x);
	x1 = input(x);
	printf("Y (1 - %d): ", y);
	y1 = input(y);
	printf("Z (1 - %d): ", z);
	z1 = input(z);
	printf("¬ведит координаты второй точки: \n");
	printf("X (1 - %d): ", x);
	x2 = input(x);
	printf("Y (1 - %d): ", y);
	y2 = input(y);
	printf("Z (1 - %d): ", z);
	z2 = input(z);
	for (int w = 0; w <= z; w++) {
		printf("%d) \n", w+1);
		for (int i = 1; i <= x; i++) {
			for (int j = 1; j <= y; j++) {
				count = 0;
				decision(x1, y1, z1, x2, y2, z2, i, j, w);
				count = 0;
			}
		}
		printarr(w, x, y);
		printf("\n");

	}
}