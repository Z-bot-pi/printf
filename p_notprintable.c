#include "main.h"


/**
* not_printable - Prints ascii codes in hexa of non printable chars
* @dataTypes: Lista of arguments
* @buff: Buffer array to handle print
* @flags: Calculates active flags
* @width: get width
* @bits: Precision specification
* @size: Size specifier
* Return: Number of chars printed
*/
int not_printable(va_list dataTypes, char buff[],
int flags, int width, int bits, int size)
{
int i = 0, offset = 0;
char *str = va_arg(dataTypes, char *);
UNUSED(flags);
UNUSED(width);
UNUSED(bits);
UNUSED(size);
if (str == NULL)
return (write(1, "(null)", 6));
while (str[i] != '\0')
{
if (its_printable(str[i]))
buff[i + offset] = str[i];
else
offset += app_hexa_code(str[i], buff, i + offset);
i++;
}
buff[i + offset] = '\0';
return (write(1, buff, i + offset));
}
