#include "main.h"
void p_buff(char buff[], int *buff_in);
/*
* _printf - Printf function
* @format: format.
* Return: Printed chars.
*/
int _printf(const char *format, ...)
{
int i, printed = 0, printed_chars = 0;
int flags, width, bits, size, buff_in = 0;
va_list list;
char buff[BUFF_SIZE];
if (format == NULL)
return (-1);
va_start(list, format);
for (i = 0; format && format[i] != '\0'; i++)
{
if (format[i] != '%')
{
buff[buff_in++] = format[i];
if (buff_in == BUFF_SIZE)
p_buff(buff, &buff_in);
/* write(1, &format[i], 1);*/
printed_chars++;
}
else
{
p_buff(buff, &buff_in);
flags = fetch_flags(format, &i);
width = fetch_width(format, &i, list);
bits = fetch_precision(format, &i, list);
size = fetch_size(format, &i);
++i;
printed = h_print(format, &i, list, buff,
flags, width, bits, size);
if (printed == -1)
return (-1);
printed_chars += printed;
}
}
p_buff(buff, &buff_in);
va_end(list);
return (printed_chars);
}
/**
* p_buffer - Prints the contents of the buffer if it exist
* @buff: Array of chars
* @buff_in: Index at which to add next char, represents the length.
*/
void print_buff(char buff[], int *buff_in)
{
if (*buff_in > 0)
write(1, &buff[0], *buff_in);
*buff_in = 0;
}
