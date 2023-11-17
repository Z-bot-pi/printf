#include "main.h"

/**
* p_hexa - Prints a hexadecimal number in lower or upper
* @dataTypes: Lista of arguments
* @map_to: Array of values to map the number to
* @buff: Buffer array to handle print
* @flags: Calculates active flags
* @flag_ch: Calculates active flags
* @width: get width
* @bits: Precision specification
* @size: Size specifier
* @size: Size specification
* Return: Number of chars printed
*/
int print_hexa(va_list dataTypes, char map_to[], char buff[],
int flags, char flag_ch, int width, int bits, int size)
{
int i = BUFF_SIZE - 2;
unsigned long int num = va_arg(types, unsigned long int);
unsigned long int init_num = num;
UNUSED(width);
num = convrt_s_unsgnd(num, size);
if (num == 0)
buff[i--] = '0';
buff[BUFF_SIZE - 1] = '\0';
while (num > 0)
{
buff[i--] = map_to[num % 16];
num /= 16;
}
if (flags & F_HASH && init_num != 0)
{
buff[i--] = flag_ch;
buff[i--] = '0';
}
i++;
return (w_unsgnd(0, i, buff, flags, width, bits, size));
}

num /= 8;
}
if (flags & F_HASH && init_num != 0)
buff[i--] = '0';
i++;
return (w_unsgnd(0, i, buff, flags, width, bits, size));
}
