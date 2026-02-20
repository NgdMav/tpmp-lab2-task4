/**
 * @file main.c
 * @brief Главный модуль программы для обработки данных о странах
 * @author Козлов Максим
 */
#include <stdio.h>
#include "country.h"
#include "../include/file_handler.h"

#define MAX_COUNTRIES 50

int main() {
    Country countries[MAX_COUNTRIES];
    Country filtered[MAX_COUNTRIES];
    
    printf("========================================\n");
    printf("ФИЛЬТРАЦИЯ ДАННЫХ О ГОСУДАРСТВАХ\n");
    printf("Вариант 25 (задача 'Государство')\n");
    printf("========================================\n\n");
    
    // Чтение данных из файла
    int total = read_countries("data/countries.txt", countries, MAX_COUNTRIES);
    if (total <= 0) {
        printf("Ошибка чтения входного файла или файл пуст.\n");
        return 1;
    }
    
    // Просмотр содержимого исходного файла
    display_file("data/countries.txt");
    
    // Фильтрация данных
    int filtered_count = 0;
    for (int i = 0; i < total; i++) {
        if (matches_criteria(&countries[i])) {
            filtered[filtered_count++] = countries[i];
        }
    }
    
    printf("\n--- РЕЗУЛЬТАТ ФИЛЬТРАЦИИ ---\n");
    printf("Всего записей: %d\n", total);
    printf("Стран Евразии с населением менее 20 млн: %d\n\n", filtered_count);
    
    // Вывод отфильтрованных данных на экран
    if (filtered_count > 0) {
        printf("%-20s | %-15s | %-8s | %-12s | %-10s | %-12s | %-10s | %-15s | %s\n",
               "Страна", "Столица", "Материк", "Язык", "Население", "Площадь", "Валюта", "Строй", "Глава");
        printf("--------------------------------------------------------------------------------------------------------------------------------------------------------------------\n");
        
        char buffer[512];
        for (int i = 0; i < filtered_count; i++) {
            country_to_string(&filtered[i], buffer);
            printf("%s\n", buffer);
        }
    } else {
        printf("Нет стран, удовлетворяющих условиям фильтрации.\n");
    }
    
    // Сохранение результатов в файл
    write_results("data/result.txt", filtered, filtered_count);
    
    printf("\n========================================\n");
    printf("Результаты сохранены в файл data/result.txt\n");
    printf("========================================\n");
    
    return 0;
}

