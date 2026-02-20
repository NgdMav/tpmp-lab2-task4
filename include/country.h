/**
 * @file country.h
 * @brief Заголовочный файл для работы со структурой Country
 * @author Козлов Максим
 */
#ifndef COUNTRY_H
#define COUNTRY_H

#define MAX_NAME_LEN 50
#define MAX_STRING_LEN 100

/**
 * @struct Country
 * @brief Структура для хранения данных о государстве
 */
typedef struct {
    char name[MAX_NAME_LEN];           // название страны
    char capital[MAX_NAME_LEN];         // столица
    char continent[MAX_NAME_LEN];       // материк
    char language[MAX_NAME_LEN];        // государственный язык
    int population;                      // население (в тысячах)
    float area;                          // площадь территории (тыс. км²)
    char currency[MAX_NAME_LEN];         // денежная единица
    char government[MAX_STRING_LEN];     // государственный строй
    char head[MAX_NAME_LEN];             // глава государства
} Country;

/**
 * @brief Парсит строку из файла в структуру Country
 * @param line Строка из файла
 * @param country Указатель на структуру для заполнения
 * @return 1 при успехе, 0 при ошибке
 */
int parse_country(const char *line, Country *country);

/**
 * @brief Проверяет, подходит ли страна под условия фильтрации
 * @param country Указатель на структуру Country
 * @return 1 если подходит (Евразия и население < 20 млн), иначе 0
 */
int matches_criteria(const Country *country);

/**
 * @brief Преобразует структуру Country в строку для вывода
 * @param country Указатель на структуру Country
 * @param buffer Буфер для строки
 */
void country_to_string(const Country *country, char *buffer);

#endif
