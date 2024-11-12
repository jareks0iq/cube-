//#include <stdio.h>
//#include <stdlib.h>
//#include <locale.h>
//
//typedef struct {
//    int x, y, z;
//} Point;
//
//// Очередь для хранения координат точек
//typedef struct {
//    Point* points;
//    int front, rear, size;
//} Queue;
//
//// Функции для работы с очередью
//void initQueue(Queue* q, int size) {
//    q->points = (Point*)malloc(size * sizeof(Point));
//    q->front = 0;
//    q->rear = 0;
//    q->size = size;
//}
//
//int isEmpty(Queue* q) {
//    return q->front == q->rear;
//}
//
//void enqueue(Queue* q, int x, int y, int z) {
//    q->points[q->rear].x = x;
//    q->points[q->rear].y = y;
//    q->points[q->rear].z = z;
//    q->rear++;
//}
//
//Point dequeue(Queue* q) {
//    return q->points[q->front++];
//}
//
//void freeQueue(Queue* q) {
//    free(q->points);
//}
//
//// Проверка, находится ли точка в пределах параллелепипеда
//int isValid(int x, int y, int z, int X_MAX, int Y_MAX, int Z_MAX) {
//    return x >= 0 && x < X_MAX && y >= 0 && y < Y_MAX && z >= 0 && z < Z_MAX;
//}
//
//// Функция для нахождения минимальных шагов до ближайшей точки
//void calculateMinSteps(int x1, int y1, int z1, int x2, int y2, int z2, int X_MAX, int Y_MAX, int Z_MAX, int*** steps) {
//    Queue q;
//    initQueue(&q, X_MAX * Y_MAX * Z_MAX);
//
//    // Инициализация всех ячеек значением -1 (ещё не посещены)
//    for (int x = 0; x < X_MAX; x++) {
//        for (int y = 0; y < Y_MAX; y++) {
//            for (int z = 0; z < Z_MAX; z++) {
//                steps[x][y][z] = -1;
//            }
//        }
//    }
//
//    // Начальные точки
//    steps[x1][y1][z1] = 0;
//    steps[x2][y2][z2] = 0;
//    enqueue(&q, x1, y1, z1);
//    enqueue(&q, x2, y2, z2);
//
//    int directions[6][3] = { {1, 0, 0}, {-1, 0, 0}, {0, 1, 0}, {0, -1, 0}, {0, 0, 1}, {0, 0, -1} };
//
//    while (!isEmpty(&q)) {
//        Point current = dequeue(&q);
//
//        for (int i = 0; i < 6; i++) {
//            int nx = current.x + directions[i][0];
//            int ny = current.y + directions[i][1];
//            int nz = current.z + directions[i][2];
//
//            if (isValid(nx, ny, nz, X_MAX, Y_MAX, Z_MAX) && steps[nx][ny][nz] == -1) {
//                steps[nx][ny][nz] = steps[current.x][current.y][current.z] + 1;
//                enqueue(&q, nx, ny, nz);
//            }
//        }
//    }
//
//    freeQueue(&q);
//}
//
//int main() {
//    setlocale(LC_ALL, "RUS");
//    int X_MAX, Y_MAX, Z_MAX;
//    printf("Введите размеры параллелепипеда (X Y Z): ");
//    scanf_s("%d %d %d", &X_MAX, &Y_MAX, &Z_MAX);
//
//    int x1, y1, z1, x2, y2, z2;
//    printf("Введите координаты первой точки (x1 y1 z1): ");
//    scanf_s("%d %d %d", &x1, &y1, &z1);
//    printf("Введите координаты второй точки (x2 y2 z2): ");
//    scanf_s("%d %d %d", &x2, &y2, &z2);
//
//    // Создание 3D массива
//    int*** steps = (int***)malloc(X_MAX * sizeof(int**));
//    for (int x = 0; x < X_MAX; x++) {
//        steps[x] = (int**)malloc(Y_MAX * sizeof(int*));
//        for (int y = 0; y < Y_MAX; y++) {
//            steps[x][y] = (int*)malloc(Z_MAX * sizeof(int));
//        }
//    }
//
//    // Вычисление минимальных шагов
//    calculateMinSteps(x1, y1, z1, x2, y2, z2, X_MAX, Y_MAX, Z_MAX, steps);
//
//    // Вывод всех слоев по оси Z
//    for (int z = 0; z < Z_MAX; z++) {
//        printf("Слой Z = %d\n", z);
//        for (int y = 0; y < Y_MAX; y++) {
//            for (int x = 0; x < X_MAX; x++) {
//                printf("%2d ", steps[x][y][z]);
//            }
//            printf("\n");
//        }
//        printf("\n");
//    }
//
//    // Освобождение памяти
//    for (int x = 0; x < X_MAX; x++) {
//        for (int y = 0; y < Y_MAX; y++) {
//            free(steps[x][y]);
//        }
//        free(steps[x]);
//    }
//    free(steps);
//
//    return 0;
//}
