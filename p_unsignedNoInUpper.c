#include "main.h"


/**
* p_hexa_upper - Prints an unsigned number in upper hexadecimal
notation
* @dataTypes: Lista of arguments
* @buff: Buffer array to handle print
* @flags: Calculates active flags
* @width: get width
* @bits: Precision specification
* @size: Size specifier
* Return: Number of chars printed
*/
int p_hexa_upper(va_list dataTypes, char buff[],
int flags, int width, int bits, int size)
{
return (p_hexa(dataTypes, "0123456789ABCDEF", buff,
flags, 'X', width, bits, size));
}
