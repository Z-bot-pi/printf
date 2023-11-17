#include "main.h"
void p_buff(char buffer[], int *buffer_in);
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
char buffer[BUFF_SIZE];
if (format == NULL)
return (-1);
va_start(list, format);
for (i = 0; format && format[i] != '\0'; i++)
{
if (format[i] != '%')
{
buffer[buff_in++] = format[i];
if (buff_in == BUFF_SIZE)
p_buff(buffer, &buff_in);
/* write(1, &format[i], 1);*/
printed_chars++;
}
else
{
p_buffer(buffer, &buff_in);
flags = fetch_flags(format, &i);
width = fetch_width(format, &i, list);
bits = fetch_bits(format, &i, list);
size = fetch_size(format, &i);
++i;
printed = h_print(format, &i, list, buffer,
flags, width, bits, size);
if (printed == -1)
return (-1);
printed_chars += printed;
}
}
p_buffer(buffer, &buff_in);
va_end(list);
return (printed_chars);
}
/**
* p_buffer - Prints the contents of the buffer if it exist
* @buff: Array of chars
* @buff_in: Index at which to add next char, represents the length.
*/
void p_buffer(char buff[], int *buff_in)
{
if (*buff_in > 0)
write(1, &buffer[0], *buff_in);
*buff_in = 0;
}
