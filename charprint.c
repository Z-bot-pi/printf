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
int print_char(va_list types, char buffer[],
int flags, int width, int bits, int size)
{
char c = va_arg(types, int);
return (w_pointer(c, buffer, flags, width, bits,
size));
}
