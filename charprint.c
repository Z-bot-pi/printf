#include "main.h"

/**
* print_char - Prints a char
* @dataTypes: List a of arguments
* @buff: Buffer array to handle print
* @flags: Calculates active flags
* @width: Width
* @bits: Precision specification
* @size: Size specifier
* Return: Number of chars printed
*/
int print_char(va_list dataTypes, char buff[],
int flags, int width, int bits, int size)
{
char c = va_arg(dataTypes, int);
return (w_handle_char(c, buff, flags, width, bits,
size));
}
