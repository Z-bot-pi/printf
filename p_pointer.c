#include "main.h"

/**
* p_pointer - Prints the value of a pointer variable
* @dataTypes: List a of arguments
* @buff: Buffer array to handle print
* @flags: Calculates active flags
* @width: get width
* @bits: Precision specification
* @size: Size specifier
* Return: Number of chars printed.
*/
int p_pointer(va_list dataTypes, char buff[],
int flags, int width, int precision, int size)
{
char x_c = 0, pa = ' ';
int in = BUFF_SIZE - 2, length = 2, pa_start = 1; /* length=2,
for '0x' */
unsigned long num_addrs;
char map_to[] = "0123456789abcdef";
void *addrs = va_arg(types, void *);
UNUSED(width);
UNUSED(size);
if (addrs == NULL)
return (write(1, "(nil)", 5));
buff[BUFF_SIZE - 1] = '\0';
UNUSED(bits);
num_addrs = (unsigned long)addrs;
while (num_addrs > 0)
{
buff[in--] = map_to[num_addrs % 16];
num_addrs /= 16;
length++;
}
if ((flags & F_ZERO) && !(flags & F_MINUS))
pa = '0';
if (flags & F_PLUS)
extra_c = '+', length++;
else if (flags & F_SPACE)
x_c = ' ', length++;
in++;
/*return (write(1, &buff[i], BUFF_SIZE - i - 1));*/
return (w_pointer(buff, in, length,
width, flags, pa, x_c, pa_start));
}
