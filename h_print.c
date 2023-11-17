#include "main.h"
/**
* h_print - Prints an argument based on its type
* @fmt: Formatted string in which to print the arguments.
* @list: List of arguments to be printed.
* @ind: ind.
* @buff: Buffer array to handle print.
* @flags: Calculates active flags
* @width: get width.
* @bits: Precision specification
* @size: Size specifier
* Return: 1 or 2;
*/
int h_print(const char *fmt, int *in, va_list list, char buff[],
int flags, int width, int bits, int size)
{
int i, unknow_len = 0, p_chars = -1;
fmt_t fmt_types[] = {
{'c', p_char}, {'s', p_string}, {'%', p_percent},
{'i', p_int}, {'d', p_int}, {'b', p_binary},
{'u', p_unsigned}, {'o', p_octal}, {'x',
p_hexadecimal},
{'X', p_upper_hexa}, {'p', p_pointer}, {'S',
p_not_printable},
{'r', p_reverse}, {'R', p_rotation13_string}, {'\0', NULL}
};
for (i = 0; fmt_types[i].fmt != '\0'; i++)
if (fmt[*in] == fmt_types[i].fmt)
return (fmt_types[i].fn(list, buff, flags, width,
bits, size));
if (fmt_types[i].fmt == '\0')
{
if (fmt[*in] == '\0')
return (-1);
unknow_len += write(1, "%%", 1);
if (fmt[*in - 1] == ' ')
unknow_len += write(1, " ", 1);
else if (width)
{
--(*in);
while (fmt[*in] != ' ' && fmt[*in] != '%')
--(*in);
if (fmt[*in] == ' ')
--(*in);
return (1);
}
unknow_len += write(1, &fmt[*in], 1);
return (unknow_len);
}
return (p_chars);
}
