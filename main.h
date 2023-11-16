#ifndef MAIN_H
#define MAIN_H
#include <stdarg.h>
#include <limits.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define UNUSED(x) (void)(x)
#define BUFF_SIZE 1024

/**Flagging**/
#define F_SPACE 16
#define F_ZERO 4
#define F_HASH 8
#define F_MINUS 1
#define F_PLUS 2

/**sizes**/
#define S_LONG 2
#define S_SHORT 1

int hexag_print(va_list dataTypes, char map_t[], char buff[], int flags, char cha_flag, int width, int bits, int size);
int upper_hexa_print(va_list dataTypes, char buff[], int flags, int width, int bits, int size);
