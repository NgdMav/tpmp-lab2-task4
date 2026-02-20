/**
 * @file country.c
 * @brief Реализация функций для работы со структурой Country
 * @author Козлов Максим
 */
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "../include/country.h"

int parse_country(const char *line, Country *country) {
    char temp[512];
    strcpy(temp, line);
    
    // Формат строки:
    // Название;Столица;Материк;Язык;Население;Площадь;Валюта;Строй;Глава
    
    char *token = strtok(temp, ";");
    if (token == NULL) return 0;
    strcpy(country->name, token);
    
    token = strtok(NULL, ";");
    if (token == NULL) return 0;
    strcpy(country->capital, token);
    
    token = strtok(NULL, ";");
    if (token == NULL) return 0;
    strcpy(country->continent, token);
    
    token = strtok(NULL, ";");
    if (token == NULL) return 0;
    strcpy(country->language, token);
    
    token = strtok(NULL, ";");
    if (token == NULL) return 0;
    country->population = atoi(token);
    
    token = strtok(NULL, ";");
    if (token == NULL) return 0;
    country->area = atof(token);
    
    token = strtok(NULL, ";");
    if (token == NULL) return 0;
    strcpy(country->currency, token);
    
    token = strtok(NULL, ";");
    if (token == NULL) return 0;
    strcpy(country->government, token);
    
    token = strtok(NULL, ";");
    if (token == NULL) return 0;
    strcpy(country->head, token);
    
    return 1;
}

int matches_criteria(const Country *country) {
    // Проверка: материк Евразия и население меньше 20 млн (20000 тыс.)
    return (strcmp(country->continent, "Евразия") == 0 && 
            country->population < 20000);
}

void country_to_string(const Country *country, char *buffer) {
    sprintf(buffer, "%-20s | %-15s | %-8s | %-12s | %5d тыс. | %6.1f тыс.км² | %-10s | %-15s | %s",
            country->name,
            country->capital,
            country->continent,
            country->language,
            country->population,
            country->area,
            country->currency,
            country->government,
            country->head);
}

