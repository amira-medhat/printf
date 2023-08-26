#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <string.h>
#include <unistd.h>

int _printf(const char *format, ...);

void _write_char(char c, int *char_counter);

void _write_str(char *str, int *char_counter);

void _write_int(int num, int *char_counter);

#endif /* MAIN_H */
