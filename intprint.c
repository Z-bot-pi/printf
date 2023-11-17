#include "main.h"

/**
* p_int - Print int
* @dataTypes: Lista of arguments
* @buff: Buffer array to handle print
* @flags: Calculates active flags
* @width: get width.
* @bits: Precision specification
* @size: Size specifier
* Return: Number of chars printed
*/
int p_int(va_list dataTypes, char buff[],
int flags, int width, int bits, int size)
{
int i = BUFF_SIZE - 2;
int its_negative = 0;
long int n = va_arg(dataTypes, long int);
unsigned long int num;
n = cnvrt_s_number(n, size);
if (n == 0)
buff[i--] = '0';
buff[BUFF_SIZE - 1] = '\0';
num = (unsigned long int)n;
if (n < 0)
{
num = (unsigned long int)((-1) * n);
its_negative = 1;
}
while (num > 0)
{
buff[i--] = (num % 10) + '0';
num /= 10;
}
i++;
return (w_number(its_negative, i, buff, flags, width,
bits, size));
}

