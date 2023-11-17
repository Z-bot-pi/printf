#include "main.h"

/* p_octal - Prints an unsigned number in octal notation
* @dataTypes: Lista of arguments
* @buff: Buffer array to handle print
* @flags: Calculates active flags
* @width: get width
* @bits: Precision specification
* @size: Size specifier
* Return: Number of chars printed
*/
int p_octal(va_list dataTypes, char buff[],
int flags, int width, int bits, int size)
{
int i = BUFF_SIZE - 2;
unsigned long int num = va_arg(types, unsigned long int);
unsigned long int init_num = num;
UNUSED(width);
num = convert_size_unsgnd(num, size);
if (num == 0)
buff[i--] = '0';
buff[BUFF_SIZE - 1] = '\0';
while (num > 0)
{
buff[i--] = (num % 8) + '0';
}
}
