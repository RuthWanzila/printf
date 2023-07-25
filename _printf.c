#include "main.h"
#include <stdarg.h>
#include <unistd.h>

/**
 * _printf - prints a formatted string to the standard output stream
 * @format: format string
 *
 * Return: the number of characters printed (excluding the null byte used to
 * end output to strings)
 */
int _printf(const char *format, ...)
{
va_list args;
int count;
count = 0;
va_start(args, format);
while (*format)
{
if (*format == '%')
{
format++;
if (*format == 'c')
{
char c = va_arg(args, int);
count += write(1, &c, 1);
}
else if (*format == 's')
{
char *s = va_arg(args, char *);
if (s == NULL)
s = "(null)";
count += write(1, s, _strlen(s));
}
else if (*format == '%')
{
count += write(1, "%", 1);
}
else
{
count += write(1, "%", 1);
if (*format)
count += write(1, format, 1);
}
}
else
{
count += write(1, format, 1);
}
format++;
}
va_end(args);
return (count);
}

/**
 * _strlen - returns the length of a string
 * @s: string
 *
 * Return: length of s
 */
int _strlen(char *s)
{
int len;
len = 0;
while (*s)
{
len++;
s++;
}
return (len);
}
