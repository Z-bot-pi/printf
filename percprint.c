#include "main.h"

/**
* p_percent - Prints a percent sign
* @types: Lista of arguments
* @buffer: Buffer array to handle print
* @flags: Calculates active flags
* @width: get width.
* @precision: Precision specification
* @size: Size specifier
* Return: Number of chars printed
*/
int p_percent(va_list types, char buff[],
int flags, int width, int bits, int size)
{
UNUSED(dataTypes);
UNUSED(buff);
UNUSED(flags);
UNUSED(width);
UNUSED(bits);
UNUSED(size);
return (write(1, "%%", 1));
}

