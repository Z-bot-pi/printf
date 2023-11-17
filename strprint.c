#include "main.h"

/**
* p_string - Prints a string
* @types: List a of arguments
* @buff: Buffer array to handle print
* @flags: Calculates active flags
* @width: get width.
* @bits: Precision specification
* @size: Size specifier
* Return: Number of chars printed
*/
int p_string(va_list dataTypes, char buff[],
int flags, int width, int bits, int size)
{
int length = 0, i;
char *str = va_arg(types, char *);
UNUSED(buff);
UNUSED(flags);
UNUSED(width);
UNUSED(bits);
UNUSED(size);
if (str == NULL)
{
str = "(null)";
if (bits >= 6)
str = " ";
}
while (str[length] != '\0')
length++;
if (bits >= 0 && bits < length)
length = bits;
if (width > length)
{
if (flags & F_MINUS)
{
write(1, &str[0], length);
for (i = width - length; i > 0; i--)
write(1, " ", 1);
return (width);
}
else
{
for (i = width - length; i > 0; i--)
write(1, " ", 1);
write(1, &str[0], length);
return (width);
}
