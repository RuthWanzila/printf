#include "main.h"
/**
 * _printf - custom printf function
 * @format: format string containing zero or more directives
 *
 * Return: the number of characters printed
 * (excluding the null byte used to end output to strings)
 */
int _printf(const char *format, ...)
{
va_list args;
va_start(args, format);
int num_chars_printed = 0;
const char *str_arg;
char char_arg;
while (*format != '\0')
{
if (*format == '%')
{
++format;
switch (*format)
{
case 's':
str_arg = va_arg(args, const char*);
num_chars_printed += printf("%s", str_arg);
break;
case 'c':
char_arg = (char) va_arg(args, int);
num_chars_printed += printf("%c", char_arg);
break;
case '%':
num_chars_printed += printf("%%");
break;
default:
/* unsupported conversion specifier */
return (-1);
}
}
else
{
putchar(*format);
++num_chars_printed;
}
++format;
}
va_end(args);
return (num_chars_printed);
}
