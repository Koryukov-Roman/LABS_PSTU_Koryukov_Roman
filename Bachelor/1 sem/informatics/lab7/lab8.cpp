#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <clocale>

typedef struct {
    char carrier[30]; //? носитель
    int volume; //? объем
    char title[30]; //? название
    char author[30]; //? автор
} Info;

//todo функция открытия файла с проверкой ошибки
FILE* openFile(char* name, char* mode) {
    FILE *f = fopen(name, mode);
    if (!f) { perror("Ошибка файла"); exit(1); }
    return f;
}

//todo 1. создание файла
void createFile(char* name) {
    FILE *f = openFile(name, "wb");
    Info x;
    int n;
    printf("Количество записей: ");
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        printf("Запись %d (носитель, объем, название, автор): ", i + 1);
        scanf("%s %d %s %s", x.carrier, &x.volume, x.title, x.author);
        fwrite(&x, sizeof(Info), 1, f);
    }
    fclose(f);
}

//todo 2. Печать файла
void printFile(char* name) {
    FILE *f = openFile(name, "rb");
    Info x;
    int i = 1;
    printf("\n--- Содержимое файла ---\n");
    while (fread(&x, sizeof(Info), 1, f) == 1)
        printf("%d. %s | %d | %s | %s\n", i++, x.carrier, x.volume, x.title, x.author);
    fclose(f);
}

//todo 3. Поиск позиции по объему или проверка номера
int findPos(char* name, int val, int mode) {
    FILE *f = openFile(name, "rb");
    Info x;
    int i = 1, res = -1;
    while (fread(&x, sizeof(Info), 1, f) == 1) {
        if ((mode == 1 && x.volume == val) || (mode == 2 && i == val)) {
            res = i;
            break;
        }
        i++;
    }
    fclose(f);
    return res;
}

//todo 4. Удаление первого элемента
void delByVolume(char* name, int vol) {
    int pos = findPos(name, vol, 1);
    if (pos == -1) { printf("Элемент не найден!\n"); return; }

    FILE *f = openFile(name, "rb");
    FILE *t = openFile("temp.dat", "wb");
    Info x;
    int i = 1;
    while (fread(&x, sizeof(Info), 1, f) == 1) {
        if (i++ != pos) fwrite(&x, sizeof(Info), 1, t);
    }
    fclose(f); fclose(t);
    remove(name);
    rename("temp.dat", name);
}

//todo 5. Добавление элемента
void addBefore(char* name, int num) {
    if (findPos(name, num, 2) == -1) { printf("Неверный номер.\n"); return; }

    Info newX, x;
    printf("Новый элемент (носитель, объем, название, автор): ");
    scanf("%s %d %s %s", newX.carrier, &newX.volume, newX.title, newX.author);

    FILE *f = openFile(name, "rb");
    FILE *t = openFile("temp.dat", "wb");
    int i = 1;
    while (fread(&x, sizeof(Info), 1, f) == 1) {
        if (i++ == num) fwrite(&newX, sizeof(Info), 1, t);
        fwrite(&x, sizeof(Info), 1, t);
    }
    fclose(f); fclose(t);
    remove(name);
    rename("temp.dat", name);
}

int main() {
    setlocale(LC_ALL, "Russian.UTF8");
    char file[] = "info.dat";
    int vol, num;

    createFile(file);
    printFile(file);

    printf("\nудаление: ");
    scanf("%d", &vol);
    delByVolume(file, vol);
    printFile(file);

    printf("\nНомер элемента, перед которым добавить: ");
    scanf("%d", &num);
    addBefore(file, num);
    printFile(file);

    return 0;
}