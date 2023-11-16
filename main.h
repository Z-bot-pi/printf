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


/**
* struct frmt - Stru op
* @frmt: format.
* @fxn: The function associated.
*/
struct frmt
{
char frmt;
int (*fxn)(va_list, char[], int, int, int, int);
};

/**
* typedef struct frmt frmt_t - Struct op
* @frmt: The format.
* @fm_t: The function associated.
*/
typedef struct fmt frmt_t;
int _printf(const char *format, ...);
int handle_print(const char *frmt, int *i,
va_list list, char buff[], int flags, int width, int bits, int
size);

/** fxns **/

/** chars and strings **/
int p_char(va_list dataTypes, char buff[],
		int flags, int width, int bits, int size);
int p_string(va_list dataTypes, char buff[],
		int flags, int width, int bits, int size);
int p_percent(va_list dataTypes, char buff[],
		int flags, int width, int bits, int size);
int p_hexa(va_list dataTypes, char map_t[], char buff[],
		int flags, char cha_flag, int width, int bits, int size);
int p_upper_hexa(va_list dataTypes, char buff[],
	       	int flags, int width, int bits, int size);


/** numbers **/
int p_int(va_list dataTypes, char buff[],
		int flags, int width, int bit, int size);
int p_binary(va_list dataTypes, char buff[],
		int flags, int width, int bits, int size);
int p_unsigned(va_list dataTypes, char buff[],
		int flags, int width, int bits, int size);
int p_octal(va_list dataTypes, char buff[],
		int flags, int width, int bits, int size);
int p_hexadecimal(va_list dataTypes, char buff[],
		int flags, int width, int bits, int size);

/** Handling specifiers **/
int fetch_flags(const char *format, int *i);
int fetch_width(const char *format, int *i, va_list ls);
int fetch_bits(const char *format, int *i, va_list ls);
int fetch_size(const char *format, int *i);

/** memory address fxn **/
int memory_variable(va_list dataTypes, char buff[],
		int flags, int width, int bits, int size);

/** reversed string */
int reversed_string(va_list dataTypes, char buff[],
		int flags, int width, int bits, int size);

/** Not printable characters */
int not_printable(va_list dataTypes, char buff[],
		int flags, int width, int bits, int size);

/** rotation13_string **/
int rotation13_string(va_list dataTypes, char buff[],
		int flags, int width, int bits, int size);

/** Width **/
int number(int positive, int in, char buff[],
       int flags, int width, int bits, int size);

int num(int in, char bf[], int flags, int width, int bits,
		int length, char pa, char x_c);

int write_handle_char(char c, char buff[],
		int flags, int width, int bits, int size);

int unassigned(int negative, int in,char buff[],
		int flags, int width, int bits, int size);


/** Uti **/
int printable(char);
int app_hexa_code(char, char[], int);
int digit(char);
long int convrt_s_number(long int num, int size);
long int convrt_s_unsgnd(unsigned long int num, int size);
#endif /* MAIN_H */

