#include "main.h"

/**
* p_binary - Prints an unsigned number
* @dataTypes: Lista of arguments
* @buff: Buffer array to handle print
* @flags: Calculates active flags
* @width: get width.
* @bits: Precision specification
* @size: Size specifier
* Return: Numbers of char printed.
*/
int p_binary(va_list types, char buffer[],
int flags, int width, int bits, int size)
{
unsigned int n, m, i, sum;
unsigned int a[32];
int count;
UNUSED(buffer);
UNUSED(flags);
UNUSED(width);
UNUSED(bits);
UNUSED(size);
n = va_arg(types, unsigned int);
m = 2147483648; /* (2 ^ 31) */
a[0] = n / m;
for (i = 1; i < 32; i++)
{
m /= 2;
a[i] = (n / m) % 2;
}
for (i = 0, sum = 0, count = 0; i < 32; i++)
{
sum += a[i];
if (sum || i == 31)
{
char z = '0' + a[i];
write(1, &z, 1);
count++;
}
}
return (count);
}
