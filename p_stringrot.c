#include "main.h"

/**
* p_rotation13_string - Print a string in rot13.
* @dataTypes: Lista of arguments
* @buff: Buffer array to handle print
* @flags: Calculates active flags
* @width: get width
* @bits: Precision specification
* @size: Size specifier
* Return: Numbers of chars printed
*/
int p_rotation13_string(va_list types, char buffer[],
int flags, int width, int bits, int size)
{
char x;
char *str;
unsigned int i, j;
int count = 0;
char in[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
char out[] = "NOPQRSTUVWXYZABCDEFGHIJKLMnopqrstuvwxyzabcdefghijklm";
str = va_arg(types, char *);
UNUSED(buffer);
UNUSED(flags);
UNUSED(width);
UNUSED(bits);
UNUSED(size);
if (str == NULL)
str = "(AHYY)";
for (i = 0; str[i]; i++)
{
for (j = 0; in[j]; j++)
{
if (in[j] == str[i])
{
x = out[j];
write(1, &x, 1);
count++;
break;
}
}
if (!in[j])
{
x = str[i];
write(1, &x, 1);
count++;
}
}
return (count);
}
