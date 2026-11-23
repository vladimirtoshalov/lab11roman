#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <locale.h>

typedef struct {
    char title[50];
    char author[50];
    int pages;
    double rating;
    int year;
} roman;

int inpp(roman* rom, int number);
void pp(roman rom);
int check(roman rom);

int main(void)
{
    setlocale(LC_ALL, ".UTF8");

    roman rom1, rom2, rom3;
    int с = 0;

    printf("Введите данные трех романов\n");
    printf("Название и автора вводите одним словом, пробелы заменяйте на _\n");

    if (inpr(&rom1, 1) == 0) {
        printf("Ошибка ввода данных романа 1\n");
        return 1;
    }

    if (inpr(&rom2, 2) == 0) {
        printf("Ошибка ввода данных романа 2\n");
        return 1;
    }

    if (inpr(&rom3, 3) == 0) {
        printf("Ошибка ввода данных романа 3\n");
        return 1;
    }

    printf("\nРоманы со страницами от 100 до 200 и оценкой больше 5\n");

    if (check(rom1)) {
        pp(rom1);
        с++;
    }

    if (check(rom2)) {
        pp(rom2);
        с++;
    }

    if (check(rom3)) {
        pp(rom3);
        с++;
    }

    if (с == 0) {
        printf("Подходящих романов нет\n");
    }

    return 0;
}

int inpr(roman* rom, int n)
{
    printf("\nРоман %d\n", n);

    printf("Название ");
    if (scanf("%s", rom->title) != 1) {
        return 0;
    }

    printf("Автор ");
    if (scanf("%s", rom->author) != 1) {
        return 0;
    }

    printf("Количество страниц ");
    if (scanf("%d", &rom->pages) != 1 || rom->pages <= 0) {
        return 0;
    }

    printf("Средняя оценка по отзывам от 0 до 10 ");
    if (scanf("%lf", &rom->rating) != 1 ||  rom->rating < 0.0 || rom->rating > 10.0) {
        return 0;
    }

    printf("Год издания ");
    if (scanf("%d", &rom->year) != 1 || rom->year <= 0) {
        return 0;
    }

    return 1;
}

void pp(roman rom)
{
    printf("Название %s\n", rom.title);
    printf("Автор %s\n", rom.author);
    printf("Количество страниц %d\n", rom.pages);
    printf("Средняя оценка %.2f из 10\n", rom.rating);
    printf("Год издания %d\n\n", rom.year);
}

int check(roman rom)
{
    if (rom.pages >= 100 && rom.pages <= 200 && rom.rating > 5.0) {
        return 1;
    }

    return 0;
}