#ifndef FILE_UTILS_H
#define FILE_UTILS_H
#define _CRT_SECURE_NO_WARNINGS
#include <locale.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 1024

void file_rw(const char* filename, int mode);
void count_char(const char* filename, char target);
void reverse_substr(const char* filename, int start, int end);
void maintask(const char* filename);

#endif // FILE_UTILS_H
