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
int p_hexa_upper(va_list types, char buffer[],
int flags, int width, int bits, int size)
{
return (p_hexa(types, "0123456789ABCDEF", buffer,
flags, 'X', width, bits, size));
}
