/**
 * @file file_handler.c
 * @brief Реализация функций для работы с файлами
 * @author Козлов Максим
 */
#include <stdio.h>
#include <string.h>
#include "../include/file_handler.h"

int read_countries(const char *filename, Country *countries, int max_count) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        printf("Ошибка: не удалось открыть файл %s\n", filename);
        return -1;
    }
    
    char line[LINE_LENGTH];
    int count = 0;
    
    while (count < max_count && fgets(line, LINE_LENGTH, file) != NULL) {
        // Удаляем символ перевода строки
        line[strcspn(line, "\n")] = 0;
        
        // Пропускаем пустые строки и комментарии
        if (strlen(line) == 0 || line[0] == '#') {
            continue;
        }
        
        if (parse_country(line, &countries[count])) {
            count++;
        }
    }
    
    fclose(file);
    printf("Прочитано %d записей о странах из файла %s\n", count, filename);
    return count;
}

int write_results(const char *filename, Country *countries, int count) {
    FILE *file = fopen(filename, "w");
    if (file == NULL) {
        printf("Ошибка: не удалось создать файл %s\n", filename);
        return -1;
    }
    
    // Заголовок таблицы
    fprintf(file, "%-15s | %-12s | %-8s | %-14s | %-10s | %-12s | %-8s | %-25s | %-15s\n",
            "Страна", "Столица", "Материк", "Язык", "Население", "Площадь", "Валюта", "Строй", "Глава");
    fprintf(file, "--------------------------------------------------------------------------------------------------------------------------------------------------------------------\n");
    
    char buffer[LINE_LENGTH];
    for (int i = 0; i < count; i++) {
        country_to_string(&countries[i], buffer);
        fprintf(file, "%s\n", buffer);
    }
    
    fclose(file);
    printf("Записано %d записей в файл %s\n", count, filename);
    return 0;
}

void display_file(const char *filename) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        printf("Ошибка: не удалось открыть файл %s\n", filename);
        return;
    }
    
    printf("\n--- Содержимое файла %s ---\n", filename);
    char line[LINE_LENGTH];
    while (fgets(line, sizeof(line), file) != NULL) {
        printf("%s", line);
    }
    printf("--- Конец файла ---\n\n");
    
    fclose(file);
}

