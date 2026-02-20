/**
 * @file file_handler.h
 * @brief Заголовочный файл для работы с файлами
 * @author Козлов Максим
 */
#ifndef FILE_HANDLER_H
#define FILE_HANDLER_H

#include "country.h"

#define MAX_LINES 100
#define LINE_LENGTH 512

/**
 * @brief Читает данные о странах из файла
 * @param filename Имя входного файла
 * @param countries Массив структур Country
 * @param max_count Максимальное количество стран
 * @return Количество прочитанных стран или -1 при ошибке
 */
int read_countries(const char *filename, Country *countries, int max_count);

/**
 * @brief Записывает отфильтрованные данные в файл
 * @param filename Имя выходного файла
 * @param countries Массив структур Country
 * @param count Количество стран
 * @return 0 при успехе, -1 при ошибке
 */
int write_results(const char *filename, Country *countries, int count);

/**
 * @brief Выводит содержимое файла на экран
 * @param filename Имя файла
 */
void display_file(const char *filename);

#endif

