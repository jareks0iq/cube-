//#include <stdio.h>
//#include <stdbool.h>
//#include <locale.h>
//#include <stdlib.h>
//#include <string.h>
//#include <ctype.h>
//#include <conio.h>
//
//char lab[20][20];
//int spawnx = 1, spawny = 1, flag = 0, start = 0, sx = 0, sy = 0, end = 0, ex = 0, ey = 0, wx = 0, wy = 0, count = 0;
//int vvod() {
//	printf("Введите ширину от 3 до 20 включительно: ");
//	char xx[100];
//	int flag = 0, x1 = 0;
//	gets(xx);
//	for (int i = 0; i < strlen(xx); i++) {
//		if (isdigit(xx[i])) {
//			flag = 0;
//			continue;
//		}
//		else {
//			flag = 1;
//			break;
//		}
//	}
//	if (flag == 0 && strlen(xx) <= 2 && strlen(xx) > 0) {
//		sscanf_s(xx, "%d", &x1);
//		if (x1 <= 20 && x1 >= 3) { return x1; }
//		else { return -1; }
//	}
//	else { return -1; }
//}
//void walls(int x, int y, int h) {
//	for (int i = 0; i < x; i++) {
//		for (int j = 0; j < y; j++) {
//			if (i == 0 || j == 0 || i == x - 1 || j == y - 1) {
//				lab[i][j] = '#';
//			}
//			else {
//				if (lab[i][j] != '#' && h != 2) {
//					lab[i][j] = '.';
//				}
//			}
//		}
//	}
//}
//void printwalls(int x, int y) {
//	for (int i = 0; i < x; i++) {
//		for (int j = 0; j < y; j++) {
//			_putch(lab[i][j]);
//		}
//		_putch('\n');
//	}
//}
//void move(deltax, deltay, x, y) {
//	int x1 = spawnx + deltax;
//	int y1 = spawny + deltay;
//	if (x1 == -1 || y1 == -1 || x1 == y || y1 == x) {
//		spawnx += 0;
//		spawny += 0;
//	}
//	else {
//		spawnx += deltax;
//		spawny += deltay;
//	}
//}
//void printstart() {
//	if (lab[spawny][spawnx] != '#') {
//		lab[spawny][spawnx] = '+';
//	}
//}
//void pressstart(int sx, int sy, int x, int y) {
//	if (sy == 0 || sx == 0 || sy == y - 1 || sx == x - 1) { lab[sy][sx] = '#'; }
//	else { lab[sy][sx] = 's'; }
//}
//void pressend(int x, int y) {
//	lab[y][x] = 'e';
//}
//void keyboard(x, y) {
//	int ch = _getch();
//	switch (ch) {
//	case 72: move(0, -1, x, y); break;
//	case 80: move(0, 1, x, y); break;
//	case 75: move(-1, 0, x, y); break;
//	case 77: move(1, 0, x, y); break;
//	case 27: flag = 1; break;
//	case 115: start = 1; sy = spawny; sx = spawnx; break;
//	case 101: end = 1; ey = spawny; ex = spawnx; break;
//	case 119: lab[spawny][spawnx] = '#'; break;
//	case 8: lab[spawny][spawnx] = '.'; break;
//	}
//}
//void labirint(int x, int y, int h) {
//	walls(x, y, h);
//	if (start == 1) { pressstart(sx, sy, x, y); }
//	if (end == 1) { pressend(ex, ey); }
//	if (h == 1) { printstart(); }
//	printwalls(x, y);
//}
//int decision(int sx, int sy, int ex, int ey, char lab[20][20], int dec[20][20], int x, int y) {
//	int ret = 0;
//	dec[sy][sx] = 1;
//	if (lab[sy][sx] == 'e') return 1;
//	if (sx < y - 1 && (lab[sy][sx + 1] == '.' || lab[sy][sx + 1] == 'e') && dec[sy][sx + 1] == 0) {
//		ret = decision(sx + 1, sy, ex, ey, lab, dec, x, y);
//		if (ret == 1) {
//			if (lab[sy][sx + 1] != 'e') { lab[sy][sx + 1] = '*'; }
//			count++;
//		}
//	}
//	if (!ret && sy < y - 1 && (lab[sy + 1][sx] == '.' || lab[sy + 1][sx] == 'e') && dec[sy + 1][sx] == 0) {
//		ret = decision(sx, sy + 1, ex, ey, lab, dec, x, y);
//		if (ret == 1) {
//			if (lab[sy + 1][sx] != 'e') { lab[sy + 1][sx] = '*'; };
//			count++;
//		}
//	}
//	if (!ret && sy > 0 && (lab[sy - 1][sx] == '.' || lab[sy - 1][sx] == 'e') && dec[sy - 1][sx] == 0) {
//		ret = decision(sx, sy - 1, ex, ey, lab, dec, x, y);
//		if (ret == 1) {
//			if (lab[sy - 1][sx] != 'e') { lab[sy - 1][sx] = '*'; };
//			count++;
//		}
//	}
//	if (!ret && sx > 0 && (lab[sy][sx - 1] == '.' || lab[sy][sx - 1] == 'e') && dec[sy][sx - 1] == 0) {
//		ret = decision(sx - 1, sy, ex, ey, lab, dec, x, y);
//		if (ret == 1) {
//			if (lab[sy][sx - 1] != 'e') { lab[sy][sx - 1] = '*'; };
//			count++;
//		}
//	}
//	return ret;
//}
//int main() {
//	setlocale(LC_ALL, "RUS");
//	int k1 = 1, x = 20, y = 20;
//	char provx = '+', provy = '+';
//	printf("> 1) Создание лабиринта \n");
//	printf("2) Поиск решения \n");
//	printf("3) Выход \n");
//	while (true) {
//		int p = getch();
//		if (p == 49 || (p == 13 && k1 == 1)) {
//			k1 = 1;
//			system("cls");
//			int k2 = 1;
//			int ch = 0;
//			printf("Размер лабиринта (мин. 3х3, макс. 20х20): \n \n");
//			if (x != -1) { printf("> 1) Ширина: %d\n", x); }
//			else { printf("> 1) Ширина: некорректное значение\n"); }
//			printf("2) Высота: %d \n", y);
//			printf("3) Продолжить \n");
//			printf("\nДля выхода назад нажмите ESC");
//			while (ch != 27) {
//				ch = _getch();
//				if (ch == 49 || (ch == 13 && k2 == 1)) {
//					k2 = 1;
//					system("cls");
//					printf("Введите ширину от 3 до 20 включительно: ");
//					x = vvod();
//					memset(lab, 0, sizeof(lab));
//					spawnx = 1, spawny = 1, flag = 0, start = 0, sx = 0, sy = 0, end = 0, ex = 0, ey = 0, wx = 0, wy = 0;
//					if (x != -1) { provx = '+'; }
//					else { provx = '-'; }
//				}
//				else if (ch == 50 || (ch == 13 && k2 == 2)) {
//					k2 = 2;
//					system("cls");
//					printf("Введите длину от 3 до 20 включительно: ");
//					y = vvod();
//					memset(lab, 0, sizeof(lab));
//					spawnx = 1, spawny = 1, flag = 0, start = 0, sx = 0, sy = 0, end = 0, ex = 0, ey = 0, wx = 0, wy = 0;
//					if (y != -1) { provy = '+'; }
//					else { provy = '-'; }
//				}
//				else if (ch == 51 || (ch == 13 && k2 == 3)) {
//					k2 = 3;
//					if (x == -1 || y == -1) {
//						int chp = 0;
//						system("cls");
//						printf("Были введены не все значения!\n");
//						printf("\nДля выхода назад нажмите ESC");
//						while (chp != 27) {
//							chp = _getch();
//							system("cls");
//							printf("Были введены не все значения!\n");
//							printf("\nДля выхода назад нажмите ESC");
//						}
//						printf("Размер лабиринта (мин. 3х3, макс. 20х20): \n \n");
//						printf("1) Ширина: %d\n", x);
//						printf("2) Высота: %d \n", y);
//						printf("> 3) Продолжить \n");
//						printf("\nДля выхода назад нажмите ESC");
//					}
//					else {
//						int k3 = 1;
//						int key = 0;
//						system("cls");
//						printf("> 1) Создать новый лабиринт \n");
//						printf("2) Редактировать предыдущий лабиринт \n");
//						printf("\nДля выхода назад нажмите ESC");
//						while (key != 27) {
//							key = _getch();
//							if (key == 49 || (key == 13 && k3 == 1)) {
//								memset(lab, 0, sizeof(lab));
//								spawnx = 1, spawny = 1, flag = 0, start = 0, sx = 0, sy = 0, end = 0, ex = 0, ey = 0, wx = 0, wy = 0;
//								k3 = 1;
//								system("cls");
//								while (flag == 0) {
//									system("cls");
//									printf("Двигаться по лабиринту на стрелочки! \n \n");
//									printf("Для установки начала нажмите S!    Для очищения стенки нажмите BACKSPACE!\n");
//									printf("Для установки конца нажмите E! \n");
//									printf("Для установки стенки нажмите W! \n");
//									printf("\nДля выхода назад нажмите ESC\n\n");
//									labirint(x, y, 1);
//									keyboard(x, y);
//								}
//								for (int i = 0; i < x; i++) {
//									for (int j = 0; j < y; j++) {
//										if (lab[i][j] == '+') {
//											if (i == sy && j == sx) { lab[i][j] = 's'; }
//											if (i == ey && j == ex) { lab[i][j] = 'e'; }
//											else { lab[i][j] = '.'; }
//										}
//									}
//								}
//								flag = 0;
//								spawnx = 0, spawny = 0;
//							}
//							else if (key == 50 || (key == 13 && k3 == 2)) {
//								k3 = 2;
//								while (flag == 0) {
//									system("cls");
//									printf("Двигаться по лабиринту на стрелочки! \n \n");
//									printf("Для установки начала нажмите S!    Для очищения стенки нажмите BACKSPACE!\n");
//									printf("Для установки конца нажмите E! \n");
//									printf("Для установки стенки нажмите W! \n");
//									printf("\nДля выхода назад нажмите ESC\n\n");
//									labirint(x, y, 1);
//									keyboard(x, y);
//								}
//								for (int i = 0; i < x; i++) {
//									for (int j = 0; j < y; j++) {
//										if (lab[i][j] == '+') {
//											lab[i][j] = '.';
//										}
//									}
//								}
//								flag = 0;
//								spawnx = 0, spawny = 0;
//							}
//							else if (key == 80) {
//								if (k3 == 2) { continue; }
//								else { k3++; }
//							}
//							else if (key == 72) {
//								if (k3 == 1) { continue; }
//								else { k3--; }
//							}
//							system("cls");
//							if (k3 == 1) { printf("> 1) Создать новый лабиринт \n"); }
//							else { printf("1) Создать новый лабиринт \n"); }
//							if (k3 == 2) { printf("> 2) Редактировать предыдущий лабиринт"); }
//							else { printf("2) Редактировать предыдущий лабиринт"); }
//							printf("\n \nДля выхода назад нажмите ESC");
//						}
//						printf("> 1) Создать новый лабиринт \n");
//						printf("2) Редактировать предыдущий лабиринт");
//						printf("\nДля выхода назад нажмите ESC");
//					}
//				}
//				else if (ch == 80) {
//					if (k2 == 3) { continue; }
//					else { k2++; }
//				}
//				else if (ch == 72) {
//					if (k2 == 1) { continue; }
//					else { k2--; }
//				}
//				system("cls");
//				printf("Размер лабиринта (мин. 3х3, макс. 20х20): \n \n");
//				if (k2 == 1) {
//					if (x != -1) { printf("> 1) Ширина: %d\n", x); }
//					else { printf("> 1) Ширина: некорректное значение \n"); }
//				}
//				else {
//					if (x != -1) { printf("1) Ширина: %d\n", x); }
//					else { printf("1) Ширина: некорректное значение \n"); }
//				}
//				if (k2 == 2) {
//					if (y != -1) { printf("> 2) Высота: %d \n", y); }
//					else { printf("> 2) Высота: некорректное значение \n"); }
//				}
//				else {
//					if (y != -1) { printf("2) Высота: %d \n", y); }
//					else { printf("2) Высота: некорректное значение \n"); }
//				}
//				if (k2 == 3) {
//					printf("> 3) Продолжить \n");
//				}
//				else {
//					printf("3) Продолжить \n");
//				}
//				printf("\nДля выхода назад нажмите ESC");
//			}
//			printf("> 1) Создание лабиринта \n");
//			printf("2) Поиск решения \n");
//			printf("3) Выход \n");
//		}
//		else if (p == 50 || (p == 13 && k1 == 2)) {
//			k1 = 2;
//			count = 0;
//			int dec[20][20];
//			memset(dec, 0, sizeof(dec));
//			int ch = 0;
//			system("cls");
//			if (sy == 0 || sx == 0 || sy == y - 1 || sx == x - 1) {
//				printf("Был не введён старт лабиринта \n");
//				printf("Для выхода назад нажмите ESC");
//				while (ch != 27) {
//					ch = _getch();
//					system("cls");
//					printf("Был не введён старт лабиринта \n");
//					printf("Для выхода назад нажмите ESC");
//				}
//			}
//			else {
//				if (decision(sx, sy, ex, ey, lab, dec, x, y)) {
//					printf("Решение лабиринта! \n");
//					printf("Для выхода назад нажмите ESC\n \n");
//					printf("Финиш! Шагов для решения: %d\n", count);
//					printwalls(x, y);
//					while (ch != 27) {
//						ch = _getch();
//						system("cls");
//						printf("Решение лабиринта! \n");
//						printf("Для выхода назад нажмите ESC\n \n");
//						printf("Финиш! Шагов для решения: %d\n", count);
//						printwalls(x, y);
//					}
//				}
//				else {
//					printf("Решение лабиринта! \n");
//					printf("Для выхода назад нажмите ESC\n \n");
//					printf("Нет решений! \n");
//					printwalls(x, y);
//					while (ch != 27) {
//						ch = _getch();
//						system("cls");
//						printf("Решение лабиринта! \n");
//						printf("Для выхода назад нажмите ESC\n \n");
//						printf("Нет решений! \n");
//						printwalls(x, y);
//					}
//				}
//			}
//			printf("1) Создание лабиринта \n");
//			printf("> 2) Поиск решения \n");
//			printf("3) Выход \n");
//
//		}
//		else if (p == 51 || (p == 13 && k1 == 3)) {
//			k1 = 3;
//			exit(1);
//		}
//		else if (p == 80) {
//			if (k1 == 3) { continue; }
//			else { k1++; }
//		}
//		else if (p == 72) {
//			if (k1 == 1) { continue; }
//			else { k1--; }
//		}
//		system("cls");
//		if (k1 == 1) { printf("> 1) Создание лабиринта \n"); }
//		else { printf("1) Создание лабиринта \n"); }
//		if (k1 == 2) { printf("> 2) Поиск решения \n"); }
//		else { printf("2) Поиск решения \n"); }
//		if (k1 == 3) { printf("> 3) Выход \n"); }
//		else { printf("3) Выход \n"); }
//	}
//	return 0;
//}