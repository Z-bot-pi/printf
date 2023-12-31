#include "main.h"

/* p_unsigned - Prints an unsigned number
* @dataTypes: List a of arguments
* @buff: Buffer array to handle print
* @flags: Calculates active flags
* @width: get width
* @bits: Precision specification
* @size: Size specifier
* Return: Number of chars printed.
*/
int p_unsigned(va_list types, char buffer[],
int flags, int width, int bits, int size)
{
int i = BUFF_SIZE - 2;
unsigned long int num = va_arg(types, unsigned long int);
num = convrt_s_unsgnd(num, size);
if (num == 0)
buffer[i--] = '0';
buffer[BUFF_SIZE - 1] = '\0';
while (num > 0)
{
buffer[i--] = (num % 10) + '0';
num /= 10;
}
i++;
return (w_unsgnd(0, i, buffer, flags, width, bits, size));
}
