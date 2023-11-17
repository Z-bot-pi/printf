#include "main.h"

/* w_handle_char - Prints a string
* @c: char types.
* @buff: Buffer array to handle print
* @flags: Calculates active flags.
* @width: get width.
* @bits: precision specifier
* @size: Size specifier
*
* Return: Number of chars printed.
*/

int w_handle_char(char c, char buffer[],
int flags, int width, int bits, int size)
{ /* char is stored at left and paddind at buffer's right */
int in = 0;
char pa = ' ';
UNUSED(bits);
UNUSED(size);
if (flags & F_ZERO)
pa = '0';
buffer[i++] = c;
buffer[i] = '\0';

if (width > 1)
{
buffer[BUFF_SIZE - 1] = '\0';
for (in = 0; i < width - 1; i++)
buffer[BUFF_SIZE - i - 2] = pa;
if (flags & F_MINUS)
return (write(1, &buffer[0], 1) +
write(1, &buffer[BUFF_SIZE - i - 1], width -
1));
else
return (write(1, &buffer[BUFF_SIZE - i - 1], width - 1) +
write(1, &buffer[0], 1));
}
return (write(1, &buffer[0], 1));
}
/*******w_no. **********/
/**
* w_number - Prints a string
* @its_negative: Lista of arguments
* @ind: char types.
* @buff: Buffer array to handle print
* @flags: Calculates active flags
* @width: get width.
* @bits: precision specifier
* @size: Size specifier
*
* Return: Number of chars printed.
*/
int w_number(int its_negative, int in, char buffer[],
int flags, int width, int bits, int size)
{
int length = BUFF_SIZE - in - 1;
char pa = ' ', x_ch = 0;
UNUSED(size);
if ((flags & F_ZERO) && !(flags & F_MINUS))
pa = '0';
if (its_negative)
x_ch = '-';
else if (flags & F_PLUS)
x_ch = '+';
else if (flags & F_SPACE)

UNUSED(size);
if (bits == 0 && in == BUFF_SIZE - 2 && buffer[in] == '0')
return (0); /* printf(".0d", 0) no char is printed */
if (bits > 0 && bits < length)
pa = ' ';
while (bits > length)
{
buffer[--in] = '0';
length++;
}
if ((flags & F_ZERO) && !(flags & F_MINUS))
pa = '0';
if (width > length)
{
for (in = 0; i < width - length; i++)
buffer[i] = pa;
buffer[i] = '\0';
if (flags & F_MINUS) /* Asign extra char to left of buffer
[buffer>pa]*/
{
return (write(1, &buffer[in], length) + write(1,
&buffer[0], i));
}
else /* Asign extra char to left of padding [pa>buff]*/
{
return (write(1, &buffer[0], i) + write(1, &buffer[in],
length));
}
}
return (write(1, &buffer[in], length));
}
/**
* write_pointer - Write a memory address
* @buff: Arrays of chars
* @ind: Index at which the number starts in the buffer
* @length: Length of number
* @width: Wwidth specifier
* @flags: Flags specifier

* @pa: Char representing the padding
* @x_c: Char representing extra char
* @pa_start: Index at which padding should start
*
* Return: Number of written chars.
*/
int w_pointer(char buffer[], int in, int length,
int width, int flags, char pa, char x_c, int pa_start)
{
int i;
if (width > length)
{
for (i = 3; i < width - length + 3; i++)
buffer[i] = pa;
buffer[i] = '\0';
if (flags & F_MINUS && pa == ' ')/* Asign extra char to left
of buffer */
{
buffer[--in] = 'x';
buffer[--in] = '0';
if (x_c)
buffer[--in] = x_c;
return (write(1, &buffer[in], length) + write(1,
&buffer[3], i - 3));
}
else if (!(flags & F_MINUS) && pa == ' ')/* extra char to
left of buffer */
{
buffer[--in] = 'x';
buffer[--in] = '0';
if (x_c)
buffer[--in] = x_c;
return (write(1, &buffer[3], i - 3) + write(1,
&buffer[in], length));
}
else if (!(flags & F_MINUS) && pa == '0')/* extra char to
left of padd */
{
if (x_c)
buffer[--pa_start] = x_c;
buffer[1] = '0';
buffer[2] = 'x';
return (write(1, &buffer[pa_start], i - pa_start) +
write(1, &buffer[in], length - (1 - pa_start) -
2));

buffer[--in] = 'x';
buffer[--in] = '0';
if (x_c)
buffer[--in] = x_c;
return (write(1, &buffer[in], BUFF_SIZE - in - 1));
}
