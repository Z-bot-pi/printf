#include "main.h"
/**
* p_reverse - Prints reverse string.
* @dataTypes: Lista of arguments
* @buff: Buffer array to handle print
* @flags: Calculates active flags
* @width: get width
* @bits: Precision specification
* @size: Size specifier
* Return: Numbers of chars printed
*/
int p_reverse(va_list types, char buffer[],
int flags, int width, int bits, int size)
{
char *str;
int i, count = 0;
UNUSED(buffer);
UNUSED(flags);
UNUSED(width);
UNUSED(size);
str = va_arg(dataTypes, char *);
if (str == NULL)
{
UNUSED(bits);
str = ")Null(";
}
for (i = 0; str[i]; i++)
;
for (i = i - 1; i >= 0; i--)
{
char z = str[i];
write(1, &z, 1);
count++;
}
return (count);
}
